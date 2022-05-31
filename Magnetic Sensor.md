** Magnetic field detecting sensor **

- [x] Determine a suitable soln. to detect magnetic field
- [x] Determine a suitable sensor to detect magnetic field
- [x] Place order for the chosen sensor
- [x] Approve order for the chosen sensor
- [ ] Design circuit to detect magnetic field
- [ ] Analyse results from the circuit
- [ ] Upload the results to the web interface/app

A reed switch is a switch activated by an external magnetic field - we can use a digital pin on the Adafruit to analyse the result and report true or false
depending on if the switch has closed or not. 

Information for writing report on reed switch: https://uk.rs-online.com/web/generalDisplay.html?id=ideas-and-advice/reed-switches-guide. 

Order has been placed for two reed switches. [Data sheet attached][Reed switch datasheet.pdf]
(https://github.com/shekratul10/EEProject/files/8786346/Reed.switch.datasheet.pdf)
Just like a regular switch, activated by an external magnetic force -> can use a digital pin on the Adafruit and report true/false if a signal is received at the corresponding pin. Detects just the presence of a magnetic field detected from the rock. Since the polarity of the rock (one of the six) is not given, require two reed switches to detect north and south magnetic poles. May use two digital pins. Then use the data from the table above to determine the rocks correctly. We expect this to be complete within 1-2 days of the Reed switches being delivered. 

A proposed circuit diagram:

![Reed switch example circuit](https://user-images.githubusercontent.com/106095203/171034722-02680c6b-d5df-4026-82c3-d38e3c634189.png)

Although an Arduino is shown in this circuit schematic, the pin layout is exactly the same as the ones with the Adafruit Metro M0 express board. Any digital pin could be used for this application.

We need to detect a magnetic field up and down so we will require two of these circuits. We could use two separate digital pins one for detecting the field up and one for detecting the field down just to keep things simple, but if you see a better/more efficient soln. then go ahead and make changes to this section in Important.md. 

As a digital signal, the input will either be low and high and reporting the detection of the field's direction can be easy with the use of basic boolean operators.  
