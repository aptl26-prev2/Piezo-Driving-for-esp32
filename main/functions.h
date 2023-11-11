// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define SIG_SIZE_MAX             	(1024 * 4) // Maximum waveform table size

#include <cstdint>

typedef enum {
    SINE,
    SQUARE,
    SAWTOOTH,
    TRIANGLE
} WaveformType;

void advSensingExecuteSensing();
void advSensingInit(uint8_t channel);

extern bool check;
extern bool sense;
extern bool press;
extern bool release;
extern uint8_t fingerSensing;
extern uint8_t fingersDriving[5];


// Function declaration
void drive(uint16_t freq, uint8_t cycles, WaveformType waveformType);


#endif /* FUNCTIONS_H */