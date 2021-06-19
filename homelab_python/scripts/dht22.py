import time
import board
import adafruit_dht

dht22 = adafruit_dht.DHT22(board.D7, use_pulseio=False)

def dht22_temperature():
    now = time.strftime('%Y-%m-%d %H:%M:%S %Z', time.localtime())
    temperature_c = dht22.temperature
    temperature_f = temperature_c * (9/5) + 32
    
    print(F"{now} | Temperature: {temperature_c} °C")
    print(F"{now} | Temperature: {temperature_f} °F")

def dht22_humidity():
    now = time.strftime('%Y-%m-%d %H:%M:%S %Z', time.localtime())
    
    print(F"{now} | Humidity: {dht22.relative_humidity} %")
