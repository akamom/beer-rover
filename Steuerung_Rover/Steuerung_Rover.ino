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
  
  motor_drehen('1', 'r', 100);
  motor_drehen('2', 'l', 100);
  delay(1000);
  
  motor_drehen('1', 'r', 255);
  motor_drehen('2', 'r', 255);
  delay(1000);
  
  // Warenabgabe
  // Warten
}

// Funktionen --------------------------------------------------------------------------


void motor_drehen (char motor, char richtung, int newMotorSpeed)
{
// Mit Hilfe der Funktion kann sowohl Motor1 als auch Motor2 angesteuert werden
// Dabe wird die aktuelle Geschwindikeit bestimmt und diese langsam vergrößert oder verkleindert bis die gewünschte Geschwindigkeit erreicht ist
// char motor = '1' -> Für Motor 1
// char motor = '2' -> Für Motor 2
// char richtung = 'r' -> Der Motor dreht rechts herum
// char richtung = 'l' -> Der Motor dreht links herum
// int newMotorSpeed = 0 - 255 -> Die neue Geschwindigkeit kann einen Wert zwischen 0 und 255 annehmen 

  int motor_A, motor_B, motor_Speed; // Hier wird überprüft ob motor1 oder motor2 angesteuert werden soll
  if ( motor == '1')
  {
    motor_A = motor1_A;
    motor_B = motor1_B;
    motor_Speed = motor1_Speed;
  }
  if (motor == '2')
  {
    motor_A = motor2_A;
    motor_B = motor2_B;
    motor_Speed = motor2_Speed;
  }

  int currentSpeed = analogRead(motor_Speed); // Ermittelt die aktuelle Geschwindigkeit
  int deltaSpeed = currentSpeed - newMotorSpeed;
  
  if (richtung == 'r') // Der Motor dreht rechts herum
  {
    if (deltaSpeed <= 0) // Wenn die neue Geschwindigkeit größer der aktuellen Geschwindigkeit ist
    {
      for (int i = currentSpeed; i < newMotorSpeed; i+=5) // Schleife um die Geschwindigkeit Schrittweise zu ändern
      {
        digitalWrite(motor_A,HIGH); // A = HIGH and B = LOW means the motor will turn right
        digitalWrite(motor_B,LOW);
        analogWrite(motor_Speed, i); // speed counts from 0 to 255
        delay(20);
      }
    }
    else // Wenn die neue Geschwindigkeit kleiner der aktuellen Geschwindigkeit ist
    {
      for (int i = currentSpeed; i > newMotorSpeed; i-=5) // Schleife um die Geschwindigkeit Schrittweise zu ändern
      {
        digitalWrite(motor_A,HIGH); // A = HIGH and B = LOW means the motor will turn right
        digitalWrite(motor_B,LOW);
        analogWrite(motor_Speed, i); // speed counts from 0 to 255
        delay(20);
      }
    }
  }
   
  else if ( richtung == 'l') // Der Motor dreht links herum
  {
    if (deltaSpeed <= 0) // Wenn die neue Geschwindigkeit größer der aktuellen Geschwindigkeit ist
    {
      for (int i = currentSpeed; i < newMotorSpeed; i+=5)
      {
        digitalWrite(motor_A,LOW); // A = LOW and B = HIGH means the motor will turn left
        digitalWrite(motor_B,HIGH);
        analogWrite(motor_Speed, i); // speed counts from 0 to 255
        delay(20);
      }
    } 
    else // Wenn die neue Geschwindigkeit kleiner der aktuellen Geschwindigkeit ist
    {
      for (int i = currentSpeed; i > newMotorSpeed; i-=5)
      {
        digitalWrite(motor_A,LOW); // A = LOW and B = HIGH means the motor will turn left
        digitalWrite(motor_B,HIGH);
        analogWrite(motor_Speed, i); // speed counts from 0 to 255
        delay(20);
      }
    }
  }
}

void motor_stoppen(char motor)
{
// Die Funktion stoppt entweder Motor 1 oder Motor 2
// char motor = '1' -> Für Motor 1
// char motor = '2' -> Für Motor 2
  if (motor == '1')
  {
    digitalWrite(motor1_A,LOW);
    digitalWrite(motor1_B,LOW);
    analogWrite(motor1_Speed, 0);
  }
  else if (motor == '2')
  {
    digitalWrite(motor2_A,LOW);
    digitalWrite(motor2_B,LOW);
    analogWrite(motor2_Speed, 0);
  }
}
