const int in1 = 5;
const int in2 = 4;
const int ena = 3;
const int in3 = 2;
const int in4 = 7;
const int enb = 6;

unsigned long startTimeGauche = 0;
unsigned long startTimeDroit = 0;
const int dureeMarche = 1500; // attend au moins 1.5s avant de changer l'état du moteur

bool moteurGaucheActif = false;
bool moteurDroitActif = false;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enb, OUTPUT);
  Serial.begin(9600);
}

void Avancer(int in1, int in2, int en, int vitesse) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(en, vitesse);
}

void Reculer(int in1, int in2, int en, int vitesse) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(en, vitesse);
}

void Stop(int in1, int in2, int en) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(en, 0);
}

void Gestion(bool &moteurActif, int pval, unsigned long &startTime, int &vitesse, const char* moteur, int in1, int in2, int en, unsigned long currentTime){
  if (!moteurActif && (pval < 480 || pval > 540)) {
    moteurActif = true;
    startTime = currentTime;

    if (pval < 480) {
      vitesse = map(pval, 0, 480, 255, 0);
      vitesse = constrain(vitesse, 0, 255);
      Reculer(in1, in2, en, vitesse);
      Serial.print(moteur);
      Serial.println(" Reculer");
    } else {
      vitesse = map(pval, 540, 1023, 0, 255);
      vitesse = constrain(vitesse, 0, 255);
      Avancer(in1, in2, en, vitesse);
      Serial.print(moteur);
      Serial.println(" Avancer");
    }
  }

  if (moteurActif && currentTime - startTime >= dureeMarche) {
    Stop(in1, in2, en);
    moteurActif = false;
    Serial.print(moteur);
    Serial.println(" Stop");
  }
}


void loop() {
  int vitesse1 = 0;
  int vitesse2 = 0;
  int pval1 = analogRead(A0); // Gauche
  int pval2 = analogRead(A1); // Droite
  unsigned long currentTime = millis();

  Gestion(moteurGaucheActif, pval1, startTimeGauche, vitesse1, "Gauche", in1, in2, ena, currentTime);
  Gestion(moteurDroitActif, pval2, startTimeDroit, vitesse2, "Droit", in3, in4, enb, currentTime);


  delay(20); // léger delay pour stabiliser la lecture
}
