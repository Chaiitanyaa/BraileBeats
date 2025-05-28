// Braille-based music input using 6 tactile buttons
const int speakerPin = 2;
const int braillePins[6] = {4, 5, 6, 7, 8, 9}; // Dot 1 to Dot 6

// Frequencies
#define NOTE_C 262
#define NOTE_D 294
#define NOTE_E 330
#define NOTE_F 349
#define NOTE_G 392
#define NOTE_A 440
#define NOTE_B 494
#define NOTE_REST 0

struct BrailleNote {
  byte pattern;     // 6-bit Braille code (dot 1 = bit 5, dot 6 = bit 0)
  int frequency;    // Hz
  int duration;     // ms
};

//Braille music mapping based the chart
BrailleNote notes[] = {
  // Format: {pattern, frequency, duration}
  // Whole Notes (1000 ms)
  {0b101111, NOTE_C, 1000},
  {0b101011, NOTE_D, 1000},
  {0b111101, NOTE_E, 1000},
  {0b111111, NOTE_F, 1000},
  {0b111011, NOTE_G, 1000},
  {0b011101, NOTE_A, 1000},
  {0b011111, NOTE_B, 1000},
  {0b101100, NOTE_REST, 1000},

  // Half Notes (500 ms)
  {0b101110, NOTE_C, 500},
  {0b101010, NOTE_D, 500},
  {0b111100, NOTE_E, 500},
  {0b111110, NOTE_F, 500},
  {0b111010, NOTE_G, 500},
  {0b011100, NOTE_A, 500},
  {0b011110, NOTE_B, 500},
  {0b101001, NOTE_REST, 500},

  // Quarter Notes (250 ms)
  {0b100111, NOTE_C, 250},
  {0b100011, NOTE_D, 250},
  {0b110101, NOTE_E, 250},
  {0b110111, NOTE_F, 250},
  {0b110011, NOTE_G, 250},
  {0b010101, NOTE_A, 250},
  {0b010111, NOTE_B, 250},
  {0b111001, NOTE_REST, 250},

  // Eighth Notes (125 ms)
  {0b100110, NOTE_C, 125},
  {0b100010, NOTE_D, 125},
  {0b110100, NOTE_E, 125},
  {0b110110, NOTE_F, 125},
  {0b110010, NOTE_G, 125},
  {0b010100, NOTE_A, 125},
  {0b010110, NOTE_B, 125},
  {0b101101, NOTE_REST, 125},
};

void setup() {
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
  for (int i = 0; i < 6; i++) {
    pinMode(braillePins[i], INPUT);
  }
}

void loop() {
  byte pattern = 0;
  Serial.print("Braille Input: ");

  // Read all Braille pins and build 6-bit pattern
  for (int i = 0; i < 6; i++) {
    int state = digitalRead(braillePins[i]);
    if (state == HIGH) {
      pattern |= (1 << (5 - i));
      Serial.print("•");  // Pressed = dot
    } else {
      Serial.print(".");  // Not pressed = blank
    }
  }

  // Search for matching Braille pattern
  for (int i = 0; i < sizeof(notes) / sizeof(notes[0]); i++) {
    if (notes[i].pattern == pattern) {
      if (notes[i].frequency == 0) {
        delay(notes[i].duration); // REST
      } else {
        tone(speakerPin, notes[i].frequency, notes[i].duration);
        delay(notes[i].duration + 100);
      }
      break; // Only match the first valid input
    }
  }

  //For Debugging
  Serial.print("  Binary: ");
  Serial.print(pattern, BIN);  // e.g. 110011
  Serial.print("  Decimal: ");
  Serial.println(pattern);     // e.g. 51

  delay(1000); // Prevent multiple triggers for a single press
} 

/*

const int speakerPin = 2;  // Pin for buzzer or speaker
const int buttonPins[] = {4, 5, 6, 7, 8, 9};
const int noteFreqs[] = {262, 294, 330, 349, 392, 440}; // C, D, E, F, G, A
const int noteDuration = 1000; // Duration in milliseconds

void setup() {
  pinMode(speakerPin, OUTPUT);
  for (int i = 0; i < 6; i++) {
    pinMode(buttonPins[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i < 6; i++) {
    if (digitalRead(buttonPins[i]) == HIGH) {
      tone(speakerPin, noteFreqs[i], noteDuration);
      delay(noteDuration + 100); // Wait for tone to finish + small delay
    }
  }
} */