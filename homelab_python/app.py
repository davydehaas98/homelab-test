import time
from homelab_python.scripts.am2320 import *
from homelab_python.scripts.dht22 import *

DELAY = 2.0

def run():
    while True:
        am2320_temperature()
        time.sleep(DELAY)
        am2320_humidity()
        time.sleep(DELAY)
        # dht22_temperature()
        # time.sleep(DELAY)
        # dht22_humidity()
        # time.sleep(DELAY)
