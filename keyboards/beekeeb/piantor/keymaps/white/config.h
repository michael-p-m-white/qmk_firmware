#include "../../config.h"

// Ensure true N-key rollover is on by default.
#define FORCE_NKRO

// It appears that the Waveshare RP2040-plus (which I am using) lacks a VBUS pin.
// At the very least, the keyboard currently behaves very differently depending
// on which half I plug in when USB_VBUS_PIN is set.
// If we define EE_HANDS and include an extra flag when flashing, we can include
// extra information in EEPROM which tells each half which side it's on.
// Note that the qmk command in documentation didn't work for me; I had use the
// following make command:
// make beekeeb/piantor:white:uf2-split-left
// for the left, and the same command with "uf2-split-right" for the right half.
#define EE_HANDS

#define TAPPING_TERM  200
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM_PER_KEY
