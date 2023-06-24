// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef enum {
    SINE,
    SQUARE,
    SAWTOOTH,
    TRIANGLE
} WaveformType;

// Function declaration
void drive(uint16_t freq, uint8_t cycles, WaveformType waveformType);


#endif /* FUNCTIONS_H */