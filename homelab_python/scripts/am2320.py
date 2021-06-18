import board
import adafruit_am2320


def am2320_temperature():
    i2c = board.I2C()  # uses board.SCL and board.SDA
    am2320 = adafruit_am2320.AM2320(i2c)
    print(F"Temperature: {am2320.temperature} °C")


def am2320_humidity():
    i2c = board.I2C()  # uses board.SCL and board.SDA
    am2320 = adafruit_am2320.AM2320(i2c)
    print(F"Humidity: {am2320.relative_humidity} %")
