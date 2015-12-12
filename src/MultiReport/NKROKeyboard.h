/*
Copyright (c) 2014-2015 NicoHood
See the readme for credit to other people.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

// Include guard
#pragma once

#include <Arduino.h>
#include "PluggableUSB.h"
#include "HID.h"
#include "HID-Settings.h"

#include "HIDTables.h"
#include "HIDAliases.h"

// Max value for USB EP_SIZE 16
// +1 reportID, +1 modifier, +1 custom key
#define NKRO_KEY_COUNT (8*13)

typedef union {
    // Modifier + keymap + 1 custom key
    uint8_t whole8[];
    uint16_t whole16[];
    uint32_t whole32[];
    struct {
        uint8_t modifiers;
        uint8_t keys[NKRO_KEY_COUNT / 8];
        uint8_t key;
    };
    uint8_t allkeys[2 + NKRO_KEY_COUNT / 8];
} HID_NKROKeyboardReport_Data_t;



class NKROKeyboard_ {
  public:
    NKROKeyboard_(void);
    inline void begin(void);
    inline void end(void);

    inline size_t press(uint8_t k);
    inline size_t release(uint8_t k);
    inline size_t releaseAll(void);
    inline int sendReport(void);
  protected:
    HID_NKROKeyboardReport_Data_t _keyReport;

};
extern NKROKeyboard_ NKROKeyboard;

