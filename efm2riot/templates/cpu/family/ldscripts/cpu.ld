/*
 * Copyright (C) 2016 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @addtogroup      cpu_{{ family }}
 * @{
 *
 * @file
 * @brief           Memory definitions for the {{ cpu|upper }} CPU
 *
 * @}
 */

MEMORY
{
    rom (rx)    : ORIGIN = 0x00000000, LENGTH = {{ flash_size }}
    ram (rwx)   : ORIGIN = 0x20000000, LENGTH = {{ ram_size }}
}

INCLUDE cortexm_base.ld
