/*
  SingleAxisDemo
  Runs a Teknic ClearPath SDSK or SDHP motor, back and forth
 
 
 This example code is in the public domain.
 */

//Import Required libraries
#include "../ClearPathMotorSD/ClearPathMotorSD.h"
#include "../ClearPathMotorSD/bcm2835drv.h"
#include <iostream>


  // initialize a ClearPathMotorSD Motor
  ClearPathMotorSD X;
  //initialize the controller and pass the reference to the motor we are controlling
 
  // the setup routine runs once when you press reset:
  void setup()
  {  
    //Begin Serial Communication // NOTE: If communication lags, consider increasing baud rate
    //Serial.begin(9600);
    
  //X.attach(9);                //attach motor so Step/B is connected to pin 9
  //X.attach(8,9);              //Direction/A is pin 8, Step/B is pin 9
  X.attach(24,25,23);            //Direction/A is pin 8, Step/B is pin 9, Enable is pin 6
  //X.attach(8,9,6,4);          //Direction/A is pin 8, Step/B is pin 9, Enable is pin 6, HLFB is pin 4

  // Set max Velocity.  Parameter can be between 2 and 100,000 steps/sec
    X.setMaxVelInMM(5000);
    
  // Set max Acceleration.  Parameter can be between 4000 and 2,000,000 steps/sec/sec
    X.setAccelInMM(4615);
    X.setDeccelInMM(4615);
    X.stepsPer100mm(1000);
    
  // Enable motor, reset the motor position to 0
  X.disable();
  DEV_Delay_ms(1000);
  X.enable();

  //delay(100);  
  }

  int main(void)
  {
  DEV_ModuleInit();
  setup();
  // the loop routine runs over and over again forever:

  // Move the motor forward 10,000 steps
    X.moveInMM(1000,2500);
    std::cout << "Move Start" << std::endl;
    
  // wait until the command is finished and The motor's HLFB asserts
    while(!X.commandDone()) //just use command done if not using motor feedback
    { 
      //std::cout << X.commandDone();
    }
    
    std::cout << "Move Done" << std::endl;
    DEV_Delay_ms(10);
    
  // Move the motor backwards 10,000 steps
    X.moveInMM(-500,2500);
    std::cout << "Negative Move Start" << std::endl;
    
  // wait until the command is finished and The motor's HLFB asserts  
    while(!X.commandDone()) //just use command done if not using motor feedback
    { }

    std::cout << "Move Done" << std::endl;
    DEV_Delay_ms(1000);
    X.disable();
    return 0;

}