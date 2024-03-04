# Rock-Paper-Scissor-Game

This Project is a rock paper scissor game. I have used three servo motors interfaced with ultrasonic sensor and buzzer and led. microcontroller I used is Arduino Nano. Whenver you put your hand in front of Arduino Uno , any servvo motor will randomly move Upward at a time. So it will act like you are playing rock, paper and  Scissor game with the setup.

How to assemble setup?
1. Connect trigger pin of ultrasonic sensor to digital pin 9 of arduino uno.
2. Connect echo pin of ultrasonic sensor to digital pin 10 of arduino uno.
3. connect vcc pin to 5v and gnd pin to gnd of arduino.
4. connect sigmal pin of three servo motors to pin 5,6 and 3 respectively of uno.
5. connect led to pin 8
6. connect buzzer to pin 11
7. connect vcc and gnd of servos to 5v and gnd of uno. You can use breadbaord because in arduino you are having 3 gnd pins and 1 5v pin.
8. Go to Arduino IDE
9. connect arduino cable.
10. Select board Arduino uno-->port(arduino uno)
11. upload the code.

Note: Sometimes we find problem in uploading the code, In such case go to device manager-->selsct port-->Click on USB Port-->go to portsetting-->click on advanced-->enable the port by click on second checkbox.
