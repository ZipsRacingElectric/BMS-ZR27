// Header
#include "lamp_check.h"

bool lampCheckActive = false; 
systime_t lampCheckStartTime;

void lampCheckStart()
{
    // Save current system time
    lampCheckStartTime = chVTGetSystemTimeX();

    // Enable lamp check output
    palSetLine(LINE_LAMP_TEST_CTRL);

    lampCheckActive = true;
}

void lampCheckUpdate()
{
    // Do nothing if lamp check is inactive
    if (!lampCheckActive)
        return;

    // Calculate time elapsed since lamp check started
    systime_t elapsed = chTimeDiffX(lampCheckStartTime, chVTGetSystemTimeX());

    // Check whether lamp check duration has elapsed
    if (elapsed >= TIME_MS2I(LAMP_CHECK_DURATION_MS))
    {
        // Disable lamp check output
        palClearLine(LINE_LAMP_TEST_CTRL);

        // Mark lamp check as complete
        lampCheckActive = false;
    }
} 