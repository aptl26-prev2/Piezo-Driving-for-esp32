/*
 * utils.c
 *
 *  Created on: Dec 5, 2021
 *      Author: NicolasGonthier
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "spi.h"

// Convert value in volts to Amplitude FIFO code
int16_t utilsVolt2Amplitude(float volt)
{
    int16_t amplitude = volt*2047/3.6/31;

    return amplitude;
}
