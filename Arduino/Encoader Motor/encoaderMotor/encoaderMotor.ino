#define ENCODER_C1 11
#define ENCODER_C2 12
#define MOTOR_ENA 10
#define MOTOR_IN1 9
#define MOTOR_IN2 8

volatile int encoderCount = 0;

void encoderISR() {
  if (digitalRead(ENCODER_C1) == digitalRead(ENCODER_C2)) {
    encoderCount++;
  } else {
    encoderCount--;
  }
}

void setup() {
  Serial.begin(9600);
  
  pinMode(ENCODER_C1, INPUT);
  pinMode(ENCODER_C2, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCODER_C1), encoderISR, CHANGE);
  
  pinMode(MOTOR_ENA, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  
}

void loop() {
  analogWrite(MOTOR_ENA, 50); // Set motor speed (0-255)
  Serial.print("Encoder Count 1: ");
  Serial.println(encoderCount);
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);
  delay(1000);
  Serial.print("Encoder Count 2: ");
  Serial.println(encoderCount);
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  delay(1000);
}
