/*
 * Copyright (C) 2015-2016 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    cpu_efm32wg Silicon Labs EFM32WG
 * @ingroup     cpu
 * @brief       Support for the Silicon Labs EFM32WG CPU
 * @{
 *
 * @file
 * @brief       Implementation specific CPU configuration options
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 * @author      Bas Stottelaar <basstottelaar@gmail.com>
 */

#ifndef CPU_CONF_H
#define CPU_CONF_H

#include "cpu_conf_common.h"

#include "em_device.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   ARM Cortex-M4 specific CPU configuration
 * @{
 */
#define CPU_DEFAULT_IRQ_PRIO            (1U)
#define CPU_IRQ_NUMOF                   (FPUEH_IRQn + 1)
#define CPU_FLASH_BASE                  FLASH_BASE
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* __CPU_CONF_H */
/** @} */