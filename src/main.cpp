#include <Arduino.h>

typedef int Pin;

const Pin R_DA = 13;
const Pin Y_DA = 12;
const Pin G_DA = 11;

const Pin R_TZ = 7;
const Pin Y_TZ = 6;
const Pin G_TZ = 5;

// const Pin P = 13;

void setup() {
  pinMode(R_DA, OUTPUT);
  pinMode(Y_DA, OUTPUT);
  pinMode(G_DA, OUTPUT);
  pinMode(R_TZ, OUTPUT);
  pinMode(Y_TZ, OUTPUT);
  pinMode(G_TZ, OUTPUT);
  // pinMode(P, INPUT_PULLDOWN);
}

void loop() {
  digitalWrite(R_DA, HIGH);
  digitalWrite(Y_DA, HIGH);
  digitalWrite(G_DA, HIGH);
  digitalWrite(R_TZ, HIGH);
  digitalWrite(Y_TZ , HIGH);
  digitalWrite(G_TZ, HIGH);

  delay(800);

  digitalWrite(R_DA, LOW);
  digitalWrite(Y_DA, LOW);
  digitalWrite(G_DA, LOW);
  digitalWrite(R_TZ, LOW);
  digitalWrite(Y_TZ , LOW);
  digitalWrite(G_TZ, LOW);

  delay(500);
}

