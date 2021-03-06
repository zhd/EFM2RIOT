/*
 * Copyright (C) 2015-2016 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    boards_slstk3401a Silicon Labs SLSTK3401A starter kit
 * @ingroup     boards
 * @brief       Support for the Silicon Labs SLSTK3401A starter kit
 * @{
 *
 * @file
 * @brief       Board specific definitions for the SLSTK3401A starter kit
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
 * @brief   Xtimer configuration.
 * @note    The timer runs at 250 KHz to increase accuracy.
 * @{
 */
#define XTIMER_HZ           (250000UL)
#define XTIMER_SHIFT        (2)
#define XTIMER_WIDTH        (16)
/** @} */

/**
 * @brief   Define for enabling Advanced Energy Monitor core output via SWO.
 * @{
 */
#ifndef AEM_ENABLED
#define AEM_ENABLED                 (1)
#endif
/** @} */

/**
 * @brief   GPIO pin for enabling communication through the board controller.
 * @{
 */
#ifndef BC_ENABLED
#define BC_ENABLED                  (1)
#endif
    #define BC_PIN              GPIO_PIN(PA, 5)
/** @} */

/**
 * @brief   Push button pin definitions.
 * @{
 */
#define PB0_PIN             GPIO_PIN(PF, 6)
#define PB1_PIN             GPIO_PIN(PF, 7)
/** @} */

/**
 * @brief    LED pin definitions.
 * @{
 */
#define LED0_PIN            GPIO_PIN(PF, 4)
#define LED1_PIN            GPIO_PIN(PF, 5)
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
 * @brief   Connection to the on-board Sharp Memory LCD (LS013B7DH03).
 * @{
 */
#define DISP_SPI            (0)
#define DISP_COM_PIN        GPIO_PIN(PD, 13)
#define DISP_CS_PIN         GPIO_PIN(PD, 14)
#define DISP_EN_PIN         GPIO_PIN(PD, 15)
/** @} */

/**
 * @brief   Connection to the on-board temperature/humidity sensor (Si7021).
 * @{
 */
#ifndef SI7021_ENABLED
#define SI7021_ENABLED          (1)
#endif
#define SI7021_I2C              (0)
#define SI7021_EN_PIN           GPIO_PIN(PD, 9)

#define SI70XX_PARAM_I2C_DEV    SI7021_I2C
/** @} */

/**
 * @brief   Initialize the board (GPIO, sensors, clocks).
 */
void board_init(void);

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H */
/** @} */
