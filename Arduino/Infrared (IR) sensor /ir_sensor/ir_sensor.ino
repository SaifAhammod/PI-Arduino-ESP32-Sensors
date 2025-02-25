#define IR_SENSOR A3  // Analog pin connected to IR sensor
#define THRESHOLD 200  // Adjust based on testing

void setup() {
    Serial.begin(9600);
}

void loop() {
    int sensorValue = analogRead(IR_SENSOR);  

    if (sensorValue < THRESHOLD) {  
        Serial.println("Object Detected!");  
    } else {  
        Serial.println("No Object");  
    }  

    delay(500);  
}
