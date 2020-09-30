# home_temp_hum_display.py.py
#
# In this project, the Temperature and humidity from the DHT sensor is printed on the DHT sensor

from grovepi import *

dht_sensor_port = 7             # Connect the DHt sensor to port 7
[ temp,hum ] = dht(dht_sensor_port,1)           #Get the temperature and Humidity from the DHT sensor
t = str(temp)
h = str(hum)
    print(t)