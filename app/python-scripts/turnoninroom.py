#!/usr/bin/env python


import time
import sys
from grovepi import *

# Connect the Grove LED to digital port D4

if sys.argv[1] == '2':
    led = 2
    if digitalRead(led) == 0:
        pinMode(led,"OUTPUT")
        digitalWrite(led,1)           # Send LOW to switch on LED

if sys.argv[1] == '3':
    led = 3
    if digitalRead(led) == 0:
        pinMode(led,"OUTPUT")
        digitalWrite(led,1)

if sys.argv[1] == '4':
    led = 4
    if digitalRead(led) == 0:
        pinMode(led,"OUTPUT")
        digitalWrite(led,1)
