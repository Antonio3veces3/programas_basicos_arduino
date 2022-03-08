int periodo = 100;
unsigned long timeActual = 0;
float vector[500];
uint64_t count = 0;
float lecturaSensor;
void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  if (millis() > timeActual + periodo){
    timeActual = millis();
    lecturaSensor = analogRead(0);
    vector[count] = (( lecturaSensor * (500.0 / 1024.0)));
    if(count == 499){
      float suma;
      for(uint64_t i = 0; i<500; i++){
        suma += vector[i];
      }
      Serial.println("Han transcurrido 50 segundos");
      Serial.print("Promedio de 500 temperaturas tomadas: ");
      Serial.println(suma/500);
      count = 0;
    }
    count++;
  }
}
