## Acoustic:
- [x] Determine a suitable soln. to detect acoustic signals
- [x] Determine a suitable sensor to detect acoustic signals
- [x] Place order for the chosen sensor
- [x] Approve order for the chosen sensor
- [x] Design circuit to demodulate the signal from the chosen sensor
- [x] Analyse results from the circuit
- [x] Upload the results to the web interface/app

31/05/22: Using the HC-SR04 will not work according to Ed Stott. We will need to use an ultrasound transducer to detect the acoustic signal emitted from the mineral. 

<img width="810" alt="Screenshot 2022-05-31 at 11 58 52" src="https://user-images.githubusercontent.com/106095203/171158535-10306992-3bf4-40bc-8d6f-033c9e1feec1.png">

Ultrasound transducer information: https://en.wikipedia.org/wiki/Ultrasonic_transducer

Datasheet for proposed component:[Ultrasonic sensor.pdf](https://github.com/shekratul10/EEProject/files/8804788/Ultrasonic.sensor.pdf)

Use a transducer; converts ultrasound pulses into an AC signal, which we can analyse using the analogue pins on the adafruit to determine its frequency at 40 kHz. May need to use some amplification to the signal, but testing on ultrasound is not possible without the transducer. 


> The acoustic signal transmitted from the rocks are both at 40 kHz, therefore we just need to design a circuit specific for this frequency and detect if it is present from the rock sample. Then use other properties of the rocks (IR and radio) to determine the rock sample being analysed. 

### Plan for acoustic processing
- [ ] Amplify the signal using an amplifier circuit similar to the one used in the IR pulse circuit and try to obtain an amplitude greater than 580 mV (since this is the voltage drop across the diodes available in the labs)
- [ ] Construct an envelope detector for the amplified signal (see similar notes as radio waves to determine the values0
- [ ] Feed the output of the envelope detector to an analogue input pin on the arduino/adafruit board
- [ ] Write some code that can determine the frequency of the analogue signal
- [ ] Compare the frequency of the signal with some parameters e.g. if the frequency is 40 kHz ± 3 kHz, return true for the detection of the acoustic signal. 

### Proposed circuit
Here is a proposed circuit to detect the ultrasound signals as well as some reasoning behind the values for the bandpass filter.

![Ultrasound circuit](https://user-images.githubusercontent.com/106095203/171390744-fabba37e-6101-4b58-9f1e-4a07e743e574.png)

![Screenshot 2022-06-01 at 12 08 20](https://user-images.githubusercontent.com/106095203/171390810-e42c462e-b2a3-491c-8f77-db44b10162e3.png)

**UPDATE:** For the high pass filter in the proposed circuit diagram above, a 42 Ω resistor is not available in the lab therefore we use a 43 Ω resistor instead. This will give us a corner frequency of 37 kHz, which should be enough to remove unwanted signals that may be picked up. 
