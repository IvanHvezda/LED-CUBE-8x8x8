#define SPEAKER_PIN 1

void setup() {
  Serial.begin(115200);
  ledcAttach(SPEAKER_PIN, 1000, 8);  // pin, frekvence, rozlišení — nová, zjednodušená funkce
  Serial.println("Pripraveno - mel bys slyset pipani kazdou sekundu");
}

void loop() {
  ledcWrite(SPEAKER_PIN, 128);  // teď se píše přímo pin, ne číslo kanálu
  delay(500);
  ledcWrite(SPEAKER_PIN, 0);
  delay(500);
}