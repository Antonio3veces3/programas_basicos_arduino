String action;
void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("INSTRUCCIONES");
  Serial.println("------------------");
  Serial.println("encender");
  Serial.println("apagar");
}

void loop() {
  while(Serial.available()>0){
    action = Serial.readStringUntil('\n');
    if(action == "encender"){
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("ON\n");
    }
    if(action == "apagar"){
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("OFF\n");
    }
    Serial.println("INSTRUCCIONES");
    Serial.println("------------------");
    Serial.println("encender");
    Serial.println("apagar");
  }

}
