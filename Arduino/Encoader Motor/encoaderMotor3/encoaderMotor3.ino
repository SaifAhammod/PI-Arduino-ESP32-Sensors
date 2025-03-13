#define ENCODER1_C1 2  
#define ENCODER1_C2 4  
#define ENCODER2_C1 11  
#define ENCODER2_C2 12  

#define MOTOR1_ENA 10
#define MOTOR1_IN1 9
#define MOTOR1_IN2 8
#define MOTOR2_IN3 7
#define MOTOR2_IN4 6
#define MOTOR2_ENB 5

volatile int encoder1Count = 0;
volatile int encoder2Count = 0;

// Interrupt Service Routine for Encoder 1
void encoder1ISR() {
  if (digitalRead(ENCODER1_C1) == digitalRead(ENCODER1_C2)) {
    encoder1Count++;
  } else {
    encoder1Count--;
  }
}

// Interrupt Service Routine for Encoder 2
void encoder2ISR() {
  if (digitalRead(ENCODER2_C1) == digitalRead(ENCODER2_C2)) {
    encoder2Count++;
  } else {
    encoder2Count--;
  }
}

void setup() {
  Serial.begin(9600);

  // Encoder 1 Pins
  pinMode(ENCODER1_C1, INPUT_PULLUP);
  pinMode(ENCODER1_C2, INPUT_PULLUP);
  
  // Encoder 2 Pins
  pinMode(ENCODER2_C1, INPUT_PULLUP);
  pinMode(ENCODER2_C2, INPUT_PULLUP);

  // Attach Interrupts
  attachInterrupt(digitalPinToInterrupt(ENCODER1_C1), encoder1ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER2_C1), encoder2ISR, CHANGE);

  // Motor Pins Setup
  pinMode(MOTOR1_ENA, OUTPUT);
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_ENB, OUTPUT);
  pinMode(MOTOR2_IN3, OUTPUT);
  pinMode(MOTOR2_IN4, OUTPUT);
}

void loop() {
  // Move Motors Forward
  analogWrite(MOTOR1_ENA, 150);
  digitalWrite(MOTOR1_IN1, LOW);
  digitalWrite(MOTOR1_IN2, HIGH);
  
  analogWrite(MOTOR2_ENB, 150);
  digitalWrite(MOTOR2_IN3, LOW);
  digitalWrite(MOTOR2_IN4, HIGH);
  
  delay(1000);
  
  Serial.print("Encoder 1 Count: ");
  Serial.println(encoder1Count);
  
  Serial.print("Encoder 2 Count: ");
  Serial.println(encoder2Count);
  
  // Move Motors Backward
  digitalWrite(MOTOR1_IN1, HIGH);
  digitalWrite(MOTOR1_IN2, LOW);
  
  digitalWrite(MOTOR2_IN3, HIGH);
  digitalWrite(MOTOR2_IN4, LOW);
  
  delay(1000);
}
