/*
 * Copyright (C) 2015-2016 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_slwstk6220a
 * @{
 *
 * @file
 * @brief       Configuration of CPU peripherals for the SLWSTK6220A starter kit
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 * @author      Bas Stottelaar <basstottelaar@gmail.com>
 */

#ifndef PERIPH_CONF_H
#define PERIPH_CONF_H

#include "cpu.h"

#include "periph_cpu.h"

#include "em_cmu.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Clock configuration
 * @{
 */
#ifndef CLOCK_HF
#define CLOCK_HF            cmuSelect_HFXO
#endif
#ifndef CLOCK_CORE_DIV
#define CLOCK_CORE_DIV      cmuClkDiv_1
#endif
#ifndef CLOCK_LFA
#define CLOCK_LFA           cmuSelect_LFXO
#endif
#ifndef CLOCK_LFB
#define CLOCK_LFB           cmuSelect_LFXO
#endif
/** @} */

/**
 * @brief   ADC configuration
 * @{
 */
static const adc_conf_t adc_config[] = {
    {
        ADC0,                               /* device */
        cmuClock_ADC0,                      /* CMU register */
    }
};

static const adc_chan_conf_t adc_channel_config[] = {
    {
        0,                                  /* device index */
        adcSingleInputTemp,                 /* channel to use */
        adcRef1V25,                         /* channel reference */
        adcAcqTime8                         /* acquisition time */
    },
    {
        0,                                  /* device index */
        adcSingleInputVDDDiv3,              /* channel to use */
        adcRef1V25,                         /* channel reference */
        adcAcqTime8                         /* acquisition time */
    }
};

#define ADC_NUMOF           (2U)
/** @} */

/**
 * @brief   DAC configuration
 * @{
 */
static const dac_conf_t dac_config[] = {
    {
        DAC0,                               /* device */
        cmuClock_DAC0,                      /* CMU register */
    }
};

static const dac_chan_conf_t dac_channel_config[] = {
    {
        0,                                  /* DAC channel index */
        1,                                  /* channel to use */
        dacRefVDD,                          /* channel reference */
    }
};

#define DAC_NUMOF           (1U)
/** @} */

/**
 * @brief   I2C configuration
 * @{
 */
static const i2c_conf_t i2c_config[] = {
    {
        I2C1,                               /* device */
        GPIO_PIN(PE, 0),                    /* SDA pin */
        GPIO_PIN(PE, 1),                    /* SCL pin */
        I2C_ROUTE_LOCATION_LOC2,            /* AF location */
        cmuClock_I2C1,                      /* CMU register */
        I2C1_IRQn                           /* IRQ base channel */
    }
};

#define I2C_NUMOF           (1U)
#define I2C_0_ISR           isr_i2c1
/** @} */

/**
 * @brief   PWM configuration
 * @{
 */
static const pwm_chan_conf_t pwm_channel_config[] = {
    {
        0,                          /* channel index */
        GPIO_PIN(PF, 6),            /* PWM pin */
        TIMER_ROUTE_LOCATION_LOC2   /* AF location */
    },
    {
        1,                          /* channel index */
        GPIO_PIN(PF, 7),            /* PWM pin */
        TIMER_ROUTE_LOCATION_LOC2   /* AF location */
    }
};

static const pwm_conf_t pwm_config[] = {
    {
        TIMER0,                     /* device */
        cmuClock_TIMER0,            /* CMU register */
        TIMER0_IRQn,                /* IRQ base channel */
        2,                          /* number of channels */
        pwm_channel_config          /* first channel config */
    }
};

#define PWM_NUMOF                    (1U)
#define PWM_0_EN                     1
/** @} */

/**
 * @brief   RTC configuration
 */
#define RTC_NUMOF           (1U)

/**
 * @brief   RTT configuration
 * @{
 */
#define RTT_NUMOF           (1U)

#define RTT_MAX_VALUE       (0xFFFFFF)
#define RTT_FREQUENCY       (1U)
/** @} */

/**
 * @brief   SPI configuration
 * @{
 */
static const spi_dev_t spi_config[] = {
    {
        USART1,                             /* device */
        GPIO_PIN(PD, 0),                    /* MOSI pin */
        GPIO_PIN(PD, 1),                    /* MISO pin */
        GPIO_PIN(PD, 2),                    /* CLK pin */
        USART_ROUTE_LOCATION_LOC1,          /* AF location */
        cmuClock_USART1,                    /* CMU register */
        USART1_RX_IRQn                      /* IRQ base channel */
    }
};

#define SPI_NUMOF           (1U)
#define SPI_0_EN            1
/** @} */

/**
 * @brief   Timer configuration
 * @{
 */
static const timer_conf_t timer_config[] = {
    {
        {
            TIMER1,             /* lower numbered timer */
            cmuClock_TIMER1     /* pre-scaler bit in the CMU register */
        },
        {
            TIMER2,             /* higher numbered timer, this is the one */
            cmuClock_TIMER2     /* pre-scaler bit in the CMU register */
        },
        TIMER2_IRQn             /* IRQn of the higher numbered timer */
    }
};

#define TIMER_NUMOF         (1U)
#define TIMER_0_ISR         isr_timer2
#define TIMER_0_MAX_VALUE   (0xffff)
/** @} */

/**
 * @brief   UART configuration
 * @{
 */
static const uart_conf_t uart_config[] = {
    {
        USART2,                             /* device */
        GPIO_PIN(PB, 4),                    /* RX pin */
        GPIO_PIN(PB, 3),                    /* TX pin */
        USART_ROUTE_LOCATION_LOC1,          /* AF location */
        cmuClock_USART2,                    /* CMU register */
        USART2_RX_IRQn                      /* IRQ base channel */
    },
    {
        USART1,                             /* device */
        GPIO_PIN(PD, 1),                    /* RX pin */
        GPIO_PIN(PD, 0),                    /* TX pin */
        USART_ROUTE_LOCATION_LOC1,          /* AF location */
        cmuClock_USART1,                    /* CMU register */
        USART1_RX_IRQn                      /* IRQ base channel */
    },
    {
        LEUART0,                            /* device */
        GPIO_PIN(PD, 5),                    /* RX pin */
        GPIO_PIN(PD, 4),                    /* TX pin */
        LEUART_ROUTE_LOCATION_LOC0,         /* AF location */
        cmuClock_LEUART0,                   /* CMU register */
        LEUART0_IRQn                        /* IRQ base channel */
    }
};

#define UART_NUMOF          (3U)
#define UART_0_ISR_RX       isr_usart1_rx
#define UART_1_ISR_RX       isr_usart2_rx
#define UART_2_ISR_RX       isr_leuart0
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CONF_H */
/** @} */
