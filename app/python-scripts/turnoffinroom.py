#!/usr/bin/env python


import time
import sys
from grovepi import *

# Connect the Grove LED to digital port D4

if sys.argv[0] == 2:
    led = 2
    if digitalRead(led) == 1:
        pinMode(led,"OUTPUT")
        digitalWrite(led,0)           # Send LOW to switch on LED

if sys.argv[0] == 3:
    led = 3
    if digitalRead(led) == 1:
        pinMode(led,"OUTPUT")
        digitalWrite(led,0)

if sys.argv[0] == 4:
    led = 4
    if digitalRead(led) == 1:
        pinMode(led,"OUTPUT")
        digitalWrite(led,0)
