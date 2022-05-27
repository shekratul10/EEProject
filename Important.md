# EEProject

Group 5/ASHB's Repository for the Electronics Design Project (Summer 2022)

Rock properties:


<img width="623" alt="Screenshot 2022-05-27 at 12 43 34" src="https://user-images.githubusercontent.com/106095203/170692913-9280b7b0-e76c-451f-a7b8-0ea30aa6a381.png">


## To do:
- [ ] Magnetic field detection
- [ ] Acoustic signal detection
- [ ] IR pulse detection
- [ ] Radio signal detection
- [ ] Motor control
- [ ] Web interface/app
- [ ] CAD + new EEE Rover designs

### Magnetic:
- [x] Determine a suitable soln. to detect magnetic field
- [x] Determine a suitable sensor to detect magnetic field
- [x] Place order for the chosen sensor
- [x] Approve order for the chosen sensor
- [ ] Design circuit to detect magnetic field
- [ ] Analyse results from the circuit
- [ ] Upload the results to the web interface/app

> Information for writing report on reed switch: https://uk.rs-online.com/web/generalDisplay.html?id=ideas-and-advice/reed-switches-guide. Order has been placed for two reed switches. [Data sheet attached] [Reed switch datasheet.pdf](https://github.com/shekratul10/EEProject/files/8786346/Reed.switch.datasheet.pdf) Just like a regular switch, activated by an external magnetic force -> can use a digital pin on the Adafruit and report true/false if a signal is received at the corresponding pin. Detects just the presence of a magnetic field detected from the rock. Since the polarity of the rock (one of the six) is not given, require two reed switches to detect north and south magnetic poles. May use two digital pins. Then use the data from the table above to determine the rocks correctly. We expect this to be complete within 1-2 days of the Reed switches being delivered. 

### Acoustic:
- [ ] Determine a suitable soln. to detect acoustic signals
- [ ] Determine a suitable sensor to detect acoustic signals
- [ ] Place order for the chosen sensor
- [ ] Approve order for the chosen sensor
- [ ] Design circuit to demodulate the signal from the chosen sensor
- [ ] Analyse results from the circuit
- [ ] Upload the results to the web interface/app

> The acoustic signal transmitted from the rocks are both at 40 kHz, therefore we just need to design a circuit specific for this frequency and detect if it is present from the rock sample. Then use other properties of the rocks (IR and radio) to determine the rock sample being analysed. 

### Infrared:
- [x] Determine a suitable soln. to detect Infrared pulses
- [x] Determine a suitable sensor to detect Infrared pulses
- [x] Place order for the chosen sensor
- [x] Approve order for the chosen sensor
- [ ] Design circuit to detect IR pulse*
- [ ] Design circuit to amplify the IR pulse signal
- [ ] Analyse results from the circuit (determine the frequency of the pulse)
- [ ] Upload the results to the web interface/app

> The phototransistor is a light-controlled current source; we connect the phototransistor into Vcc and a load resistor and measure the voltage across the resistor. When measuring the IR pulse with the exorock shell, there is a "extremely" weak signal therefore we need to amplify the pulsed signal. Filtering may be required to remove the ambient IR that may interfere with the readings. We can then process the results using the digital pin on the Adafruit board and hopefully determine the frequency of the IR pulse and upload the results to the web interface/app. An existing soln. is to use an IR phototransistor SFH 309 FA. [IR phototransistor datasheet.pdf](https://github.com/shekratul10/EEProject/files/8786571/IR.phototransistor.datasheet.pdf) 

### Radio wave:
- [ ] Create a suitable air-cored inductor
- [ ] Test if the air-cored inductor can detect radio waves transmitted from the rock
- [ ] Design a suitable amplifier circuit to amplify the detected signal
- [ ] (1 of 2) Detect the carrier frequency of the signal (see below)
- [ ] (2 of 2) Detect the modulating frequency of the signal (see below)
- [ ] Analyse the results from the carrier frequency circuit
- [ ] Analyse the results from the modulating frequency circuit
- [ ] Upload these results to the web interface/app
- [ ] Match the data to determine a suitable profile for the rock (if they emit radio signals)

Detecting the carrier frequency (sinusoidal)
> We can apply filtering to the amplified signal to remove the extreme high-frequency noise and some low frequency background radiowaves. We can have a band-pass filter (low pass filter cascade with a high pass filter), where the corner frequencies are the frequency of the carrier signal (61 and 89 kHz). This can be implemented using first order filters, but if we use second order filters with a capacitor and an inductor, then we could use the resonant peak property to make the gain of the signal at the corner frequencies to be much higher than the other frequencies in the passband. From these increased signal peaks, we can analyse this using an analog input and determining the frequency of that input.

Detecting the modulating frequency (square)
> We need to demodulate the amplified signal. Some lecture slides and pictures from the Signals and Communications lecture are shown below to aid the development of the rectifier detector. The modulating signal is a square wave, therefore we can analyse it using a digital pin on the Adafruit board. 

<img width="514" alt="Screenshot 2022-05-27 at 13 30 20" src="https://user-images.githubusercontent.com/106095203/170699524-e8e9d5c6-3b9a-4ed8-a5b6-04a688847c5b.png">
<img width="812" alt="Screenshot 2022-05-27 at 13 35 39" src="https://user-images.githubusercontent.com/106095203/170700285-892a02e6-35bd-4648-b640-b554f4468dd6.png">
<img width="847" alt="Screenshot 2022-05-27 at 13 35 51" src="https://user-images.githubusercontent.com/106095203/170700302-2775250b-8dcf-4904-b92c-45511317c1bf.png">
<img width="807" alt="Screenshot 2022-05-27 at 13 36 08" src="https://user-images.githubusercontent.com/106095203/170700337-f9eec882-94a7-4fa6-85c3-48d143ba80ae.png">
<img width="809" alt="Screenshot 2022-05-27 at 13 36 19" src="https://user-images.githubusercontent.com/106095203/170700361-d336ae47-75ba-4add-9d61-88ba2de890f6.png">







