#!/usr/bin/python
from ClearPathMotorSD import ClearPathMotorSD
import time

def main():
    x = ClearPathMotorSD()
    x.attach(24,25,23)
    x.setMaxVelInMM(5000)
    x.setAccelInMM(4615)
    x.setDeccelInMM(4615)
    x.stepsPer100mm(1000)
    x.disable()
    time.sleep(.5)
    x.enable()
    x.moveInMM(1000,2500)
    while not x.commandDone():
        x.commandDone()
    x.disable()

if __name__ == '__main__':
        main()