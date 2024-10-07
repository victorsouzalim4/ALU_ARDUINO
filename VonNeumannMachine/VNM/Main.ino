#include "VNM.h"

VonNeumannMachine vnm;

void setup() {
    Serial.begin(9600);
}

void loop() {
    int i = 0;
    while (true) {
        if (Serial.available() >= 3) {
            i++;
            String x((char)Serial.read());
            String y((char)Serial.read());
            String w((char)Serial.read());
            String str = x + y + w;
            Serial.println(str);

            vnm.registerOperation(str);
            if (i >= 95) {
                vnm.operate();
            }
            delay(10);
        }
    }
}
