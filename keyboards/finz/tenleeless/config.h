// Copyright 2022 Michael Lee (@MichaelRLee)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#define LOCKING_RESYNC_ENABLE
#define LED_CAPS_LOCK_PIN C6
#define LED_SCROLL_LOCK_PIN D6

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
