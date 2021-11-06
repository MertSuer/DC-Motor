#include <X113647Stepper.h>
static const int STEPS_PER_REVOLUTION = 32 * 32;
static const int STEPS_PER_REVOLUTION1 = 32 * 32;
static const int STEPS_PER_REVOLUTION2 = 32 * 32;
X113647Stepper myStepper(STEPS_PER_REVOLUTION, 8, 9, 10, 11);
X113647Stepper myStepper1(STEPS_PER_REVOLUTION1, 31, 33, 35, 37);
X113647Stepper myStepper2(STEPS_PER_REVOLUTION2, 38, 40, 42, 44);
char data;
void setup() {
  myStepper.setSpeed(600);
  myStepper1.setSpeed(600);
  myStepper2.setSpeed(600);
  Serial.begin(9600);
}
void salon_acma() {

  myStepper.step(STEPS_PER_REVOLUTION);
}
void salon_kapatma() {
  myStepper.step(-STEPS_PER_REVOLUTION);
  delay(500);
}
void garaj_acma() {

  myStepper1.step(STEPS_PER_REVOLUTION1);
}
void garaj_kapatma() {
  myStepper1.step(-STEPS_PER_REVOLUTION1);
  delay(500);
}
void salon_acma1() {

  myStepper2.step(STEPS_PER_REVOLUTION);
}
void salon_kapatma1() {
  myStepper2.step(-STEPS_PER_REVOLUTION);
  delay(500);
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();
    Serial.print(data);
    Serial.print("\n");
    if (data == '1') {
      salon_acma();
    }
    else if (data == '0') {
      salon_kapatma();
    }
    else if (data == '2') {
      garaj_acma();
    }
    else if (data == '3') {
      garaj_kapatma();
    }
    else if (data == '4') {
      salon_acma1();
    }
    else if (data == '5') {
      salon_kapatma1();
    }
  }
}
