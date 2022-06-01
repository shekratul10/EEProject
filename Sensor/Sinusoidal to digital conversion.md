Analysis of analogue inputs by the Adafruit will be difficult and time consuming, instead use an op-amp comparator to convert the sinusoidal signal input a digital pulse, then we can determine the frequency of the signal. It comes with the added bonus of reusing a lot of the code that we used to sense IR pulses, just adjusting the parameters of the boolean expressions. 

An op-amp comparator is shown here:

![circuit](https://user-images.githubusercontent.com/106095203/171500721-e2a9826f-c0c6-4053-9e26-e292bba9738c.png)

A 3.3V supply rail is used for the +Vcc since this represents the maximum voltage for our digital signal, 3.3V and this is also the maximum logic level that can be accepted by the Adafruit without damaging the board. The -Vcc is GND, representing the minimum logic level that the Adafruit can accept.

More information can be found here: https://www.electronics-tutorials.ws/opamp/op-amp-comparator.html 
