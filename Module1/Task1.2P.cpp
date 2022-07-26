// C++ code
//
const uint8_t SENSOR_PIN = 2;
const uint8_t LED_PIN = 13;


void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN), toggleLed, CHANGE);
  
  Serial.begin(9600);
  
}

void loop()
{
}

void toggleLed() 
{
  uint8_t sensorState = digitalRead(SENSOR_PIN);
  
  Serial.print(sensorState);
  Serial.println("");
  
  digitalWrite(LED_PIN , sensorState);               
}