# Flipper Zero "Hello World" App

import time
from flipper import Flipper

# Verbinde mit dem Flipper Zero
flipper = Flipper()

try:
    while True:
        # Zeige "Hello World" auf dem Display des Flipper Zero an
        flipper.display.text("Hello World")
        time.sleep(1)  # Warte 1 Sekunde

except KeyboardInterrupt:
    # Bei Tastaturunterbrechung (z.B. durch Strg + C) aufräumen
    flipper.display.clear()
    flipper.disconnect()
