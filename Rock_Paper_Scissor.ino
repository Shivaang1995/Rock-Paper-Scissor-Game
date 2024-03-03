#include <Servo.h>

#define TRIG_PIN 9
#define ECHO_PIN 10
#define SERVO_ROCK_PIN 5
#define SERVO_PAPER_PIN 6
#define SERVO_SCISSORS_PIN 3
int led = 8;
int buzzer = 11;
int pos = 0;

Servo servoRock;
Servo servoPaper;
Servo servoScissors;

void setup() {
  Serial.begin(9600);
 
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);

  servoRock.attach(SERVO_ROCK_PIN);
  servoPaper.attach(SERVO_PAPER_PIN);
  servoScissors.attach(SERVO_SCISSORS_PIN);
 
  digitalWrite(led, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
}

void loop() {
  long duration, distance;
 
  // Trigger ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
 
  // Read the echo pulse duration
  duration = pulseIn(ECHO_PIN, HIGH);
 
  // Calculate the distance
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if someone is within 15 cm range
  if (distance < 15) {
    // Someone is in range, play the game
    playGame();
  }

  delay(1000); // Adjust delay as needed
}

void playGame() {
  int randomChoice = random(3); // Generate a random number between 0 and 2

  // Move the servo motor based on the random choice
  if (randomChoice == 0) {
    // Rock
    moveServo(servoRock);
  } else if (randomChoice == 1) {
    // Paper
    moveServo(servoPaper);
  } else {
    // Scissors
    moveServo(servoScissors);
  }

  delay(100); // Adjust delay as needed
}

void moveServo(Servo &servo) {
  int angle = pos; // Set the desired angle (adjust as needed)
  delay(1000);
  servo.write(90);
  delay(1000);
  servo.write(pos);
}
