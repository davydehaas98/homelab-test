import time
import board
import adafruit_bme280

# Create sensor object, using the board's default I2C bus.
i2c = board.I2C()  # uses board.SCL and board.SDA
bme280 = adafruit_bme280.Adafruit_BME280_I2C(i2c)

# Create sensor object, using the board's default SPI bus.
# spi = board.SPI()
# bme_cs = digitalio.DigitalInOut(board.D10)
# bme280 = adafruit_bme280.Adafruit_BME280_SPI(spi, bme_cs)

# Change this to match the location's pressure (hPa) at sea level
bme280.sea_level_pressure = 1013.25

def bme280_temperature():
    now = time.strftime('%Y-%m-%d %H:%M:%S %Z', time.localtime())
    temperature_c = bme280.temperature
    temperature_f = round(temperature_c * 1.8 + 32, 2)
    
    print(F"{now} | Temperature: {temperature_c} °C")
    print(F"{now} | Temperature: {temperature_f} °F")

def bme280_humidity():
    now = time.strftime('%Y-%m-%d %H:%M:%S %Z', time.localtime())
    
    print(F"{now} | Humidity: {bme280.relative_humidity} %")

def bme280_pressure():
    now = time.strftime('%Y-%m-%d %H:%M:%S %Z', time.localtime())

    print(F"{now} | Pressure: {bme280.pressure} hPa")

def bme280_altitude():
    now = time.strftime('%Y-%m-%d %H:%M:%S %Z', time.localtime())

    print(F"{now} | Altitude: {bme280.altitude} meters")
