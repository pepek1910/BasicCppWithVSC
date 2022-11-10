#pragma once
#include <iostream>
#include <list>

enum MachineStateEnum
{
    INITIALIZATION,
    READY,
    RUNNING,
    ERROR,
    RESETTING,
    FATAL_ERROR,
    MACHINE_STATE_ENUM_GUARD
};

class StateController
{
public:
    StateController();
    ~StateController()=default;

    bool trySetState(MachineStateEnum p_machineState);
    MachineStateEnum GetState();
    MachineStateEnum m_machineState{MachineStateEnum::INITIALIZATION};
    bool m_allowedTransitions[MachineStateEnum::MACHINE_STATE_ENUM_GUARD][MachineStateEnum::MACHINE_STATE_ENUM_GUARD];
};