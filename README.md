# 🎵 BrailleBeats – A Music Aid for the Visually Impaired

**BrailleBeats** is an Arduino-powered Tangible User Interface (TUI) designed to help blind and visually impaired individuals learn, practice, and play music using Braille notation. By translating tactile Braille music inputs into sound, the system provides immediate audio feedback, supporting musical creativity, practice, and accessibility.

---

## 📌 Features

- 🎹 Accepts Braille music notation as input using 6 push buttons (Braille cell layout)
- 🔊 Converts inputs into musical notes using a piezo buzzer
- ⏱ Supports note durations: whole, half, quarter, and eighth notes
- 🧠 Designed to minimize learning curve for existing Braille users
- 🔗 Inspired by research in accessible music learning and tangible interaction

---

## 🎯 Motivation

Visually impaired musicians face barriers due to the scarcity of Braille music sheets, non-standardized notation systems, and a lack of real-time feedback. BrailleBeats addresses these challenges by enabling tactile interaction and real-time sound output for music education and practice.

---

## 🛠 Hardware Requirements

- 1 × Arduino Uno R3
- 6 × Push buttons
- 6 × 10kΩ resistors
- 1 × Active piezo buzzer
- 1 × Breadboard
- Jumper wires

---

## 🧾 Circuit Diagram

![Circuit Diagram](images/circuit.png) <!-- Replace with actual path if hosted -->

---

## 🔧 Setup Instructions

1. **Connect the components** as shown in the circuit diagram:
   - Buttons connected to digital pins 4–9
   - Buzzer connected to pin 2
2. **Upload the Arduino sketch** from [`braillebeats.ino`](braillebeats.ino) to your Arduino Uno.
3. **Press button combinations** matching Braille music characters to play notes.

---

## 🎼 Braille Music Mapping

| Note | Braille Char | Frequency (Hz) | Example Pattern |
|------|---------------|----------------|-----------------|
| C (Do) | d | 261.63 | `100000` |
| D (Re) | e | 293.66 | `101000` |
| E (Mi) | f | 329.63 | `110000` |
| F (Fa) | g | 349.23 | `110100` |
| G (Sol) | h | 392.00 | `100100` |
| A (La) | i | 440.00 | `111000` |
| B (Si) | j | 493.88 | `111100` |
| Rest | - | 0 | `000000` |

> Patterns use a 6-bit binary to match Braille dot layout (dots 1–6)

---

## 📽 Demo

🎥 Watch the system in action:  
[YouTube Demo Link](https://youtu.be/example) <!-- Replace with your actual video -->

---

## 📚 References

- Lang et al. (2023). *BrailleBuddy: A Tangible User Interface to Support Children with Visual Impairment in Learning Braille.*
- Lu et al. (2023). *Improving Access to Blind and Low Vision Music Learning through Personal Adaptations.*
- Johnson, S. (2009). *Notational Systems and Conceptualizing Music: Print vs Braille.*
- RNIB (Royal National Institute of Blind People). *Braille Music Literacy Resources.*

---

## 💡 Future Work

- Add dynamics and tempo variation
- Integrate Bluetooth for MIDI playback
- Develop a full Braille music phrase player
- Add tactile or haptic feedback modules

---

## 🤝 Authors

- **Chaiitanyaa Chopraa** – Software & hardware integration  
- **Aimee Le** – Research & writing  

---

## 📄 License

MIT License – feel free to use and adapt this project for educational or accessibility-related work.

---
