//
// Created by louis on 2024-01-22.
// Blink logic from: https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay/
// Due to resource constraints, we are not using FreeRTOS for this project
//

#include "TaskManager.h"
#include "UOSMCoreConfig.h"
#include "InternalCommsModule.h"
#include "LightsDriver.h"
#include "pins.h"

_Noreturn void RunTaskManager(void) {
    //Initialize MCP
    MCP2515_CS_HIGH();

    // Initialize CAN
    IComms_Init();

    flag_status_t blink;
    uint32_t blink_delay = BLINK_DELAY; //Blink interval in milliseconds

    uint32_t current_time = HAL_GetTick();
    uint32_t previous_time = 0;
    while (1) {
        // Check for CAN messages
        IComms_PeriodicReceive();

        // TODO: Actuate Lights based off of state in LightsDriver
        current_time = HAL_GetTick();

        // Code for front lights
        if (getHazardsStatus() == Set) {
            setHazards(blink == Set);
        } else {
            setLeftTurn(getLeftTurnStatus() == Set && blink == Set);
            setRightTurn(getRightTurnStatus() == Set && blink == Set);
        }

        setHighBeams(getHighBeamsStatus() == Set);
        setLowBeams(getLowBeamsStatus() == Set);

        setRunningLights();
        setBrakeLights();

        //Update blink flag
        if (current_time - previous_time >= blink_delay) {
            previous_time = current_time;
            if (blink == Set) {
                blink = Clear;
            } else {
                blink = Set;
            }
        }
    }
}