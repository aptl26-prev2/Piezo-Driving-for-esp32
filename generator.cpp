#include <stdio.h>
#include <math.h>

#define PI 3.14159265
#define PLAY_SAMPLING_RATE 8000
#define PRESS_SIGNAL_VOLTAGE 60
#define WAVEFORM_SIZE 256

typedef enum {
    SINE,
    SQUARE,
    SAWTOOTH,
    TRIANGLE
} WaveformType;

double press_waveform[WAVEFORM_SIZE];

double UtilsVolt2Amplitude(double volt) {
    double amplitude = (volt * 2047 / 3.6 / 31);
    return amplitude;
}

void GeneratePressWaveform(double frequency, WaveformType waveformType) {
    int press_waveform_size = (int)(PLAY_SAMPLING_RATE / frequency);
    double angleIncrement = 2 * PI * frequency / PLAY_SAMPLING_RATE;

    for (int i = 0; i < press_waveform_size; i++) {
        double angle = i * angleIncrement;
        double normalizedValue;

        switch (waveformType) {
            case SINE:
                normalizedValue = sin(angle);
                break;
            case SQUARE:
                normalizedValue = fmod(angle, 2 * PI) < PI ? 1 : -1;
                break;
            case SAWTOOTH:
                normalizedValue = fmod(angle, 2 * PI) / (2 * PI) * 2 - 1;
                break;
            case TRIANGLE:
                normalizedValue = 4 * fabs(fmod(angle, 2 * PI) / (2 * PI) - 0.5) - 1;
                break;
            default:
                normalizedValue = 0;
                break;
        }

        press_waveform[i] = UtilsVolt2Amplitude(PRESS_SIGNAL_VOLTAGE / 2 * (normalizedValue + 1));
    }
}


int main() {
    double frequency = 50;
    WaveformType waveformType = SINE;  // Change this to SQUARE, SAWTOOTH, or TRIANGLE to generate different waveforms
    GeneratePressWaveform(frequency, waveformType);

    FILE *file = fopen("waveform.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i < WAVEFORM_SIZE; i++) {
        printf("Sample %d: %f\n", i, press_waveform[i]);
        // fprintf(file, "%f\n", press_waveform[i]);
    }

    fclose(file);
    return 0;
}
