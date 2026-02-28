#include <sys/cdefs.h>
//
// Created by louis on 2024-01-22.
//

#ifndef UOSM_LIGHTS_TASKMANAGER_H
#define UOSM_LIGHTS_TASKMANAGER_H

#include "ApplicationTypes.h"




//
//
//
//typedef union {
//    uint16_t all;
//    struct {
//        uint16_t brightness: 7;
//
//    };
//};
//
//
//
//typedef union {
//    uint32_t all;
//    struct {
//        uint32_t brakes:1;
//        uint32_t rightTurn:1;
//        uint32_t hazard:1;
//        uint32_t leftTurn:1;
//        uint32_t highBeams:1;
//        uint32_t lowBeams:1;
//    };
//} lights_state_t;
//
//typedef union {
//    uint32_t all;
//    struct {
//        uint32_t red:8;
//        uint32_t green:8;
//        uint32_t blue:8;
//    };
//} rgb_t;

_Noreturn void RunTaskManager(void);

#endif //UOSM_LIGHTS_TASKMANAGER_H
