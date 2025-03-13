#define ENCODER_C1 13  
#define ENCODER_C2 12  
#define MOTOR_ENA 10
#define MOTOR_IN1 9
#define MOTOR_IN2 8

volatile int encoderCount = 0;

ISR(PCINT0_vect) {  
  if (digitalRead(ENCODER_C1) == digitalRead(ENCODER_C2)) {
    encoderCount++;
  } else {
    encoderCount--;
  }
}

void setup() {
  Serial.begin(9600);
  
  pinMode(ENCODER_C1, INPUT_PULLUP);
  pinMode(ENCODER_C2, INPUT_PULLUP);

  // Enable Pin Change Interrupts
  PCICR |= (1 << PCIE0);  
  PCMSK0 |= (1 << PCINT3);  // Enable interrupt for D11

  pinMode(MOTOR_ENA, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
}

void loop() {
  analogWrite(MOTOR_ENA, 150);  
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);
  delay(1000);
  
  Serial.print("Encoder Count: ");
  Serial.println(encoderCount);
  
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  delay(1000);
}
