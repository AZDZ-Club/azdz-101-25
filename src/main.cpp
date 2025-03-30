#include <Arduino.h>

// just my preference, no need
typedef int Pin;
typedef int Signal;
typedef unsigned long Milliseconds;

// main road LEDs
const Pin R_DA = 13;
const Pin Y_DA = 12;
const Pin G_DA = 11;

// THD-Zentrum Road LEDs
const Pin R_TZ = 7;
const Pin Y_TZ = 6;
const Pin G_TZ = 5;

// Wait Duration Def-n
const Milliseconds GO_WAIT_TIME = 8000;
const Milliseconds WARN_WAIT_TIME = 5000;

enum State
{
  DA_GO,
  DA_WARN,
  TZ_GO,
  TZ_WARN,
};

typedef struct
{
  Signal R_DA;
  Signal Y_DA;
  Signal G_DA;

  Signal R_TZ;
  Signal Y_TZ;
  Signal G_TZ;

  Milliseconds Wait_Duration;
} Output;


/**
 * Following function calculates what is the next state based on the current state
 * this is a pure function, but doesn't have to be. i just like pure functions for the state managements
 */
State state_machine(State current_state)
{
  switch (current_state)
  {
  case DA_GO:
    return DA_WARN;
  case DA_WARN:
    return TZ_GO;
  case TZ_GO:
    return TZ_WARN;
  case TZ_WARN:
    return DA_GO;
  default:
    break;
  }
}

/**
 * Following function calculates the output based on the current state.
 * We are passing in @type Output as a reference, to save some stack space.
 * Size of this program is very small, but it is a good practice. 
 */
void calc_output(Output *output, State curr_state)
{
  // sanitization, keeps the switching below simple
  output->R_DA = LOW;
  output->Y_DA = LOW;
  output->G_DA = LOW;

  output->R_TZ = LOW;
  output->Y_TZ = LOW;
  output->G_TZ = LOW;

  // since we sanitized above, we only turn on the signals we need
  switch (curr_state)
  {
  case DA_GO:
    output->G_DA = HIGH;
    output->R_TZ = HIGH;
    output->Wait_Duration = GO_WAIT_TIME;
    break;

  case DA_WARN:
    output->Y_DA = HIGH;
    output->R_TZ = HIGH;
    output->Wait_Duration = WARN_WAIT_TIME;
    break;

  case TZ_GO:
    output->G_TZ = HIGH;
    output->R_DA = HIGH;
    output->Wait_Duration = GO_WAIT_TIME;
    break;

  case TZ_WARN:
    output->Y_TZ = HIGH;
    output->R_DA = HIGH;
    output->Wait_Duration = WARN_WAIT_TIME;
    break;
  }
}

/**
 * Following function updates the registers to change the circuit states.
 * As i already said above, i like to keep the state management without side effects.
 * 
 * Otherwise, we can reduce the source by doing all of these in state_machine function.
 */
void update_output(Output *output)
{
  // main Road
  digitalWrite(R_DA, output->R_DA);
  digitalWrite(Y_DA, output->Y_DA);
  digitalWrite(G_DA, output->G_DA);

  // THD-Zentrum Road
  digitalWrite(R_TZ, output->R_TZ);
  digitalWrite(Y_TZ, output->Y_TZ);
  digitalWrite(G_TZ, output->G_TZ);
}

// some global variables; not a good practice, but i like it this way
State current_state = DA_GO;
Output next_output = {
    .R_DA = LOW,
    .Y_DA = LOW,
    .G_DA = HIGH,

    .R_TZ = HIGH,
    .Y_TZ = LOW,
    .G_TZ = LOW,

    .Wait_Duration = GO_WAIT_TIME,
};

void setup()
{
  pinMode(R_DA, OUTPUT);
  pinMode(Y_DA, OUTPUT);
  pinMode(G_DA, OUTPUT);
  pinMode(R_TZ, OUTPUT);
  pinMode(Y_TZ, OUTPUT);
  pinMode(G_TZ, OUTPUT);

  // we go to the RESET position.
  current_state = DA_GO;
  calc_output(&next_output, current_state);
  update_output(&next_output);
}

void loop()
{
  delay(next_output.Wait_Duration);
  current_state = state_machine(current_state);
  calc_output(&next_output, current_state);
  update_output(&next_output);
}
