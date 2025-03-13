//It works perfectly
// Define motor control pins
#define ENA 10  // PWM pin for Motor A
#define IN1 9  // Direction pin for Motor A
#define IN2 8  // Direction pin for Motor A
#define ENB 5 // PWM pin for Motor B
#define IN3 7  // Direction pin for Motor B
#define IN4 6  // Direction pin for Motor B

// Encoder pins
#define ENCODER_A1 2
#define ENCODER_A2 4
#define ENCODER_B1 3
#define ENCODER_B2 11

volatile int encoderCountA = 0;
volatile int encoderCountB = 0;

void encoderA_ISR() {
    if (digitalRead(ENCODER_A2) == HIGH) {
        encoderCountA++;
    } else {
        encoderCountA--;
    }
}

void encoderB_ISR() {
    if (digitalRead(ENCODER_B2) == HIGH) {
        encoderCountB++;
    } else {
        encoderCountB--;
    }
}

void setup() {
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    
    pinMode(ENCODER_A1, INPUT);
    pinMode(ENCODER_A2, INPUT);
    pinMode(ENCODER_B1, INPUT);
    pinMode(ENCODER_B2, INPUT);

    attachInterrupt(digitalPinToInterrupt(ENCODER_A1), encoderA_ISR, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENCODER_B1), encoderB_ISR, CHANGE);
    
    Serial.begin(9600);
}

void setMotorA(int speed) {
    if (speed > 0) {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
    } else {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
    }
    analogWrite(ENA, abs(speed));
}

void setMotorB(int speed) {
    if (speed > 0) {
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    } else {
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    }
    analogWrite(ENB, abs(speed));
}

void loop() {
    setMotorA(150); // Run Motor A at half speed
    setMotorB(150); // Run Motor B at half speed
    
    delay(2000);
    
    setMotorA(-150); // Reverse Motor A
    setMotorB(-150); // Reverse Motor B
    
    delay(2000);
    
    setMotorA(0); // Stop Motor A
    setMotorB(0); // Stop Motor B
    
    delay(1000);
    
    Serial.print("Encoder A Count: ");
    Serial.println(encoderCountA);
    Serial.print("Encoder B Count: ");
    Serial.println(encoderCountB);
}
