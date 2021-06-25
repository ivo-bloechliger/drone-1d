#include<Wire.h>
#include<Servo.h>
const int MPU_addr = 0x68; // I2C address of the MPU-6050
Servo drone;
void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
  drone.attach(10);
  drone.write(20);
  delay(2000);
}
void loop() {
  drone.write(50);
  delay(1000);
  drone.write(65);
  delay(1000);
}
