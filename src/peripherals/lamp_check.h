#ifndef LAMP_CHECK_H
#define LAMP_CHECK_H

// ChibiOS
#include "ch.h"
#include "hal.h"

// Lamp Check Timer ------------------------------------------------------------------------------------------------------------
//
// Author: Jake Nowak
// Date Created: 2026.11.5
//
// Description: Implements a timer for the lamp check rule: (FSAE EV.6.3), (FHE EV9.3)
// Note that lamp check should last 2-3 seconds and should not inhibit normal fault protection of BMS

// Lamp Check Timer Configuration
#define LAMP_CHECK_DURATION_MS 2500

// Functions  -------------------------------------------------------------------------------------------------------------------

/// @brief Start the lamp check sequence.
void lampCheckStart(void);

/// @brief Update the lamp check state without blocking fault logic.
void lampCheckUpdate(void);

#endif // LAMP_CHECK_H