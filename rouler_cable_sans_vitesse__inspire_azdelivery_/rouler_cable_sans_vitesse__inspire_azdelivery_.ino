const int in1=5;
const int in2=4 ; 
const int ena=3 ;
int pval1;
int pval2;
const int in3 = 2;
const int in4 = 7;
const int enb = 6;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ena, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  Serial.begin(9600);

}

void Avancer(int in1, int in2, int en){
  analogWrite(en, 255);
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);
  Serial.print("255");
  Serial.println(" avancer");
  }

void Reculer(int in1, int in2, int en){
  analogWrite(en, 255);
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  Serial.print("255");
  Serial.println(" reculer");
  }

void Stop(int in1, int in2, int en){
  analogWrite(en, 0);
  digitalWrite(in2, LOW);
  digitalWrite(in1, LOW);
  Serial.print("0");
  Serial.println(" STOP!");
  }

void Rouler(int i1, int i2, int pval, int en){
  if (pval<480){
    Reculer(i1, i2, en);
    delay(200);
    Stop(i1, i2, en);
    }
  else if (pval>540){
  Avancer(i1, i2, en);
  delay(200);
  Stop(i1, i2, en);
  }
  else{
    Stop(i1, i2, en);
    delay(200);
    }
  }

void loop() {
  pval1 = analogRead(A0);
  Serial.print("pval 1: ");
  Serial.println(pval1);
  
  pval2 = analogRead(A1);
  Serial.print("pval 2: ");
  Serial.println(pval2);

  Rouler(in1, in2, pval1, ena); //moteur 1
  Rouler(in3, in4, pval2, enb); //moteur 2
  
}
