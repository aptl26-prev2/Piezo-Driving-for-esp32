using System;
using System.IO;

namespace WaveformGenerator
{
    public enum WaveformType
    {
        Sine,
        Square,
        Sawtooth,
        Triangle
    }

    public class Waveform
    {
        private const int PLAY_SAMPLING_RATE = 8000;
        private const int PRESS_SIGNAL_VOLTAGE = 60;

        public static void GeneratePressWaveform(double frequency, WaveformType waveformType, ref double[] press_waveform)
        {
            int press_waveform_size = (int)(PLAY_SAMPLING_RATE / frequency);
            double angleIncrement = 2 * Math.PI * frequency / PLAY_SAMPLING_RATE;

            for (int i = 0; i < press_waveform_size; i++)
            {
                double angle = i * angleIncrement;
                double normalizedValue;

                switch (waveformType)
                {
                    case WaveformType.Sine:
                        normalizedValue = Math.Sin(angle);
                        break;
                    case WaveformType.Square:
                        normalizedValue = angle % (2 * Math.PI) < Math.PI ? 1 : -1;
                        break;
                    case WaveformType.Sawtooth:
                        normalizedValue = (angle % (2 * Math.PI)) / (2 * Math.PI) * 2 - 1;
                        break;
                    case WaveformType.Triangle:
                        normalizedValue = 4 * Math.Abs(angle % (2 * Math.PI) / (2 * Math.PI) - 0.5) - 1;
                        break;
                    default:
                        throw new ArgumentException("Invalid waveform type");
                }

                press_waveform[i] = UtilsVolt2Amplitude(PRESS_SIGNAL_VOLTAGE / 2 * (normalizedValue + 1));
            }
        }

        // You will need to define the UtilsVolt2Amplitude function here.
        public static short UtilsVolt2Amplitude(double volt)
        {
            short amplitude = (short)(volt * 2047 / 3.6 / 31);
            return amplitude;
        }
    
        class Program
        {
            static void Main(string[] args)
            {
                double frequency = 50;
                WaveformType waveformType = WaveformType.Sine;
                double[] press_waveform = new double[256];

                Waveform.GeneratePressWaveform(frequency, waveformType, ref press_waveform);



                int graphWidth = press_waveform.Length;

                // Create a list of strings representing the waveform data
                List<string> waveformLines = new List<string>();

                for (int i = 0; i < graphWidth; i++)
                {
                    Console.WriteLine($"Sample {i}: {press_waveform[i]}");
                    waveformLines.Add($"{press_waveform[i]}");
                }

                // Save the waveform data to a text file
                File.WriteAllLines("waveform.txt", waveformLines);

            }
        }
    }
}