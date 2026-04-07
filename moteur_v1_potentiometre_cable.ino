int pval1 = 0;
int pval2 = 0;
int in1;
int in2;
int ena;
int in3; //mettre ici pin du controleur
int in4;
int enb;

void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

}

void tourner(int in1,int in2,int en,int pval){
  int vitesse;
  if (pval<500){ //arriere
    vitesse = map(pval, 0, 520, 255, 0);
    vitesse = constrain(vitesse, 0, 255);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(en, vitesse);
  } else if (pval>520){
    vitesse = map(pval, 520, 1023, 50, 255);
    vitesse = constrain(vitesse, 0, 255);
    digitalWrite(in2, LOW);
    digitalWrite(in1, HIGH);
    analogWrite(en, vitesse);
  }
  else{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(en, 0);}
  }

void loop() {
  pval1 = analogRead(A0);
  pval2 = analogRead(A1);

  tourner(in1, in2, ena, pval1); //moteur gauche
  tourner(in3, in4, enb, pval2); //moteur droit

  Serial.print("gauche: ");
  Serial.println(pval1);
  Serial.print("droite: ");
  Serial.println(pval2);
  delay(10);
}
