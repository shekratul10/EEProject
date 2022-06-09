## Radio wave:
- [x] Create a suitable air-cored inductor
- [x] Test if the air-cored inductor can detect radio waves transmitted from the rock
- [x] Design a suitable amplifier circuit to amplify the detected signal
- [ ] (1 of 2) Detect the carrier frequency of the signal (see below)
- [ ] (2 of 2) Detect the modulating frequency of the signal (see below)
- [ ] Analyse the results from the carrier frequency circuit
- [ ] Analyse the results from the modulating frequency circuit
- [ ] Upload these results to the web interface/app
- [ ] Match the data to determine a suitable profile for the rock (if they emit radio signals)

### Amplifying the circuit
> We need to significantly amplify the signal from picked up from the coil - even using a non-inverting amplifier with a gain of 1001, the output is not sufficiently amplified - the amplitude of the output waveform needs to be greater than the voltage drop from the diode else nothing will be detected at the output of the demodulator circuit. 

### Detecting the carrier frequency (sinusoidal)
> We can apply filtering to the amplified signal to remove the extreme high-frequency noise and some low frequency background radiowaves. We can have a band-pass filter (low pass filter cascade with a high pass filter), where the corner frequencies are the frequency of the carrier signal (61 and 89 kHz). This can be implemented using first order filters, but if we use second order filters with a capacitor and an inductor, then we could use the resonant peak property to make the gain of the signal at the corner frequencies to be much higher than the other frequencies in the passband. From these increased signal peaks, we can analyse this using an analog input and determining the frequency of that input. A 4th order band-pass filter has been constructed and works, no processing has been done on these signals though.

### Detecting the modulating frequency (square)
> We need to demodulate the amplified signal. Some lecture slides and pictures from the Signals and Communications lecture are shown below to aid the development of the rectifier detector. The modulating signal is a square wave, therefore we can analyse it using a digital pin on the Adafruit board. 

<img width="514" alt="Screenshot 2022-05-27 at 13 30 20" src="https://user-images.githubusercontent.com/106095203/170699524-e8e9d5c6-3b9a-4ed8-a5b6-04a688847c5b.png">
<img width="812" alt="Screenshot 2022-05-27 at 13 35 39" src="https://user-images.githubusercontent.com/106095203/170700285-892a02e6-35bd-4648-b640-b554f4468dd6.png">
<img width="847" alt="Screenshot 2022-05-27 at 13 35 51" src="https://user-images.githubusercontent.com/106095203/170700302-2775250b-8dcf-4904-b92c-45511317c1bf.png">
<img width="807" alt="Screenshot 2022-05-27 at 13 36 08" src="https://user-images.githubusercontent.com/106095203/170700337-f9eec882-94a7-4fa6-85c3-48d143ba80ae.png">
<img width="809" alt="Screenshot 2022-05-27 at 13 36 19" src="https://user-images.githubusercontent.com/106095203/170700361-d336ae47-75ba-4add-9d61-88ba2de890f6.png">
