#define ENA 5   // Speed control for Motor A
#define IN1 7   // Direction for Motor A
#define IN2 6   

#define ENB 10  // Speed control for Motor B
#define IN3 9   // Direction for Motor B
#define IN4 8   

void setup() {
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void loop() {
    int speedA = 255;  // Speed (0-255)
    int speedB = 255;

    // Move forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, speedA);
    analogWrite(ENB, speedB);
    delay(2000);

    // Stop
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(1000);

    // Move backward
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, speedA);
    analogWrite(ENB, speedB);
    delay(2000);

    // Stop again
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(1000);
    speedA = 200;  // Speed (0-255)
    speedB = 200;

    // Move forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, speedA);
    analogWrite(ENB, speedB);
    delay(2000);
    speedA = 150;  // Speed (0-255)
    speedB = 150;

    // Move forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, speedA);
    analogWrite(ENB, speedB);
    delay(2000);
    speedA = 100;  // Speed (0-255)
    speedB = 100;

    // Move forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, speedA);
    analogWrite(ENB, speedB);
    delay(2000);
    
    speedA = 50;  // Speed (0-255)
    speedB = 50;

    // Move forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, speedA);
    analogWrite(ENB, speedB);
    delay(2000);
}
