//
// Created by louis on 2024-01-22.
//

#ifndef UOSM_LIGHTS_LIGHTSDRIVER_H
#define UOSM_LIGHTS_LIGHTSDRIVER_H

#include "ApplicationTypes.h"
#define BLINK_DELAY 600 //Will blink a bit less than once every half second.

// TODO: Create getters and setters to access data
//Getters
flag_status_t getLeftTurnStatus();
flag_status_t getRightTurnStatus();
flag_status_t getHazardsStatus();
flag_status_t getHeadlightsStatus();
flag_status_t getBrakeLightsStatus();
flag_status_t getHighBeamsStatus();
flag_status_t getLowBeamsStatus();

//Setters
void setLightsStatus(uint32_t lights);
void setBrakesStatus(flag_status_t);

//Functions for front lights
void setLeftTurn(flag_status_t enabled);
void setRightTurn(flag_status_t enabled);
void setHazards(flag_status_t enabled);
void setHeadlights(flag_status_t enabled);
void setHighBeams(flag_status_t enabled);
void setLowBeams(flag_status_t enabled);

//Functions for brake lights
void setRunningLights();
void setBrakeLights();
#endif //UOSM_LIGHTS_LIGHTSDRIVER_H
