#define A_IN 6
#define A_OUT 5
#define C_IN 4
#define C_OUT 7 

bool exiting_or_not()
{
  if (digitalRead(C_OUT) == LOW) return true;
  if (digitalRead(C_IN)== LOW) return false;
}

bool children_or_not()
{
  if (digitalRead(C_IN)== LOW or digitalRead(C_OUT)== LOW)return true;
  if ((digitalRead(A_IN)==LOW and digitalRead(C_IN)== LOW)or (digitalRead(C_OUT)== LOW and digitalRead(A_OUT)==LOW)) return false;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(A_IN, INPUT);
  pinMode(C_IN, INPUT);
  pinMode(A_OUT, INPUT);
  pinMode(C_OUT, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, LOW);

  bool exiting, children;
  exiting = exiting_or_not();
  children = children_or_not();

  if (children and exiting)
  {
    digitalWrite(13, HIGH);
  }

  else digitalWrite(13, LOW);
  delay(1000);
}
