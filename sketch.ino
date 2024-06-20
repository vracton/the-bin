#include <Adafruit_NeoPixel.h>
#define PIN_TRIG 21
#define PIN_ECHO 20

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16, 5, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial1.begin(115200);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(26, INPUT);
  pixels.begin();
  pixels.setBrightness(100); // 100/255 brightness (about 40%)
  pixels.show();  
}

uint32_t red = pixels.Color(255, 0, 0); //red
  uint32_t orange = pixels.Color(255, 100, 10); //orange
  uint32_t yellow = pixels.Color(255, 255, 0); //yellow
  uint32_t green = pixels.Color(0, 255, 0);//green
  uint32_t dkgreen = pixels.Color(0, 115, 0);//dark green
  uint32_t cyan = pixels.Color(0, 255, 255); //cyan
  uint32_t blue = pixels.Color(0, 0, 255); //blue
  uint32_t magenta = pixels.Color(255, 0, 255); //magenta
  uint32_t purple = pixels.Color(50, 0, 50); //purple

void loop() {
  // Start a new measurement:
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  // Read the result:
  int value = analogRead(26);
  int duration = pulseIn(PIN_ECHO, HIGH);
  //CM /58, IN /148 

  pixels.setPixelColor(0, red);
  pixels.show();
  delay(1000);
}
