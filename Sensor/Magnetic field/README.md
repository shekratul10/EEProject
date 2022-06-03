## Magnetic field detecting sensor

- [x] Determine a suitable soln. to detect magnetic field
- [x] Determine a suitable sensor to detect magnetic field
- [x] Place order for the chosen sensor
- [x] Approve order for the chosen sensor
- [x] Design circuit to detect magnetic field
- [ ] Analyse results from the circuit
- [ ] Upload the results to the web interface/app

**Use of a hall effect sensor may be better instead.**
The circuit required to detect the magntic field is easier to implement when considering the two poles that need to be analysed. Information for reed switching will remain here until we have a better idea of which sensor is better for this purpose. Example circuit: https://circuitdigest.com/electronic-circuits/magnetic-polarity-detector-circuit-using-hall-sensor. Here are resources for using the hall effect sensor instead: https://www.electronics-tutorials.ws/electromagnetism/hall-effect.html , https://uk.rs-online.com/web/generalDisplay.html?id=ideas-and-advice/hall-effect-sensors-guide.

If we intend to provide a solution using a hall sensor, then we are interested in the bipolar hall sensor that will "switch on" in response to one pole and will "switch off" in response to the other pole. The sensor reamins in its present state (either on or off) without a magnetic field, like a flip-flop of magnetism. Idea from: https://www.rfwireless-world.com/Terminology/Unipolar-hall-sensor-vs-Bipolar-hall-sensor-vs-Omnipolar-hall-sensor.html . 

We could use a unipolar hall sensor for detecting the general presence of a magnetic field and then use a bipolar hall sesnsor to determine the direction of the field. Can construct a truth table for this if this improves understanding. This is better than just using two bipolar hall sensor since you need to be able to determine the change in one hall sensor's signal, while the other remains the same meaning you will have two inputs on the same level (they're digital) so unless you are able to code a memory storing feature into the code, using a bipolar and unipolar hall sensor will be more efficient and take up the same number of digital pins as the read switch. 

![Screenshot 2022-06-03 at 12 11 17](https://user-images.githubusercontent.com/106095203/171843051-7bf609bd-7622-4e34-9223-2bce74ee30bd.png)

**I have heard that the pins on the hall effect sensor are rather delicate therefore two of each kind will be ordered.**

The ordered sensors:

Bipolar: https://onecall.farnell.com/texas-instruments/drv5053eaqlpgm/hall-effect-bipolar-to-92-3/dp/3124148
Unipolar: https://onecall.farnell.com/honeywell/ss441r/sensor-hall-effect-unipolar-to/dp/1784735 

Data sheets for each of the ordered sensors can be reviewed by clicking on the links. 
https://www.ti.com/lit/ds/symlink/drv5053.pdf?HQS=dis-dk-null-digikeymode-dsf-pf-null-wwe&ts=1654186442426 

**Information for the implementation with the reed switch**
A reed switch is a switch activated by an external magnetic field - we can use a digital pin on the Adafruit to analyse the result and report true or false depending on if the switch has closed or not. We are required to determine the polarity of the magnetic field produced by the mineral so we will need two reed switches to detect the north and south magnetic poles. We could use two digital pins to analyse the signal from each reed switch. Here is a proposed circuit diagram:

![Reed switch example circuit](https://user-images.githubusercontent.com/106095203/171034722-02680c6b-d5df-4026-82c3-d38e3c634189.png)

Although the connected digital pin in the diagram is pin 7 on the Arduino, we could use any digital pin to report the results of the magnetic field circuit.

### Hints for written report
Here is some information about how a reed switch works: https://uk.rs-online.com/web/generalDisplay.html?id=ideas-and-advice/reed-switches-guide. 
And here is the data sheet of the reed switch components we have used: https://github.com/shekratul10/EEProject/files/8786346/Reed.switch.datasheet.pdf

