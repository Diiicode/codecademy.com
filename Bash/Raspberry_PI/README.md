# Raspberry Pi Quickstart: Setup, CLI, GPIO & Electronics

> A compact recap of the Raspberry Pi pieces you covered: setup, command line, environment, I/O redirection, and hands‑on electronics.

---

## 1) What is Raspberry Pi?

A small, Linux‑capable single‑board computer. You interact with it via a terminal (local or SSH) and can control hardware through its 40‑pin GPIO header.

**Key facts**

* OS: Raspberry Pi OS (Debian‑based).
* Storage: microSD (or USB/SSD on newer models).
* Power: 5V USB (ensure a capable PSU; undervoltage causes instability).
* GPIO logic level: **3.3V** (not 5V‑tolerant!).

---

## 2) First‑Time Setup

**Flash the OS**

1. Use **Raspberry Pi Imager** → pick Raspberry Pi OS.
2. In Imager’s settings, preconfigure: hostname, user, password, Wi‑Fi, locale, enable **SSH**.
3. Write to microSD, insert, boot Pi.

**Initial updates & config**

```bash
sudo apt update && sudo apt full-upgrade -y
sudo raspi-config        # enable SSH, I2C, SPI, camera, set locale/timezone
```

> Tip: find your Pi on the network via router UI or try `ping raspberrypi.local` (mDNS). SSH in: `ssh <user>@raspberrypi.local`.

---

## 3) Command Line Essentials

Navigation & files (recap): `pwd`, `ls -lah`, `cd`, `mkdir -p`, `touch`.

Redirection & pipes (recap):

```bash
echo "Hello"  > hello.txt     # overwrite
echo "World" >> hello.txt     # append
cat hello.txt | wc -w          # pipes
```

Environment & history:

```bash
env | sort            # list env vars
export PATH="$HOME/bin:$PATH"
history 25            # last 25 commands
alias ll='ls -lah'    # handy alias (put in ~/.bashrc)
source ~/.bashrc      # reload changes
```

---

## 4) GPIO, Interfaces & Electronics

**Pin highlights (40‑pin header)**

* Power: 5V (pins 2, 4), 3V3 (pin 1), GND (many).
* I²C: SDA1 (GPIO2), SCL1 (GPIO3) — enable via `raspi-config`.
* SPI0: MOSI (GPIO10), MISO (GPIO9), SCLK (GPIO11), CE0 (GPIO8), CE1 (GPIO7).
* UART: TXD (GPIO14), RXD (GPIO15).

> ⚠️ Use series resistors with LEDs (≈220–1kΩ). Never feed 5V into a GPIO.

**Tools**

```bash
pinout                 # show header map (on Raspberry Pi OS)
ls /dev/i2c* /dev/spi* # check enabled buses
sudo apt install -y i2c-tools
sudo i2cdetect -y 1    # scan I²C bus 1
```

**Python: easiest way to start (`gpiozero`)**

```python
# blink_led.py
from gpiozero import LED
from time import sleep
led = LED(17)  # GPIO17 (pin 11)
while True:
    led.toggle()
    sleep(0.5)
```

```bash
python3 blink_led.py
```

**Read a button (internal pull‑up)**

```python
from gpiozero import Button
btn = Button(27, pull_up=True)
btn.when_pressed = lambda: print("pressed")
btn.when_released = lambda: print("released")
btn.wait_for_press()
```

**I²C quick check**

```bash
i2cdetect -y 1   # shows device hex addresses (e.g., 0x48)
```

---

## 5) Camera (Bookworm)

Use `libcamera` tools.

```bash
libcamera-still -o image.jpg
libcamera-vid -t 5000 -o video.h264   # 5s clip
```

---

## 6) System & Services

```bash
vcgencmd measure_temp           # SoC temperature
systemctl status ssh            # service status
sudo systemctl enable --now ssh # enable and start service
journalctl -u ssh --since today # service logs
```

---

## 7) Troubleshooting

* **Undervoltage**: lightning bolt icon / throttling → use a better power supply & cable.
* **No boot**: reflash SD; check Imager settings; HDMI cable/monitor, or use SSH headless.
* **I²C device not found**: check wiring (SDA↔SDA, SCL↔SCL, GND), bus enabled, correct 3.3V power.
* **Permissions**: add user to groups: `gpio`, `i2c`, `spi`, `video`.

```bash
sudo usermod -aG gpio,i2c,spi,video $USER
```

---

## 8) Mini Project Ideas

* Blink an LED, then add a push‑button.
* Read a temperature sensor (e.g., I²C) and log to a CSV.
* Take a time‑lapse with the camera (`cron` + `libcamera-still`).

---

## 9) Safety Cheat Sheet

* Work at **3.3V** logic only; level‑shift 5V sensors.
* Always share grounds between Pi and external circuits.
* Power down before rewiring; avoid shorting 5V to 3.3V/GPIO.

---

### One‑pager Installer (optional)

```bash
# Essentials for electronics & Python projects
sudo apt update && sudo apt install -y python3-gpiozero python3-pip i2c-tools git
sudo raspi-config   # enable interfaces
```

---

*Happy making!* 🍓
