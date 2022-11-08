#include <iostream>
#include <list>

enum MachineStateEnum
{
    INITIALIZATION,
    READY,
    RUNNING,
    ERROR,
    MACHINE_STATE_ENUM_GUARD
};
class MachineStateController
{
public:
    MachineStateController();
    ~MachineStateController()=default;

    bool trySetState(MachineStateEnum p_machineState);
    MachineStateEnum GetState();
    MachineStateEnum m_machineState{MachineStateEnum::INITIALIZATION};
    bool m_allowedTransitions[MACHINE_STATE_ENUM_GUARD][MACHINE_STATE_ENUM_GUARD];
};