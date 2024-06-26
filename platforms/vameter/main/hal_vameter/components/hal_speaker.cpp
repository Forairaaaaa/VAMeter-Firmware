/*
* SPDX-FileCopyrightText: 2024 M5Stack Technology CO LTD
*
* SPDX-License-Identifier: MIT
*/
#include "../hal_vameter.h"
#include "../hal_config.h"
#include <mooncake.h>
#include <Arduino.h>

#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494

void HAL_VAMeter::_seaker_init()
{
    initArduino();

    if (_config.beepOn)
    {
        beep(3200, 50);
        delay(80);
        beep(3200, 50);
    }
}

void HAL_VAMeter::beep(float frequency, uint32_t duration)
{
    if (_config.beepOn)
        tone(HAL_PIN_BUZZ, frequency, duration);
}

void HAL_VAMeter::beepStop()
{
    if (_config.beepOn)
        noTone(HAL_PIN_BUZZ);
}
