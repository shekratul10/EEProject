## IR Pulse sensing circuit

- [x] Determine a suitable soln. to detect Infrared pulses
- [x] Determine a suitable sensor to detect Infrared pulses
- [x] Place order for the chosen sensor
- [x] Approve order for the chosen sensor
- [x] Design circuit to detect IR pulse
- [x] Design circuit to amplify the IR pulse signal
- [x] Analyse results from the circuit (determine the frequency of the pulse)
- [x] Write code for determining the frequency of the digital signal detected into the Adafruit
- [ ] Upload the results to the web interface/app
- [x] Begin written report for the infrared detection

### Written report hints

The phototransistor is a light-controlled current source; we connect the phototransistor into Vcc and a load resistor and measure the voltage across the resistor. When measuring the IR pulse with the exorock shell, there is a **extremely** weak signal therefore we need to amplify the pulsed signal. Filtering may be required to remove the ambient IR that may interfere with the readings. We can then process the results using the digital pin on the Adafruit board and hopefully determine the frequency of the IR pulse and upload the results to the web interface/app. An existing soln. is to use an IR phototransistor SFH 309 FA. [IR phototransistor datasheet.pdf](https://github.com/shekratul10/EEProject/files/8786571/IR.phototransistor.datasheet.pdf) 
