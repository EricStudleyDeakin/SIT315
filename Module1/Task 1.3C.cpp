const uint8_t SOIL_PIN = 2;
const uint8_t MOTION_PIN = 3;

void setup()
{
  pinMode(SOIL_PIN, INPUT);
  pinMode(MOTION_PIN, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
 
  attachInterrupt(digitalPinToInterrupt(SOIL_PIN), detectMoisture, CHANGE);
  attachInterrupt(digitalPinToInterrupt(MOTION_PIN), detectMotion, CHANGE);

  Serial.begin(9600);
  
}

void loop()
{

}

void detectMoisture() 
{
  
  int sensor = digitalRead(SOIL_PIN);
  Serial.print(sensor);
  Serial.println("");
  
  digitalWrite(13, sensor);
         
}
void detectMotion() 
{
  
  int sensor = digitalRead(MOTION_PIN);
  Serial.print(sensor);
  Serial.println("");
  
  digitalWrite(12, sensor);
         
}