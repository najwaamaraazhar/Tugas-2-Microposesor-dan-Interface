#define pinPotensiometer 0
float volt;
int potensiometer;
int pin = A0;
int nilaipot;
void setup() {
  Serial.begin(9600);   

}

void loop() {
  nilaipot = analogRead(pin);
  volt = nilaipot * (5.0 / 1023.0);

  Serial.print(volt);
  Serial.print("v");
  Serial.println();
  delay(300);

}
