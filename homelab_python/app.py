from homelab_python.scripts.am2320 import *


def run():
    while True:
        am2320_temperature()
        am2320_humidity()

        time.sleep(1)
