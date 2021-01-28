#include <DynamixelMotor.h>
#include <DynamixelInterface.h>
#include <Dynamixel.h>
#include <DynamixelInterfaceArduinoImpl.h>
#include <DynamixelConsole.h>


const uint8_t id1=1;
const uint8_t id2=2;
int16_t speed=512;
const long unsigned int baudrate=1000000;

SoftwareDynamixelInterface interface_claw(2,3);
SoftwareDynamixelInterface interface_driver(4,5);

DynamixelMotor claw_motor(interface_claw, id1);
DynamixelMotor driver_motor(interface_driver, id2);

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  interface_claw.begin(baudrate);
  interface_driver.begin(baudrate);
  delay(100);
  
  uint8_t status_claw=claw_motor.init();
  uint8_t status_driver=driver_motor.init();
  if(status_claw!=DYN_STATUS_OK || status_driver!=DYN_STATUS_OK)
  {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    while(1);
  }
  Serial.println("Motor init complete");
  claw_motor.enableTorque();  
  claw_motor.wheelMode();
  driver_motor.enableTorque();  
  driver_motor.wheelMode();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    int control = Serial.read() - '0';
    switch(control) {
      case 1:
        open();
        Serial.println("Open");
        break;
      case 2:
        close();
        Serial.println("Close");
        break;
      case 3:
        stop();
        Serial.println("Stop");
        break;
      case 4:
        forward();
        break;
      default:
        break;
    }
    delay(1000);
  }
}

void open(){
  claw_motor.speed(speed);
}

void close(){
  claw_motor.speed(-speed);
}

void stop(){
  claw_motor.speed(0);
}

void forward(){
  driver_motor.speed(speed);
}
