import time
import board
import adafruit_am2320

# Create sensor object, using the board's default I2C bus.
i2c = board.I2C() # uses board.SCL and board.SDA
am2320 = adafruit_am2320.AM2320(i2c);

def am2320_temperature():
    try:
        now = time.strftime('%Y-%m-%d %H:%M:%S %Z', time.localtime())
        temperature_c = am2320.temperature
        temperature_f = round(temperature_c * 1.8 + 32, 2)
        
        print(F"{now} | Temperature: {temperature_c} °C")
        print(F"{now} | Temperature: {temperature_f} °F")
    except RuntimeError as error:
        print(error.args[0])
    except Exception as error:
        print(error.args[0])



def am2320_humidity():
    try:
        now = time.strftime('%Y-%m-%d %H:%M:%S %Z', time.localtime())
        
        print(F"{now} | Humidity: {am2320.relative_humidity} %")
    except RuntimeError as error:
        print(error.args[0])
    except Exception as error:
        print(error.args[0])
