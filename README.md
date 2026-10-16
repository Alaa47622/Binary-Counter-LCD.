# Binary Counter with LCD Display

A button-controlled 4-bit binary counter implemented on an Arduino Uno and simulated in Tinkercad Circuits. The current count is shown in binary and decimal on a 16x2 character LCD.

**[Run the simulation in Tinkercad](https://www.tinkercad.com/things/gSIbkgwo7IL/editel?sharecode=B9j7xKKM1FGgJW8tOxxviY5YCJSFiaY627Kx7jKl7VY)**

---

## Overview

Each press of the pushbutton increments the counter by one. The value ranges from 0 to 15 (`0000` to `1111`) and wraps to 0 after reaching the maximum.

### Features

- 4-bit binary counter with automatic rollover
- Binary and decimal output on a 16x2 LCD
- Software edge detection and debouncing
- No external resistor required for the button (internal pull-up)

### Example output

```
Binary: 0101
Decimal: 5
```

---

## Hardware

| Qty | Component |
|:---:|-----------|
| 1 | Arduino Uno R3 |
| 1 | LCD 16x2 (HD44780-compatible, parallel interface) |
| 1 | Pushbutton |
| 1 | Breadboard |
| - | Jumper wires |

---

## Pin Configuration

### LCD (4-bit mode)

| LCD Pin | Arduino Pin | Function |
|---------|:-----------:|----------|
| RS | 12 | Register select |
| E | 11 | Enable |
| DB4 | 5 | Data |
| DB5 | 4 | Data |
| DB6 | 3 | Data |
| DB7 | 2 | Data |
| VCC | 5V | Power |
| GND | GND | Ground |
| V0 | GND | Contrast |
| RW | GND | Write mode |
| DB0 - DB3 | - | Not connected |
| LED (x2) | - | Backlight, not connected |

### Pushbutton

| Terminal | Connection |
|----------|------------|
| Side A | Arduino pin 7 |
| Side B | GND |

Side A and Side B must be on opposite sides of the switch. Terminals on the same side are internally shorted and would hold the input permanently LOW.

---

## Getting Started

### Tinkercad

1. Open the above simulation link 
2. Click **Start Simulation**.
3. Click the pushbutton to increment the counter.

### Physical hardware

1. Assemble the circuit according to the pin configuration above.
2. Open `binary_counter.ino` in the Arduino IDE.
3. Select **Arduino Uno** as the board and upload the sketch.

> On a physical LCD, connect V0 to the center pin of a 10 kΩ potentiometer for adjustable contrast, and place a 220 Ω resistor in series with the backlight anode.

---

## How It Works

| Concept | Implementation |
|---------|----------------|
| Button input | `INPUT_PULLUP` holds the pin HIGH; pressing the button pulls it LOW |
| Press detection | The counter increments only on a HIGH to LOW transition, so holding the button counts once |
| Debouncing | A 50 ms delay after each press filters contact bounce |
| Rollover | `count = (count + 1) % 16` returns the value to 0 after 15 |
| Binary output | `(count >> i) & 1` isolates bit `i`; bits are printed from MSB to LSB |

---

## Project Structure

```
binary-counter-lcd/
├── binary_counter.ino   # Arduino sketch
└── README.md
```

---

## Troubleshooting

| Symptom | Resolution |
|---------|------------|
| Blank display | Verify VCC on 5V, and GND, V0, and RW on GND |
| Garbled characters | Confirm DB4 to DB7 map to pins 5, 4, 3, 2 respectively |
| Counter stays at 1 | Button terminals are on the same side; move one wire to the opposite side |
| Skipped counts | Increase the debounce delay to 100 ms |
| Backlight over-current warning | Disconnect the LED pins, or add a 220 Ω series resistor |

---

## Future Improvements

- Extend the counter to 8 bits
- Add a second button for decrement and reset
- Display the value in hexadecimal
- Mirror the count on a row of LEDs

---

## License

This project is released under the [MIT License](LICENSE).
