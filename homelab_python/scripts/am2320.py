import time
import board
import adafruit_am2320

i2c = board.I2C()  # uses board.SCL and board.SDA
am2320 = adafruit_am2320.AM2320(i2c);

def am2320_temperature():
    now = time.strftime('%Y-%m-%d %H:%M:%S %Z', time.localtime())
    print(F"{now} | Temperature: {am2320.temperature} °C")


def am2320_humidity():
    now = time.strftime('%Y-%m-%d %H:%M:%S %Z', time.localtime())
    print(F"{now} | Humidity: {am2320.relative_humidity} %")
