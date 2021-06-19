import time
from homelab_python.scripts.am2320 import *
from homelab_python.scripts.dht22 import *


def run():
    while True:
        try:
            am2320_temperature()
            am2320_humidity()

            dht22_temperature()
            dht22_humidity()
        except (RuntimeError, TypeError) as error:
            print(error.args[0])
            continue
        except Exception as error:
            print(error.args[0])
            raise error
        time.sleep(2)
