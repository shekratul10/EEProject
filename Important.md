# 1st Year EE Project

Group 5/ASHB's Repository for the Electronics Design Project (Summer 2022)

**ATTENTION:** Try to avoid using inductors for circuits (excluding the air-cored inductor for radio wave detection) since they exhibit cataffi "undefined behaviour" when subjected to magnetic fields - we are detecting the presence of a magnetic field so it is possible that circuit with inductors to be affected. If you intend to use a second order filter, I suggest using a Sallen Key Filter/amplifier instead.

Rock properties:


<img width="623" alt="Screenshot 2022-05-27 at 12 43 34" src="https://user-images.githubusercontent.com/106095203/170692913-9280b7b0-e76c-451f-a7b8-0ea30aa6a381.png">


<img width="650" alt="Screenshot 2022-05-29 at 19 43 50" src="https://user-images.githubusercontent.com/106095203/170886613-d42fbb28-ed0c-472e-93cb-3d7952c586f6.png">



## To do:
(priorities indicated with ^, where more ^ represents a great priority) Also see the list at the bottom of this page.
- [ ] Magnetic field detection ^
- [ ] Acoustic signal detection ^^
- [x] ~~IR pulse detection~~ 
- [ ] Radio signal detection ^^^
- [ ] Motor control ^^^
- [ ] Web interface/app ^^^^
- [ ] CAD + new EEE Rover designs ^
- [ ] Recording the results of each sensor ^^^
- [ ] Written report for each section ^^^
- [ ] Combining the written reports of each sections ^^
- [ ] Editor reviews the combined reports ^
- [ ] Another editor proof-reads the changes ^
- [ ] Final testing of all functions
- [ ] Relax until the big day ^^^^^
- [ ] **24/06/22: All wear suits to the demo of the EEE Rover**

### UI:
- [ ] Create a prediction system that returns the rocks based on signal.
- [ ] Add graphics for rock predictions
- [ ] Add functionality for Graphs
- [ ] Once motor control team decides on movement mechanism add controls

### Magnetic:
Relocated!   

### Acoustic:
- [ ] Determine a suitable soln. to detect acoustic signals
- [x] Determine a suitable sensor to detect acoustic signals
- [x] Place order for the chosen sensor
- [ ] Approve order for the chosen sensor
- [ ] Design circuit to demodulate the signal from the chosen sensor
- [ ] Analyse results from the circuit
- [ ] Upload the results to the web interface/app

31/05/22: Using the HC-SR04 will not work according to Ed Stott. We will need to use an ultrasound transducer to detect the acoustic signal emitted from the mineral. 

<img width="810" alt="Screenshot 2022-05-31 at 11 58 52" src="https://user-images.githubusercontent.com/106095203/171158535-10306992-3bf4-40bc-8d6f-033c9e1feec1.png">

Ultrasound transducer information: https://en.wikipedia.org/wiki/Ultrasonic_transducer

