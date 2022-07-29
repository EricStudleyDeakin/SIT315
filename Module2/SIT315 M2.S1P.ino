// C++ code
//

const byte LED_PIN = 13;
const byte METER_PIN = A4;


void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(METER_PIN, INPUT);
      
  Serial.begin(9600);
  
}

void loop()
{ 
  int val = analogRead(METER_PIN);
  float frequency = val / 1024.0;
  Serial.println(frequency);
  startTimer(frequency);
  delay(2000);
}

void startTimer(double frequency){
 
  //Timer 1 speed = 16Mhz/1024  
  uint16_t target = 1/frequency * (16000000/1024);
  noInterrupts();
  
  Serial.println(target);
  
  TCCR1A = 0;
  TCCR1B = 0;

  TCNT1  = 0;


  TCCR1B |= (1 << WGM12);   // CTC mode

  TCCR1B = (1<<CS20)|(1<<CS21)|(1<<CS22);  // 1024 prescaler 

  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
   
  OCR1A = target;  	
  
  interrupts();
}


ISR(TIMER1_COMPA_vect)
{
  digitalWrite(LED_PIN, digitalRead(LED_PIN) ^ 1);
}

