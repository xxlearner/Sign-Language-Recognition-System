//#include <Adafruit_MPU6050.h>

#include <Wire.h>
#include <MPU6050.h>
#include <SoftwareSerial.h>

MPU6050 mpu;

const int flexPin1 = A0; // Flex sensor 1
const int flexPin2 = A1; // Flex sensor 2
const int flexPin3 = A2; // Flex sensor 3
const int flexPin4 = A3; // Flex sensor 4
const int flexPin5 = A4; // Flex sensor 5

SoftwareSerial bluetoothSerial(4, 5); // RX, TX pins for HC-05

void setup() {
  Serial.begin(9600);
  bluetoothSerial.begin(9600);
  
  Wire.begin();
  mpu.initialize();
  
  // Print initial data
  //Serial.println("MPU-6050 and Flex Sensors Test");
  delay(1000);
}

void loop() {


  // Read MPU-6050 data
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  
  //Serial.print("MPU-6050: ");
 // Serial.print("Accel [X,Y,Z]: ");
  Serial.print(ax); Serial.print(" ");
  Serial.print(ay); Serial.print(" ");
  Serial.print(az); Serial.print("  ");
  //Serial.print("Gyro [X,Y,Z]: ");
  Serial.print(gx); Serial.print(" ");
  Serial.print(gy); Serial.print(" ");
  Serial.print(gz); Serial.print("  ");
  
  // Read flex sensor data
  int flexValue1 = analogRead(flexPin1);
  int flexValue2 = analogRead(flexPin2);
  int flexValue3 = analogRead(flexPin3);
  int flexValue4 = analogRead(flexPin4);
  int flexValue5 = analogRead(flexPin5);
  
 // Serial.print("Flex Sensors: ");
  //Serial.print("Flex1: ");
   Serial.print(flexValue1);
    Serial.print("  ");
  //Serial.print("Flex2: "); 
  Serial.print(flexValue2);
   Serial.print("  ");
  //Serial.print("Flex3: ");
   Serial.print(flexValue3); 
   Serial.print("  ");
  //Serial.print("Flex4: ");
   Serial.print(flexValue4);
    Serial.print("  ");
  //Serial.print("Flex5: "); 
  Serial.println(flexValue5);



if (bluetoothSerial.available() > 0) {
    String receivedData = bluetoothSerial.readStringUntil('\n'); // Read data from Bluetooth serial
    receivedData.trim(); // Remove leading/trailing whitespace
    
    // Process the received data
    if (receivedData == "मलाई सहयोग चाहियो") {
    bluetoothSerial.println(receivedData.c_str());
   } else if (receivedData == "पानी") {
    bluetoothSerial.println(receivedData.c_str());  
   } else if (receivedData == "मलाई भोक लाग्यो") {
    bluetoothSerial.println(receivedData.c_str());
   } else if (receivedData == "के म कल गर्न सक्छु") {
    bluetoothSerial.println(receivedData.c_str());
   } else if (receivedData == "ठिक छ") {
    bluetoothSerial.println(receivedData.c_str());
   } else if (receivedData == "छैन") {
    bluetoothSerial.println(receivedData.c_str());
   } else {
    // Send the default value to the app with UTF-8 encoding
     bluetoothSerial.println("भएन");
   }

}

  delay(3000); // Adjust the delay as needed
}

  

  
