/*
* SPDX-FileCopyrightText: 2024 M5Stack Technology CO LTD
*
* SPDX-License-Identifier: MIT
*/
#include "encoder.h"
#include "hal/hal.h"
#include <cstdint>

using namespace SYSTEM::INPUTS;

Encoder* Encoder::_encoder = nullptr;

Encoder* Encoder::Get()
{
    if (_encoder == nullptr)
    {
        _encoder = new Encoder;
        _encoder->_data.last_encoder_count = HAL::GetEncoderCount();
    }
    return _encoder;
}

void Encoder::update()
{
    auto new_count = HAL::GetEncoderCount();

    if (new_count == _data.last_encoder_count)
    {
        _data.encoder_direction = 0;
        return;
    }

    if (new_count > _data.last_encoder_count)
        _data.encoder_direction = -1;
    else
        _data.encoder_direction = 1;
    _data.last_encoder_count = new_count;
}

void Encoder::reset()
{
    HAL::ResetEncoderCount();
    _data.last_encoder_count = HAL::GetEncoderCount();
    _data.encoder_direction = 0;
}
