// C++ code
//
const uint8_t SENSOR_PIN = 2;
const uint8_t LED_PIN = 13;


void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
  
  
  Serial.begin(9600);
  
}

void loop()
{
  uint8_t sensorState = digitalRead(SENSOR_PIN);
  
  Serial.print(sensorState);
  Serial.println("");
  
  digitalWrite(LED_PIN , sensorState);
  
  delay(500);
}