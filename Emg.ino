#include <FFT.h> // Include the FFT library


// Constants
const int EMG_PIN = A0; // Analog input pin for EMG signal
const int SAMPLE_SIZE = 256; // Number of samples for FFT
const int FFT_MAX_FREQ = 500; // Maximum frequency for FFT plot
const double SAMPLING_FREQUENCY = 1000.0; // Sampling frequency of EMG signal
const double VREF = 5.0; // Reference voltage of Arduino (5V)


// Variables
double EMGArray[SAMPLE_SIZE]; // Array to hold EMG samples
double peakToPeak = 0.0; // Peak-to-peak amplitude of EMG signal
double frequency = 0.0; // Frequency of EMG signal


void setup() {
  Serial.begin(9600); // Initialize Serial communication
 
 
  // Set up FFT
  FFT.useAVRfix(); // Enable AVR fix for Arduino boards
  FFT.Windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD); // Set Hamming window for FFT
  FFT.ComputeN(); // Compute N for FFT
  FFT.SetInputScaling(FFT_INPUT_ON); // Enable input scaling for FFT
}


void loop() {
  // Read EMG signal from array or input stream (replace with actual EMG samples)
  for (int i = 0; i < SAMPLE_SIZE; i++) {
    // Use EMGArray[i] = EMGValue; to assign EMG samples to array
    // or use EMGArray[i] = analogRead(EMG_PIN) * (VREF / 1023.0); to read from analog input pin
    // Replace with your own EMG acquisition code
    // Example: EMGArray[i] = ...;
  }
 
  // Perform FFT
  FFT.Windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD); // Apply windowing to samples
  FFT.Compute(EMGArray, SAMPLE_SIZE); // Compute FFT
  FFT.ComplexToMagnitude(); // Convert complex data to magnitude
 
  // Find peak-to-peak amplitude of EMG signal
  peakToPeak = 0.0; // Initialize peak-to-peak amplitude
  for (int i = 0; i < SAMPLE_SIZE; i++) {
    double amplitude = EMGArray[i];
    if (amplitude > peakToPeak) {
      peakToPeak = amplitude; // Update peak-to-peak amplitude
    }
  }
 
  // Find frequency of EMG signal
  frequency = FFT.MajorPeak(); // Get major peak frequency from FFT
 
  // Print frequency domain specifications
  Serial.print(frequency);
  Serial.print(",");
  Serial.println(peakToPeak);
 
  delay(1000); // Delay for visualization purposes (adjust as needed)
}
