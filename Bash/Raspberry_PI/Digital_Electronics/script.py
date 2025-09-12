from gpiozero import LED
from time import sleep

led14 = LED(14)
led15 = LED(15)
led18 = LED(18)

for i in range(6):
  led14.on()
  sleep(0.5)
  led14.off()
  led15.on()
  sleep(0.5)
  led15.off()
  led18.on()
  sleep(0.5)
  led18.off()