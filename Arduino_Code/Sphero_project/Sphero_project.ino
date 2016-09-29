//#include <SoftwareSerial.h>

//#define txPin 1

//SoftwareSerial LCD = SoftwareSerial(0, txPin);

#define sensorPin A1

int sensorVal = 0;

byte endBoot[] = {0xFF, 0xFE, 0x01, 0x04, 0x01, 0xFA };
byte shellMode[] = {0xFF, 0xFF, 0x02, 0x42, 0x33, 0x02, 0x01, 0x85 };


void setup()
{
  Serial1.begin(115200);
  SerialUSB.begin(9600);
  pinMode(sensorPin, INPUT);
  delay(500);
  Serial1.write(endBoot, sizeof(endBoot));
  delay(500);
  Serial1.write(shellMode, sizeof(shellMode));
}

void loop()
{  
  sensorVal = analogRead(sensorPin);

  SerialUSB.println(sensorVal);
  
  if (sensorVal <= 10){
    Serial1.write("mf 255");
    Serial1.println();
  } else if (sensorVal <= 20){
    Serial1.write("mf 200");
    Serial1.println();
  } else if (sensorVal <= 30){
    Serial1.write("mf 150");
    Serial1.println();
  } else if (sensorVal <= 40){
    Serial1.write("mf 100");
    Serial1.println();
  } else if (sensorVal <= 50){
    Serial1.write("mf 50");
    Serial1.println();
  } else {
    Serial1.write("mh 0");
    Serial1.println();
  }
}
