# Frequency_Meter
A simple Frequency Meter using microcontroller PIC18F4550

Using the CCP Module (from the PIC18F4550) in Capture mode, we built a simple frequency meter that allows the user to measure frenquencies from 100 Hz to 12 kHz (approx).

To get this frequency range, we set the Capture module to trigger every 4th rising edge. To be able to get lower frequency ranges, we must trigger the CCP module every rising/falling edge, but if we want to get bigger frequency ranges, we have to trigger it every 16th risign edge.

![prototype](https://user-images.githubusercontent.com/91303136/231691286-28da868c-945d-4252-a832-cff78dbfd7fe.jpg)