Datasheet for proposed component:[Ultrasonic sensor.pdf](https://github.com/shekratul10/EEProject/files/8804788/Ultrasonic.sensor.pdf)

Use a transducer; converts ultrasound pulses into an AC signal, which we can analyse using the analogue pins on the adafruit to determine its frequency at 40 kHz. May need to use some amplification to the signal, but testing on ultrasound is not possible without the transducer. 


> The acoustic signal transmitted from the rocks are both at 40 kHz, therefore we just need to design a circuit specific for this frequency and detect if it is present from the rock sample. Then use other properties of the rocks (IR and radio) to determine the rock sample being analysed. 

Plan for acoustic processing
- [ ] Amplify the signal using an amplifier circuit similar to the one used in the IR pulse circuit and try to obtain an amplitude greater than 580 mV (since this is the voltage drop across the diodes available in the labs)
- [ ] Construct an envelope detector for the amplified signal (see similar notes as radio waves to determine the values0
- [ ] Feed the output of the envelope detector to an analogue input pin on the arduino/adafruit board
- [ ] Write some code that can determine the frequency of the analogue signal
- [ ] Compare the frequency of the signal with some parameters e.g. if the frequency is 40 kHz ± 3 kHz, return true for the detection of the acoustic signal. 

### Infrared:
Relocated!

### Radio wave:
Relocated!

### Resources
Number of pins used for sensors/analysis of signals: 4 Digital and 2 Analogue

### Design ideas
> Large wheels are better than the existing wheels that are provided with the EEE Bug. The wheels from the EE Bug are dogshit. Using larger wheels such as the ones that can be stolen from the robotic labs, are much better, provide additional height and look more heavy duty.

### Enhancing the durability of the EEE Rover  
Although we may have a functioning EEE Rover, we do not want it to break on the day of the oral so we should implement as many fail-safes as possible. For circuit analysing signals, use the shortest length wires as possible since this will minimise the amount of noise picked up in the signal and making the reading more accurate and consistent. Connections on the breadboard aren't the best so for each sensor circuit, perhaps build them on a separate board (I can't recall the name of the board but some of them are in the drawers at the entrance to the labs) and make the connections using soldering. Then we solder a wire from this board to the parent breadboard. We could use lower gauge wires for making connections between these sub-board to the breadboard to reduce the chances of the wires coming out of the breadboard slots. 
  
The chasis for the EEE Rover could wrap around the internal circuitry for functionality - this will protect the wires and components from dust and debris as well as restricting the movement of circuits and components and the EEE Rover moves. The chasis could include additonal mounting points for the breadboard and the sub-circuits so they can be secured into place and are less likely to come loose and rattle. 
  
Larger wheels will provide the EEE Rover with additional ground clearance, which can be useful when driving over smaller obstacles. The batteries for the EEE Bug are likely going to be on the bottom therefore we may need to consider making a protective plate that will prevent sharp objects from puncturing the batteries and preventing the EEE Rover from catching fire (as well as setting off the fire alarms). 
  
### Written report
Rough plan of what needs to be done for the written report:
  - [ ] Project Cover page
  - [ ] Table of contents/contents page for the written report
  - [ ] Information about the given problem as for context
  - [ ] Product specification
  - [ ] Gantt Chart (or equivalent planning roadmap)
  - [ ] Written reports for each section: magnetic sensor, IR sensor, radio sensor, acoustic sensor, web interface, motor control, CAD and other design changes etc.
  - [ ] Written report for integration of each sub-system with oneanother
  - [ ] Written report for test of functions
  - [ ] Assess the final product against the points given in the product specification
  - [ ] Evaluation of the project
  - [ ] References and sources at the end of the document with the appropriate referencing

  For specialist written report, there should be a similar structure between each
  - [ ] Heading for what section the report is about
  - [ ] Introduction to the problem given e.g. for magnetic we want to detect the presence of a magnetic field from an unknown rock sample
  - [ ] Suggest a soln. to the given problem with the help of the given sensor/component used
  - [ ] Background information about the component e.g. for magnetic we have gone for reed switch and a website has been included describing the workings of the reed switch (make sure to reference appropriately)
  - [ ] Suggest a suitable circuit and signal processing techniques to solve the problem e.g. for magnetic use a reed switch to send a voltage to a digital pin on the Adafruit board, where we can assess whether a magnetic field is detected with the use of boolean variables
  - [ ] Testing of the circuit and well as appropriate results e.g. for radio wave we can have oscilloscopes in labs detect the signal picked up by the air-cored inductor
  - [ ] Refinements and improvements to the circuit to improve performance and reliability, once again have appropriate results to show progression
  - [ ] For signal processing, whether done on Adafruit or elsewhere, explain what code does e.g. for IR pulse have an algorithm that determines the frequency of the pulsed signal and explain the parts of the code that allows us to determine the frequency
  - [ ] Testing of the overall system with pictures and diagrams to help explain the results and show that the implementation functions as intended. 
  - [ ] Have a final circuit schematic included in the document where necessary, where values of the components used e.g. a resistor used in reed switch circuit has a value of 10 kΩ or something similar
  - [ ] Referencing for research, concepts, similar circuits and code examples at the end of the specialist written report. This should be easy for the editor of the written report to find the references and merge all references across all of the written reports at the end of the document.
  
### Gantt chart
  This is a chart that shows what tasks need to be done during a project, including the time it should be start as well as the time it should be finished by. This can be done easily in Mircosoft Excel, but other software can be used for making this chart. This will allow us to represent the planning stages of the project in the written report as well as use it to determine when deadlines should be met and which tasks we should prioritise for completion. 
  
### Product Specification
  The talk was pretty shit. Essentially we, as a group, must come up with a set of criteria that our finished EEE Rover must satisfy in order for it to be successful. Each point needs to be concise and relevant to the project. These goals are what we will be working towards throughout the duration of the project. These goals are not fixed; they provide a baseline of what we need to accomplish in the project but we can change any of the product specification points if needed if we find out a point is not concise enough or not providing the restrictions we require. This will be useful in the evaluation of the project since we can look back our product specification and determine if our final product satisfy our points, which will determine whether the project was successful or not. The journey is worth more than the end product so don't change the product specification just to satisfy the objective that couldn't be achieved with the old point(s). That is the purpose of an evaluation. 
  

