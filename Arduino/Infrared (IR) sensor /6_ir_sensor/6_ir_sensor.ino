#define NUM_SENSORS 6  // Total number of IR sensors
#define THRESHOLD 200  // Adjust based on testing

int sensorPins[NUM_SENSORS] = {A0, A1, A2, A3, A4, A5};  // IR sensor pins

void setup() {
    Serial.begin(9600);
}

void loop() {
    bool objectDetected = false;

    for (int i = 0; i < NUM_SENSORS; i++) {
        int sensorValue = analogRead(sensorPins[i]);  // Read each sensor

        if (sensorValue < THRESHOLD) {
            Serial.print("Object Detected at Sensor ");
            Serial.println(i);
            objectDetected = true;
        }
    }

    if (!objectDetected) {
        Serial.println("No Object Detected");
    }

    delay(2000);  // Delay for stability
}
