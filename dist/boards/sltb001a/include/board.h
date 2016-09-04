/*
 * Copyright (C) 2015-2016 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    boards_sltb001a Silicon Labs SLTB001A starter kit
 * @ingroup     boards
 * @brief       Support for the Silicon Labs SLTB001A starter kit
 * @{
 *
 * @file
 * @brief       Board specific definitions for the SLTB001A starter kit
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 * @author      Bas Stottelaar <basstottelaar@gmail.com>
 */

#ifndef BOARD_H
#define BOARD_H

#include "cpu.h"

#include "periph_conf.h"
#include "periph/gpio.h"
#include "periph/spi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Xtimer configuration
 * @{
 */
#define XTIMER                      (0)
#define XTIMER_CHAN                 (0)
#define XTIMER_WIDTH                (16)
#define XTIMER_SHIFT_ON_COMPARE     (2)
/** @} */

/**
 * @brief   Push button pin definitions
 * @{
 */
#define PB0_PIN             GPIO_PIN(PD, 14)
#define PB1_PIN             GPIO_PIN(PD, 15)
/** @} */

/**
 * @brief    LED pin definitions
 * @{
 */
#define LED0_PIN            GPIO_PIN(PD, 11)
#define LED1_PIN            GPIO_PIN(PD, 12)
/** @} */

/**
 * @brief   Macros for controlling the on-board LEDs.
 * @{
 */
#define LED0_ON             gpio_set(LED0_PIN)
#define LED0_OFF            gpio_clear(LED0_PIN)
#define LED0_TOGGLE         gpio_toggle(LED0_PIN)
#define LED1_ON             gpio_set(LED1_PIN)
#define LED1_OFF            gpio_clear(LED1_PIN)
#define LED1_TOGGLE         gpio_toggle(LED1_PIN)
/** @} */

/**
 * @brief   Pin for enabling environmental sensors (BMP280, Si1133, Si7021, Si7210A).
 */
#define ENV_SENSE_EN_PIN    GPIO_PIN(0, 0)

/**
 * @brief   Connection to the on-board pressure sensor (BMP280)
 * @{
 */
#ifndef BMP280_ENABLED
#define BMP280_ENABLED      (0)
#endif
#define BMP280_I2C          (0)
/** @} */

/**
 * @brief   Connection to the on-board air quality/gas sensor (CCS811)
 * @{
 */
#ifndef CCS811_ENABLED
#define CCS811_ENABLED      (0)
#endif
#define CCS811_I2C          (0)
#define CCS811_EN_PIN       GPIO_PIN(0, 0)
#define CCS811_INT_PIN      GPIO_PIN(0, 0)
#define CCS811_WAKE_PIN     GPIO_PIN(0, 0)
/** @} */

/**
 * @brief   Connection to the on-board IMU sensor (ICM-20648)
 * @{
 */
#ifndef ICM20648_ENABLED
#define ICM20648_ENABLED    (0)
#endif
#define ICM20648_SPI        (0)
#define ICM20648_EN_PIN     GPIO_PIN(0, 0)
#define ICM20648_INT_PIN    GPIO_PIN(0, 0)
/** @} */

/**
 * @brief   Connection to the on-board UV/ambient light sensor (Si1133)
 * @{
 */
#ifndef SI1133_ENABLED
#define SI1133_ENABLED      (0)
#endif
#define SI1133_I2C          (0)
#define SI1133_INT_PIN      GPIO_PIN(0, 0)
/** @} */

/**
 * @brief   Connection to the on-board temperature/humidity sensor (Si7021)
 * @{
 */
#ifndef SI7021_ENABLED
#define SI7021_ENABLED      (0)
#endif
#define SI7021_I2C          (0)
/** @} */

/**
 * @brief   Connection to the on-board hall-effect sensor (Si7210A)
 * @{
 */
#ifndef SI7210A_ENABLED
#define SI7210A_ENABLED      (0)
#endif
#define SI7210A_I2C          (0)
/** @} */

/**
 * @brief   Initialize the board (GPIO, sensors, clocks)
 */
void board_init(void);

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H */
/** @} */