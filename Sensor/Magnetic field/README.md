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

We could use the bipolar HS (DRV5053EAQLPGM) to detect if there is a magnetic field via analogue analysis. VQ is the "middle ground" between north and south poles, quoted with a value between 0.9-1.2 V as manufacturing tolerances. To detect a magnetic field we need to determine if the voltage from the bipolar analogue input is outside a certain voltage region e.g. 0.7 - 1.5 V then a magnetic field is detected. Datasheet for reference: https://www.ti.com/lit/ds/symlink/drv5053.pdf?HQS=dis-dk-null-digikeymode-dsf-pf-null-wwe&ts=1654186442426

We could use the unipolar HS (SS441R) to detect the polarity of the magnetic field. This produces a digital signal and responds in the presence of a South pole (0 for north and 1 for south). Will be used to determine the polarity of the field. Datasheet for reference: https://www.farnell.com/datasheets/2012747.pdf 

Here is some logic that can be implemented to determine the magnetic field polarity:

<img width="655" alt="Screenshot 2022-06-05 at 18 42 07" src="https://user-images.githubusercontent.com/106095203/172063273-21db719c-5d0a-4177-ab32-7a4530459b2b.png">

**I have heard that the pins on the hall effect sensor are rather delicate therefore two of each kind will be ordered.**

The ordered sensors:

Bipolar: https://onecall.farnell.com/texas-instruments/drv5053eaqlpgm/hall-effect-bipolar-to-92-3/dp/3124148

Unipolar: https://onecall.farnell.com/honeywell/ss441r/sensor-hall-effect-unipolar-to/dp/1784735 

Proposed circuit will HS: 

![circuit-2](https://user-images.githubusercontent.com/106095203/171848226-dc738b46-7dbd-4f10-a798-017f355e1281.png)

Resistor values have been chosen to ensure the current limits of the components are not reached, allowing for safe operation without damaging the components. 
