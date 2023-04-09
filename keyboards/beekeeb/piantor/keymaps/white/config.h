#include "../../config.h"

// Ensure true N-key rollover is on by default.
#define FORCE_NKRO

// It appears that the Waveshare RP2040-plus (which I am using) lacks a VBUS pin.
// At the very least, the keyboard currently behaves very differently depending
// on which half I plug in when USB_VBUS_PIN is set.
#undef USB_VBUS_PIN

#define TAPPING_TERM  200
#define IGNORE_MOD_TAP_INTERRUPT
