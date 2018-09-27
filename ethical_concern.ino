//Code to collect data

#define A_IN 4
#define A_OUT 5
#define C_IN 6
#define C_OUT 7 
#define DOOR 8

bool exiting()
{
  if (digitalRead(C_OUT) == LOW) return true;
  else return false;
}

bool entering()
{
   if (digitalRead(C_IN)== LOW)return true;
   else return false;
}

bool children()
{
  if ((digitalRead(C_IN)== LOW or digitalRead(C_OUT)== LOW) and (digitalRead (A_IN)== HIGH and digitalRead(A_OUT)==HIGH))return true;
  else return false;
}

bool adult()
{
  if (digitalRead(A_IN)==LOW or digitalRead(A_OUT)== LOW and (digitalRead(C_IN)== LOW or digitalRead(C_OUT)== LOW)) return true;
  else return false;
}

bool door_opened()
{
  if (digitalRead(DOOR) == LOW ) return true;
  else return false;  
}

void setup() {
  // put your setup code here, to run once:
  pinMode(A_IN, INPUT);
  pinMode(C_IN, INPUT);
  pinMode(A_OUT, INPUT);
  pinMode(C_OUT, INPUT);
  pinMode(DOOR, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin (9600);
}

void loop() {
  digitalWrite(13, LOW)
  
  if (children() and exiting())
  {
    Serial.println("Children exiting");
    digitalWrite(13, LOW)
    delay(2000); 
  }

  else if (children() and entering())
  {
    Serial.println("Children playing");  
    digitalWrite(13, LOW)
    delay(2000); 
  }

  else if (adult()and exiting())
  {
    Serial.println("Adult exiting"); 
    digitalWrite(13, LOW) 
    delay(2000); 
  }

  else if (adult() and entering())
  {
    Serial.println("Adult entering");  
    digitalWrite(13, LOW)
    delay(2000); 
  }

  else if (children() and exiting() and door_opened())
  {
    Serial.println("Children exiting");
    digitalWrite(13, HIGH);
    delay(2000); 
  }
  
  else
  {
    Serial.println("Nothing"); 
    digitalWrite(13, LOW)
  }
  
  delay(1000);
}
