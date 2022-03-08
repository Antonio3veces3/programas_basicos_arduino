float lecturaSensor;
float celsius;
float farenheit;
float kelvin;
void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  lecturaSensor= analogRead(A0);
  celsius = (lecturaSensor * (500.0 / 1024.0));
 
  Serial.print("Grados Celsius: ");
  Serial.println(celsius);
  farenheit = ((celsius * 1.8) + 32);
  Serial.print("\nGrados Farenheit: ");
  Serial.print(farenheit);

  kelvin = celsius + 273.15;
  Serial.print("\nGrados Kelvin: ");
  Serial.print(kelvin);
  delay(120000);
}
