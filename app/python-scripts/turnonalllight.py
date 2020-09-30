#!/usr/bin/env python

import time
from grovepi import *

# Connect the Grove LED to digital port D4

led = 4
if digitalRead(led) == 1:
    pinMode(led,"OUTPUT")
    digitalWrite(led,0)
led = 3
if digitalRead(led) == 1:
    pinMode(led,"OUTPUT")
    digitalWrite(led,0)
led = 2
if digitalRead(led) == 1:
    pinMode(led,"OUTPUT")
    digitalWrite(led,0)           # Send LOW to switch on LED