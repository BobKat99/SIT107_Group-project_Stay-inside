#define A_IN 7
#define A_OUT 6
#define C_IN 5
#define C_OUT 4 //PIR motion sensor

bool exiting_or_not()
{
  if (digitalRead(C_OUT) == HIGH) return true;
  else if (digitalRead(C_IN)) return false;
}

bool children_or_not()
{
  if ()digitalRead(C_IN) or digitalRead(C_OUT)== HIGH) and not (digitalRead(A_IN)or digitalRead(A_OUT))return true;
  else if (digitalRead(A_IN)or digitalRead(A_OUT)) return false;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(A_IN, INPUT);
  pinMode(C_IN, INPUT);
  pinMode(A_OUT, INPUT);
  pinMode(C_OUT, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, LOW);

  bool exiting, children;
  exiting = exiting_or_not();
  children = children_or_not();

  if (children and exiting)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(5000);
  }
  delay(3000);
}
