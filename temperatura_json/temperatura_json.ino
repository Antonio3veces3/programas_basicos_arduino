#include <ArduinoJson.h>

int periodo = 499;
unsigned long timeActual = 0;
float data[10];
int count = 0;
String json;
float lecturaSensor;
void setup() {
  Serial.begin(115200);
}

void loop() {
  if (millis() > timeActual + periodo){
    timeActual = millis();
    lecturaSensor = analogRead(0);
    data[count] = (( lecturaSensor * (500.0 / 1024.0)));
    if(count == 9){
      create_json();
     count = 0;
    }
    count++;
  }
}

void create_json(){
  StaticJsonDocument<500> doc;
  JsonObject root = doc.to<JsonObject>();
  JsonObject datos = root["data"].to<JsonObject>();
  JsonArray array = root["data"].to<JsonArray>();
  for(int i=0 ; i<10; i++){
    array.add(data[i]);
  }
  serializeJsonPretty(doc, Serial);
  serializeJsonPretty(doc, json);
}
