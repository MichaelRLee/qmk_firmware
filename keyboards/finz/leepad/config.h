// Copyright 2022 Michael Lee (@MichaelRLee)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#define LOCKING_RESYNC_ENABLE
#define LED_NUM_LOCK_PIN B5

#define COMBO_COUNT 1

#define SOFT_SERIAL_PIN D3
#define MASTER_RIGHT
#define SELECT_SOFT_SERIAL_SPEED 1
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
