#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <matplotlibcpp.h>



// Include necessary libraries for plotting (e.g., Matplotlib for Python)

// Function to generate a sine wave
std::vector<double> generate_sine_wave(double amplitude, double frequency, double sampling_rate, int num_samples) {
    std::vector<double> waveform(num_samples);
    double time_step = 1.0 / sampling_rate;

    for (int i = 0; i < num_samples; ++i) {
        double time = i * time_step;
        waveform[i] = amplitude * sin(2 * M_PI * frequency * time);
    }

    return waveform;
}

// Function to generate a square wave
std::vector<double> generate_square_wave(double amplitude, double frequency, double sampling_rate, int num_samples) {
    std::vector<double> waveform(num_samples);
    double time_step = 1.0 / sampling_rate;
    double period = 1.0 / frequency;

    for (int i = 0; i < num_samples; ++i) {
        double time = i * time_step;
        waveform[i] = (time < period / 2) ? amplitude : -amplitude;
    }

    return waveform;
}

// Function to generate a triangle wave
std::vector<double> generate_triangle_wave(double amplitude, double frequency, double sampling_rate, int num_samples) {
    std::vector<double> waveform(num_samples);
    double time_step = 1.0 / sampling_rate;
    double period = 1.0 / frequency;

    for (int i = 0; i < num_samples; ++i) {
        double time = i * time_step;
        double phase = fmod(time, period) / period;
        waveform[i] = amplitude * (4 * phase - 2 * (phase > 0.5));
    }

    return waveform;
}

// Function to generate a sawtooth wave
std::vector<double> generate_sawtooth_wave(double amplitude, double frequency, double sampling_rate, int num_samples) {
    std::vector<double> waveform(num_samples);
    double time_step = 1.0 / sampling_rate;
    double period = 1.0 / frequency;

    for (int i = 0; i < num_samples; ++i) {
        double time = i * time_step;
        double phase = fmod(time, period) / period;
        waveform[i] = amplitude * (2 * phase - 1);
    }

    return waveform;
}

// Function to visualize the waveform (using Matplotlib or another plotting library)

void visualize_waveform(const std::vector<double>& waveform, const std::string& plot_title) {
    namespace plt = matplotlibcpp;

    plt::plot(waveform);
    plt::title(plot_title);
    plt::xlabel("Time (samples)");
    plt::ylabel("Amplitude");
    plt::grid(true);
    plt::show();
}

int main() {
    // Parameters
    double amplitude = 1.0;
    double frequency = 440.0; // Hz
    double sampling_rate = 44100.0; // Hz
    int num_samples = 1024;

    // Generate different waveforms
    std::vector<double> sine_wave = generate_sine_wave(amplitude, frequency, sampling_rate, num_samples);
    std::vector<double> square_wave = generate_square_wave(amplitude, frequency, sampling_rate, num_samples);
    std::vector<double> triangle_wave = generate_triangle_wave(amplitude, frequency, sampling_rate, num_samples);
    std::vector<double> sawtooth_wave = generate_sawtooth_wave(amplitude, frequency, sampling_rate, num_samples);

    // Visualize the waveforms
    visualize_waveform(sine_wave, "Sine Wave");
    visualize_waveform(square_wave, "Square Wave");
    visualize_waveform(triangle_wave, "Triangle Wave");
    visualize_waveform(sawtooth_wave, "Sawtooth Wave");

    return 0;
}