# EEProject

Group 5's Repository for the Electronics Design Project (Summer 2022)

Rock properties:


<img width="623" alt="Screenshot 2022-05-27 at 12 43 34" src="https://user-images.githubusercontent.com/106095203/170692913-9280b7b0-e76c-451f-a7b8-0ea30aa6a381.png">

Magnetic:
- [x] Determine a suitable soln. to detect magnetic field
- [x] Determine a suitable sensor to detect magnetic field
- [x] Place order for the chosen sensor
- [x] Approve order for the chosen sensor
- [ ] Design circuit to detect magnetic field
- [ ] Analyse results from the circuit
- [ ] Upload the results to the web interface/app

> Information for writing report on reed switch: https://uk.rs-online.com/web/generalDisplay.html?id=ideas-and-advice/reed-switches-guide. Order has been placed for two reed switches (currently pending)[Data sheet attached] [Reed switch datasheet.pdf](https://github.com/shekratul10/EEProject/files/8786346/Reed.switch.datasheet.pdf) Just like a regular switch, activated by an external magnetic force -> can use a digital pin on the Adafruit and report true/false if a signal is received at the corresponding pin. Detects just the presence of a magnetic field detected from the rock. Since the polarity of the rock (one of the six) is not given, require two reed switches to detect north and south magnetic poles. May use two digital pins. Then use the data from the table above to determine the rocks correctly. 

Acoustic:
- [ ] Determine a suitable soln. to detect acoustic signals
- [ ] Determine a suitable sensor to detect acoustic signals
- [ ] Place order for the chosen sensor
- [ ] Approve order for the chosen sensor
- [ ] Design circuit to demodulate the signal from the chosen sensor
- [ ] Analyse results from the circuit
- [ ] Upload the results to the web interface/app

> The acoustic signal transmitted from the rocks are both at 40 kHz, therefore we just need to design a circuit specific for this frequency and detect if it is present from the rock sample. Then use other properties of the rocks (IR and radio) to determine the rock sample being analysed. 

Infrared:
- [x] Determine a suitable soln. to detect Infrared pulses
- [x] Determine a suitable sensor to detect Infrared pulses
- [x] Place order for the chosen sensor
- [x] Approve order for the chosen sensor
- [ ] Design circuit to detect IR pulse*
- [ ] Design circuit to amplify the IR pulse signal
- [ ] Analyse results from the circuit (determine the frequency of the pulse)
- [ ] Upload the results to the web interface/app

> The phototransistor is a light-controlled current source; we connect the phototransistor into Vcc and a load resistor and measure the voltage across the resistor. When measuring the IR pulse with the exorock shell, there is a "extremely" weak signal therefore we need to amplify the pulsed signal. Filtering may be required to remove the ambient IR that may interfere with the readings. We can then process the results using the digital pin on the Adafruit board and hopefully determine the frequency of the IR pulse and upload the results to the web interface/app.
