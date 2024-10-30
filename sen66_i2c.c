/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * Generator:     sensirion-driver-generator 1.0.1
 * Product:       sen66
 * Model-Version: 1.2.0
 */
/*
 * Copyright (c) 2024, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "sen66_i2c.h"
#include "sensirion_common.h"
#include "sensirion_i2c.h"
#include "sensirion_i2c_hal.h"

#define sensirion_hal_sleep_us sensirion_i2c_hal_sleep_usec

static uint8_t communication_buffer[48] = {0};

static uint8_t _i2c_address;

void sen66_init(uint8_t i2c_address) {
    _i2c_address = i2c_address;
}

float sen66_signal_mass_concentration_pm1p0(
    uint16_t mass_concentration_pm1p0_raw) {
    float mass_concentration_pm1p0 = 0.0;
    mass_concentration_pm1p0 = mass_concentration_pm1p0_raw / 10.0;
    return mass_concentration_pm1p0;
}

float sen66_signal_mass_concentration_pm2p5(
    uint16_t mass_concentration_pm2p5_raw) {
    float mass_concentration_pm2p5 = 0.0;
    mass_concentration_pm2p5 = mass_concentration_pm2p5_raw / 10.0;
    return mass_concentration_pm2p5;
}

float sen66_signal_mass_concentration_pm4p0(
    uint16_t mass_concentration_pm4p0_raw) {
    float mass_concentration_pm4p0 = 0.0;
    mass_concentration_pm4p0 = mass_concentration_pm4p0_raw / 10.0;
    return mass_concentration_pm4p0;
}

float sen66_signal_mass_concentration_pm10p0(
    uint16_t mass_concentration_pm10p0_raw) {
    float mass_concentration_pm10p0 = 0.0;
    mass_concentration_pm10p0 = mass_concentration_pm10p0_raw / 10.0;
    return mass_concentration_pm10p0;
}

float sen66_signal_temperature(int16_t temperature_raw) {
    float temperature = 0.0;
    temperature = temperature_raw / 200.0;
    return temperature;
}

float sen66_signal_humidity(int16_t humidity_raw) {
    float humidity = 0.0;
    humidity = humidity_raw / 100.0;
    return humidity;
}

float sen66_signal_voc_index(int16_t voc_index_raw) {
    float voc_index = 0.0;
    voc_index = voc_index_raw / 10.0;
    return voc_index;
}

float sen66_signal_nox_index(int16_t nox_index_raw) {
    float nox_index = 0.0;
    nox_index = nox_index_raw / 10.0;
    return nox_index;
}

float sen66_signal_co2(uint16_t co2_raw) {
    float co2 = 0.0;
    co2 = co2_raw / 1.0;
    return co2;
}

int16_t sen66_read_measured_values(float* mass_concentration_pm1p0,
                                   float* mass_concentration_pm2p5,
                                   float* mass_concentration_pm4p0,
                                   float* mass_concentration_pm10p0,
                                   float* humidity, float* temperature,
                                   float* voc_index, float* nox_index,
                                   float* co2) {
    uint16_t mass_concentration_pm1p0_raw = 0;
    uint16_t mass_concentration_pm2p5_raw = 0;
    uint16_t mass_concentration_pm4p0_raw = 0;
    uint16_t mass_concentration_pm10p0_raw = 0;
    int16_t humidity_raw = 0;
    int16_t temperature_raw = 0;
    int16_t voc_index_raw = 0;
    int16_t nox_index_raw = 0;
    uint16_t co2_raw = 0;
    int16_t local_error = 0;
    local_error = sen66_read_measured_values_as_integers(
        &mass_concentration_pm1p0_raw, &mass_concentration_pm2p5_raw,
        &mass_concentration_pm4p0_raw, &mass_concentration_pm10p0_raw,
        &humidity_raw, &temperature_raw, &voc_index_raw, &nox_index_raw,
        &co2_raw);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    *mass_concentration_pm1p0 =
        sen66_signal_mass_concentration_pm1p0(mass_concentration_pm1p0_raw);
    *mass_concentration_pm2p5 =
        sen66_signal_mass_concentration_pm2p5(mass_concentration_pm2p5_raw);
    *mass_concentration_pm4p0 =
        sen66_signal_mass_concentration_pm4p0(mass_concentration_pm4p0_raw);
    *mass_concentration_pm10p0 =
        sen66_signal_mass_concentration_pm10p0(mass_concentration_pm10p0_raw);
    *humidity = sen66_signal_humidity(humidity_raw);
    *temperature = sen66_signal_temperature(temperature_raw);
    *voc_index = sen66_signal_voc_index(voc_index_raw);
    *nox_index = sen66_signal_nox_index(nox_index_raw);
    *co2 = sen66_signal_co2(co2_raw);
    return local_error;
}

int16_t sen66_device_reset() {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command16_to_buffer(buffer_ptr, local_offset, 0xd304);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(1200 * 1000);
    return local_error;
}

int16_t sen66_start_continuous_measurement() {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command16_to_buffer(buffer_ptr, local_offset, 0x21);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(50 * 1000);
    return local_error;
}

int16_t sen66_stop_measurement() {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command16_to_buffer(buffer_ptr, local_offset, 0x104);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(160 * 1000);
    return local_error;
}

int16_t sen66_get_data_ready(uint8_t* padding, bool* data_ready) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command16_to_buffer(buffer_ptr, local_offset, 0x202);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(20 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 2);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    *padding = (uint8_t)buffer_ptr[0];
    *data_ready = (bool)buffer_ptr[1];
    return local_error;
}

int16_t sen66_read_measured_values_as_integers(
    uint16_t* mass_concentration_pm1p0, uint16_t* mass_concentration_pm2p5,
    uint16_t* mass_concentration_pm4p0, uint16_t* mass_concentration_pm10p0,
    int16_t* ambient_humidity, int16_t* ambient_temperature, int16_t* voc_index,
    int16_t* nox_index, uint16_t* co2) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command16_to_buffer(buffer_ptr, local_offset, 0x300);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(20 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 18);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    *mass_concentration_pm1p0 =
        sensirion_common_bytes_to_uint16_t(&buffer_ptr[0]);
    *mass_concentration_pm2p5 =
        sensirion_common_bytes_to_uint16_t(&buffer_ptr[2]);
    *mass_concentration_pm4p0 =
        sensirion_common_bytes_to_uint16_t(&buffer_ptr[4]);
    *mass_concentration_pm10p0 =
        sensirion_common_bytes_to_uint16_t(&buffer_ptr[6]);
    *ambient_humidity = sensirion_common_bytes_to_int16_t(&buffer_ptr[8]);
    *ambient_temperature = sensirion_common_bytes_to_int16_t(&buffer_ptr[10]);
    *voc_index = sensirion_common_bytes_to_int16_t(&buffer_ptr[12]);
    *nox_index = sensirion_common_bytes_to_int16_t(&buffer_ptr[14]);
    *co2 = sensirion_common_bytes_to_uint16_t(&buffer_ptr[16]);
    return local_error;
}

int16_t
sen66_perform_forced_co2_recalibration(uint16_t target_co2_concentration,
                                       uint16_t* correction) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command16_to_buffer(buffer_ptr, local_offset, 0x6707);
    local_offset = sensirion_i2c_add_uint16_t_to_buffer(
        buffer_ptr, local_offset, target_co2_concentration);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(500 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 2);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    *correction = sensirion_common_bytes_to_uint16_t(&buffer_ptr[0]);
    return local_error;
}

int16_t sen66_get_product_name(uint8_t* product_name,
                               uint16_t product_name_size) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command16_to_buffer(buffer_ptr, local_offset, 0xd014);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(20 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 32);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_common_copy_bytes(&buffer_ptr[0], (uint8_t*)product_name,
                                product_name_size);
    return local_error;
}

int16_t sen66_get_serial_number(uint8_t* serial_number,
                                uint16_t serial_number_size) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command16_to_buffer(buffer_ptr, local_offset, 0xd033);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(20 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 32);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_common_copy_bytes(&buffer_ptr[0], (uint8_t*)serial_number,
                                serial_number_size);
    return local_error;
}

int16_t sen66_get_version(uint8_t* firmware_major, uint8_t* firmware_minor,
                          bool* firmware_debug, uint8_t* hardware_major,
                          uint8_t* hardware_minor, uint8_t* protocol_major,
                          uint8_t* protocol_minor, uint8_t* padding) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command16_to_buffer(buffer_ptr, local_offset, 0xd000);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(20 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 8);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    *firmware_major = (uint8_t)buffer_ptr[0];
    *firmware_minor = (uint8_t)buffer_ptr[1];
    *firmware_debug = (bool)buffer_ptr[2];
    *hardware_major = (uint8_t)buffer_ptr[3];
    *hardware_minor = (uint8_t)buffer_ptr[4];
    *protocol_major = (uint8_t)buffer_ptr[5];
    *protocol_minor = (uint8_t)buffer_ptr[6];
    *padding = (uint8_t)buffer_ptr[7];
    return local_error;
}
