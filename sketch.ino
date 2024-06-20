#define PIN_TRIG 21
#define PIN_ECHO 20

void setup() {
  Serial1.begin(115200);
  while (!Serial1) {
    delay(10); // wait for serial port to connect. Needed for native USB
  }
  // Now you can safely print message:
  Serial1.println("Hello, Serial Monitor!");
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(26, INPUT);
}

void loop() {
  // Start a new measurement:
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  // Read the result:
  int value = analogRead(26);
  Serial1.println(value);
  int duration = pulseIn(PIN_ECHO, HIGH);
  Serial1.print("Distance in CM: ");
  Serial1.println(duration / 58);
  Serial1.print("Distance in inches: ");
  Serial1.println(duration / 148);

  delay(1000);
}