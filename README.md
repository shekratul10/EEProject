# Group 5/ASHB's EE Project 2022 

All important information is here:

**IMPORTANT NOTICES AS OF 05/06/22 14:14**
- Physical sensor circuits built on stripboards - reasoning here: https://github.com/shekratul10/EEProject/blob/main/Sensor/physical%20circuits.md
- Using two hall effect sensors might be better to detect the polarity of the magntic field => A proposed circuit has been uploaded, as well as component suggestions. All updated in the magnetic field section.
- A circuit to convert sinusoidal signals into square waves can be found here: [sinusoidal to digital conversion](https://github.com/shekratul10/EEProject/blob/main/Sensor/Sinusoidal%20to%20digital%20conversion.md)
- Code to determine the frequency of an analogue input on the Adafruit will be difficult to implement so it is suggested to use an op-amp comparator circuit and digital pin instead. Then all sensors can use the existing IR pulse code to determine the frequency of the signal, if required. Information here: https://www.electronics-tutorials.ws/opamp/op-amp-comparator.html 
- Avoid using inductors in circuits as their impedances **may** be affected by an external magnetic field
- Make component orders at https://apps.powerapps.com/play/30b4e212-d040-4203-98cc-882acb4edee0?tenantId=2b897507-ee8c-4575-830b-4f8267c3d307 if necessary
- **We should wear suits or other formal wear to the demo for 24/06/22**
- Be aware that digital pins 5,7 & 10 cannot be used on the Adafruit board
- A written report has been submitted, please view it here: [written report](https://github.com/shekratul10/EEProject/blob/main/Written%20report/IR%20sensing%20written%20report.docx)

**Here is a Gantt chart, which shows what section of the project should be complete for a set date so we can meet the project deadline ontime (19 June 2022)**

![EE Project Gantt Chart](https://user-images.githubusercontent.com/106095203/170874786-cc7f64eb-d050-46ae-aa13-25eecf843db8.png)

The following needs to be **accomplished** to meet our project goals:
- [x] Develop a circuit to detect acoustic signals and analyse the frequency
- [x] Develop a circuit to detect infrared pulses and analyse the pulse frequency
- [ ] Develop a circuit to detect magnetic field polarity and analyse the direction of the field
- [ ] Develop a circuit to detect radio waves, detect the carrier frequency, detect the modulating frequency and analyse these frequencies
- [ ] Establish motor control of the EEE Rover
- [ ] Establish a web interface to control the motion of the EEE Rover as well as display the data gathered from the sensors
- [ ] Consider CAD-based methods to improve the design of the EEE Rover
- [ ] Conduct testing for each sensor and motor control
- [ ] Produce a written report for each section, combine the reports and edit the combined document
- [ ] Review the combined written report for final adjustments
- [ ] Submit the final written report

## Useful information
Mineral properties:

<img width="623" alt="Screenshot 2022-05-27 at 12 43 34" src="https://user-images.githubusercontent.com/106095203/170692913-9280b7b0-e76c-451f-a7b8-0ea30aa6a381.png">
Exorock operating switches:

<img width="650" alt="Screenshot 2022-05-29 at 19 43 50" src="https://user-images.githubusercontent.com/106095203/170886613-d42fbb28-ed0c-472e-93cb-3d7952c586f6.png">

## Acoustic sensing
Resources have been moved here: [Ultrasound](https://github.com/shekratul10/EEProject/tree/main/Sensor/Ultrasound)
## IR Pulse sensing
Resources have been moved here: [IR Pulse](https://github.com/shekratul10/EEProject/tree/main/Sensor/IR%20Pulse)
## Magnetic field sensing
Resources have been moved here: [Magnetic field](https://github.com/shekratul10/EEProject/tree/main/Sensor/Magnetic%20field)
## Radio wave sensing
Resources have been moved here: [Radio Wave](https://github.com/shekratul10/EEProject/tree/main/Sensor/Radio%20Wave)
## Written Report
Resources have been moved here: [Written Report](https://github.com/shekratul10/EEProject/tree/main/Written%20report)
