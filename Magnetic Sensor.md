## Magnetic field detecting sensor

- [x] Determine a suitable soln. to detect magnetic field
- [x] Determine a suitable sensor to detect magnetic field
- [x] Place order for the chosen sensor
- [x] Approve order for the chosen sensor
- [x] Design circuit to detect magnetic field
- [ ] Analyse results from the circuit
- [ ] Upload the results to the web interface/app

A reed switch is a switch activated by an external magnetic field - we can use a digital pin on the Adafruit to analyse the result and report true or false depending on if the switch has closed or not. We are required to determine the polarity of the magnetic field produced by the mineral so we will need two reed switches to detect the north and south magnetic poles. We could use two digital pins to analyse the signal from each reed switch. Here is a proposed circuit diagram:

![Reed switch example circuit](https://user-images.githubusercontent.com/106095203/171034722-02680c6b-d5df-4026-82c3-d38e3c634189.png)

Although the connected digital pin in the diagram is pin 7 on the Arduino, we could use any digital pin to report the results of the magnetic field circuit.

### Hints for written report
Here is some information about how a reed switch works:https://uk.rs-online.com/web/generalDisplay.html?id=ideas-and-advice/reed-switches-guide. 
And here is the data sheet of the reed switch components we have used:https://github.com/shekratul10/EEProject/files/8786346/Reed.switch.datasheet.pdf

