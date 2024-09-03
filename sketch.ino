#include <Adafruit_NeoPixel.h>
#define PIN_TRIG 11
#define PIN_ECHO 12

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16, 5, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial1.begin(115200);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(10, INPUT);
  pixels.begin();
  pixels.setBrightness(100); // 100/255 brightness (about 40%)
  pixels.show();  
}

uint32_t red = pixels.Color(255, 115, 115); //red
  uint32_t orange = pixels.Color(255, 175, 115); //orange
  uint32_t yellow = pixels.Color(255, 255, 115); //yellow
  uint32_t green = pixels.Color(115, 255, 115);//green
  uint32_t dkgreen = pixels.Color(115, 155, 115);//dark green
  uint32_t cyan = pixels.Color(115, 255, 255); //cyan
  uint32_t blue = pixels.Color(115, 115, 255); //blue
  uint32_t magenta = pixels.Color(255, 150, 255); //magenta
  uint32_t purple = pixels.Color(155, 110, 190); //purple

void loop() {
  // Start a new measurement:
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  // Read the result:
  int dis = analogRead(10);
  int duration = pulseIn(PIN_ECHO, HIGH)/58;
  //CM /58, IN /148
  int val = 200-abs(dis-duration);
  if (val>200){
    val = 200;
  }

  //doesnt work in actual neopixel for some reason, but should theoretically work
  int g = 255;
  int r = 255;
  if (val <100){
    g = round(val/100*255);
  } 
  if (val >100){
    r = round(255-(val-100)/100*255);
  }
  pixels.setPixelColor(0, pixels.Color(r, g, 0));
  Serial1.println(r);
  Serial1.println(g);
  pixels.show();
  delay(1000);
}
