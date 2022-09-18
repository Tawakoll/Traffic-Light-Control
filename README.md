# Traffic-Light-Control
This is a project done as a part of Udacity Embedded systems nano degree
Project files includes software drivers, application flow and design and the proteus simulation for the traffic control

Program runs as a normal traffic light : green , yellow blink, then red but at any time a pedestrian can interrupt this flow (press a button ) and 
it will activate pedestrian mode which gives priority for pedestrians to cross green light!.

It contains the following drivers :
  1- Avr full timer driver (timer0, timer1,timer2) that can work in CTC (compare mode ) or Normal overflow mode with a call back function when entering an interrupt for overflow or compare match.
  2- An external interrupt driver which can enable int0, int1,in2 interrupts with a call back function.
  3- GPIO driver , for this GPIO driver simply each pin is initialized at a time can add modifications to make it better later for example initializing ports at a time
  can save some time if you are capable by writing a certain decimal, hex , or binary number to the port. Same applies to reading and writing from ports.

It contains application which dictates the application's flow according to the program explained above, and the main simply runs the application!
if you have any questions please hit me up at linkedin or my email ! Thank you for reading :)
