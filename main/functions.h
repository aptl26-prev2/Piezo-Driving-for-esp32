// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define SIG_SIZE_MAX             	(1024 * 4) // Maximum waveform table size



typedef enum {
    SINE,
    SQUARE,
    SAWTOOTH,
    TRIANGLE
} WaveformType;

void advSensingExecuteSensing();

extern bool check;
extern bool sense;
extern bool press;
extern bool release;

// Function declaration
void drive(uint16_t freq, uint8_t cycles, WaveformType waveformType);


#endif /* FUNCTIONS_H */