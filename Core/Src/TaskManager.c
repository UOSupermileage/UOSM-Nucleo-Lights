//
// Created by louis on 2024-01-22.
// Blink logic from: https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay/
// Due to resource constraints, we are not using FreeRTOS for this project
//

#include "TaskManager.h"
#include "MCP251XFD.h"
#include "network.h"
#include "UOSMCoreConfig.h"
#include "InternalCommsModule.h"
#include "LightsDriver.h"
#include "pins.h"
#include "ApplicationTypes.h"
#include "SerialDebugDriver.h"

extern SPI_HandleTypeDef hspi1;

_Noreturn void RunTaskManager(void) {
    // Initialize CAN
    // MCP251FXD requires 3ms to warm up
    HAL_Delay(100);

    printf("Initializing CAN\n");

    int init_status = CAN_Init();
    DebugPrint("CAN Init status: %d", init_status);

    //DebugPrint("%d", hspi1.Instance);

    // Initialize MCP
    // MCP2515_CS_HIGH();

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

    flag_status_t blink;
    uint32_t blink_delay = BLINK_DELAY; // Blink interval in milliseconds

    uint32_t current_time = HAL_GetTick();
    uint32_t previous_time = 0;
    while (1) {
        // Check for CAN messages
        CAN_Receive();
        // CAN_Send();
        // SerialPrintln("pomme");

        // // TODO: Actuate Lights based off of state in LightsDriver
        // current_time = HAL_GetTick();
        //
        // // Code for front lights
        // if (getHazardsStatus() == Set) {
        //     setHazards(blink == Set);
        // } else {
        //     setLeftTurn(getLeftTurnStatus() == Set && blink == Set);
        //     setRightTurn(getRightTurnStatus() == Set && blink == Set);
        // }
        //
        // setHighBeams(getHighBeamsStatus() == Set);
        // setLowBeams(getLowBeamsStatus() == Set);
        //
        // setRunningLights();
        // // setBrakeLights(); // N/A
        //
        // //Update blink flag
        // if (current_time - previous_time >= blink_delay) {
        //     previous_time = current_time;
        //     if (blink == Set) {
        //         blink = Clear;
        //     } else {
        //         blink = Set;
        //     }
        // }
    }
}