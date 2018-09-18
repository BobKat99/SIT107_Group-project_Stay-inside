#define ADULT 7
#define IN 6
#define OUT 5

bool exiting_or_not()
{
  if (digitalRead(OUT))return true;
  else if (digitalRead(IN)) return false;
}

bool children_or_not()
{
  if (digitalRead(IN) and digitalRead(ADULT))return true;
  else if (digitalRead(IN) or digitalRead(OUT)and not digitalRead(ADULT)) return false;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(OUT, INPUT);
  pinMode(IN, INPUT);
  pinMode(ADULT, INPUT);
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
