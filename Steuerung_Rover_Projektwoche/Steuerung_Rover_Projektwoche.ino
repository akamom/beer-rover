// Konstanten----------------------------------------------------------------------
const int TasterLadung = 7;
const int WarnLED = 2;
const int HalteLED = 4;

const int motor1_A=11;
const int motor1_B=10;
const int motor1_Speed=9;
 
const int motor2_A=6;
const int motor2_B=5;
const int motor2_Speed=3;

// Variablen------------------------------------------------------------------------
bool beladungsStatus = 0;
bool fahrStatus = 0;
bool statusMeldung = 0; 
double x = 0, y = 0; // Kordianten für Fahrauftrag


// Setup für den Loop----------------------------------------------------------------
void setup() 
{
  // OUTPUT
  pinMode(WarnLED, OUTPUT); // LEDs
  pinMode(HalteLED, OUTPUT);
  pinMode(motor1_A,OUTPUT); // Motorsteuerung
  pinMode(motor1_B,OUTPUT);
  pinMode(motor2_A,OUTPUT);
  pinMode(motor2_B,OUTPUT);

  // INPUT
  pinMode(TasterLadung, INPUT);

  // REST 
  Serial.begin (9600);

  // RESET
  digitalWrite(WarnLED, LOW);
  digitalWrite(HalteLED, LOW);
}


// LOOP --------------------------------------------------------------------------------
void loop() 
{
  beladungsStatus = digitalRead(TasterLadung);  
  // Warenannahme
  // Fahren
  // Warenabgabe
  // Warten
}

// Funktionen --------------------------------------------------------------------------
void motor1_drehen (int drehGrad, int motorSpeed, char richtung)
{
  if ( richtung == 'r')
  {
    for (int i=0; i<drehGrad; i+=5)
    {
      digitalWrite(motor1_A,HIGH); // A = HIGH and B = LOW means the motor will turn right
      digitalWrite(motor1_B,LOW);
      analogWrite(motor1_Speed,motorSpeed); // speed counts from 0 to 255
      delay(20);
    }
  } 
  else if ( richtung == 'l')
  {
    for (int i=0; i<drehGrad; i+=5)
    {
      digitalWrite(motor1_A,LOW); // A = LOW and B = HIGH means the motor will turn left
      digitalWrite(motor1_B,HIGH);
      analogWrite(motor1_Speed,motorSpeed); // speed counts from 0 to 255
      delay(20);
    }
  }
}

void motor2_drehen (int drehGrad, int motorSpeed, char richtung)
{
  if ( richtung == 'r')
  {
    for (int i=0; i<drehGrad; i+=5)
    {
      digitalWrite(motor2_A,HIGH); // A = HIGH and B = LOW means the motor will turn right
      digitalWrite(motor2_B,LOW);
      analogWrite(motor2_Speed,motorSpeed); // speed counts from 0 to 255
      delay(20);
    }
  } 
  else if ( richtung == 'l')
  {
    for (int i=0; i<drehGrad; i+=5)
    {
      digitalWrite(motor2_A,LOW); // A = LOW and B = HIGH means the motor will turn left
      digitalWrite(motor2_B,HIGH);
      analogWrite(motor2_Speed,motorSpeed); // speed counts from 0 to 255
      delay(20);
    }
  }
}

void motor1_stoppen()
{
   digitalWrite(motor1_A,LOW);
   digitalWrite(motor1_B,LOW);
}

void motor2_stoppen()
{
   digitalWrite(motor2_A,LOW);
   digitalWrite(motor2_B,LOW);
}

