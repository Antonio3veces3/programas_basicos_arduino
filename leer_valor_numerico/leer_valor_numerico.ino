
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Ingresa un valor numerico positivo");

}

void loop() {
  while(Serial.available() > 0){
    int numero = Serial.parseInt();
    if(numero !=0 ){
      for(int i = 1; i <= numero; i++){
        Serial.println(i);
      }
      Serial.println("\nIngresa un valor numerico positivo");
    }
  }
}
