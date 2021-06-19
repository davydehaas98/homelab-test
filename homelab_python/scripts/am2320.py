import time
import board
import adafruit_am2320

i2c = board.I2C()  # uses board.SCL and board.SDA
am2320 = adafruit_am2320.AM2320(i2c);

def am2320_temperature():
    now = time.strftime('%Y-%m-%d %H:%M:%S %Z', time.localtime())
    temperature_c = am2320.temperature
    temperature_f = temperature_c * (9/5) + 32
    
    print(F"{now} | Temperature: {temperature_c} °C")
    print(F"{now} | Temperature: {temperature_f} °F")


def am2320_humidity():
    now = time.strftime('%Y-%m-%d %H:%M:%S %Z', time.localtime())
    
    print(F"{now} | Humidity: {am2320.relative_humidity} %")
