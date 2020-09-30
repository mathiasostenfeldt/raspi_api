import grovepi
import math
# Connect the Grove Temperature & Humidity Sensor Pro to digital port D4
# This example uses the blue colored sensor.
# SIG,NC,VCC,GND
sensor = 7  # The Sensor goes on digital port 4.
 
# temp_humidity_sensor_type
# Grove Base Kit comes with the blue sensor.
blue = 1    # The Blue colored sensor.
white = 0   # The White colored sensor.
 
while True:
    try:
        # This example uses the blue colored sensor.
        # The first parameter is the port, the second parameter is the type of sensor.
        [temp,humidity] = grovepi.dht(sensor,white)  
        if math.isnan(temp) == False and math.isnan(humidity) == False:
            print(temp)
 
    except IOError:
        print ("Error")