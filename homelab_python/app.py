import time
from homelab_python.scripts.am2320 import *
from homelab_python.scripts.dht22 import *


def run():
    while True:
        am2320_temperature()
        am2320_humidity()

        dht22_temperature()
        dht22_humidity()

        time.sleep(10)
