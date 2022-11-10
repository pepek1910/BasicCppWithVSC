#pragma once
#include <iostream>
#include "StateController.h"

class ResetController
{
public:
    ResetController(StateController p_stateController): m_stateController{p_stateController}{};
    ~ResetController()=default;

    void Control(){if(m_resetTrigger) m_stateController.trySetState(MachineStateEnum::RESETTING);};
private:
    StateController m_stateController;
    bool m_resetTrigger{false};

};