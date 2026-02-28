#include "ApplicationTypes.h"
#include "LightsDriver.h"

void LightsDataCallback(iCommsMessage_t *msg){
    DebugPrint("Lights CAN Message Received\n");
    uint32_t message = 0;
    message |= (uint32_t) msg->data[0] << 24;
    message |= (uint32_t) msg->data[1] << 16;
    message |= (uint32_t) msg->data[2] << 8;
    message |= (uint32_t) msg->data[3];

    setLightsStatus(message);
    if (getLeftTurnStatus()) {
        DebugPrint("Left Light CAN\n");
    }

    if (getRightTurnStatus()) {
        DebugPrint("Right Light CAN\n");
    }

    if (getHazardsStatus()) {
        DebugPrint("Hazards CAN\n");
    }

    if (getBrakeLightsStatus()) {
        DebugPrint("Brake Lights CAN \n");
    }

    if (getHighBeamsStatus()) {
        DebugPrint("High Beams CAN \n");
    }

    if (getLowBeamsStatus()) {
        DebugPrint("Low Beams CAN \n");
    }

}

void EventDataCallback(iCommsMessage_t *msg) {
    DebugPrint("Event CAN Message Received\n");
    // if (msg->dataLength == CANMessageLookUpTable[EVENT_DATA_ID].numberOfBytes) {
    //     EventCode code = msg->data[1];
    //     flag_status_t status = msg->data[0];
    //
    //     if(code == BRAKES_ENABLED) {
    //         setBrakesStatus(status);
    //     }
    // }
}

// Lights doesn't need most of the callbacks
extern void ThrottleDataCallback(iCommsMessage_t *msg){}
extern void ErrorDataCallback(iCommsMessage_t *msg){}
extern void SpeedDataCallback(iCommsMessage_t *msg){}
extern void MotorRPMDataCallback(iCommsMessage_t *msg){}
extern void CurrentVoltageDataCallback(iCommsMessage_t *msg){}
extern void PressureTemperatureDataCallback(iCommsMessage_t *msg){}
extern void EfficiencyDataCallback(iCommsMessage_t *msg){}
extern void MotorTemperatureDataCallback(iCommsMessage_t *msg){}