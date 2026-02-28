/*
 * Front Lights Pin configuration
 * Author: Dan Shan
 * Created: Feb 27, 2026
 *
 * Pins from the diagram
 * RunningLightsR: D1/PA9
 * RunningLightsG: D0/PA10
 * RunningLightB: D10/PA11
 * HeadlightsLow / LowBeams: D9/PA8
 * HeadlightsHigh / High beams: A0/PA0
 * LeftTurn: D11/PB5
 * RightTurn: D12/PB4
*/

#ifndef UOSM_LIGHTS_PINS_H
#define UOSM_LIGHTS_PINS_H

// Running lights
#define RunningLightsR_port GPIOA
#define RunningLightsR_pin GPIO_PIN_9

#define RunningLightsG_port GPIOA
#define RunningLightsG_pin GPIO_PIN_10

#define RunningLightsB_port GPIOA
#define RunningLightsB_pin GPIO_PIN_11

// Headlights
#define HeadlightsLow_port GPIOA
#define HeadlightsLow_pin GPIO_PIN_8

#define HeadlightsHigh_port GPIOA
#define HeadlightsHigh_pin GPIO_PIN_0

// Turn Signals
#define LeftTurn_port GPIOB
#define LeftTurn_pin GPIO_PIN_5

#define RightTurn_port GPIOB
#define RightTurn_pin GPIO_PIN_4

#endif