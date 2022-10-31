#pragma once
#include <iostream>
#include "EventsController.h"
#include "SpecificAction.h"

enum struct EMachineState : uint8_t
{
  UNKNOWN = 0,
  INITIALIZATION,
  INITIALIZATION_DONE,
  SPECIFIC_ACTION,
  SPECIFIC_ACTION_DONE,
  PRE_RUNNING,
  RUNNING,
  ERROR,
  STATES_COUNT
};

class Machine
{
public:
  Machine();
  ~Machine() = default;
  void machineSpin();
private:
   
    void MachineSetState(EMachineState p_state);
    EMachineState MachineGetState(void);

    EMachineState m_machine_state;
    //uint32_t g_current_millis = millis();
    std::string m_machine_state_strings[(uint8_t)EMachineState::STATES_COUNT];
    EventsController m_events{};
    //SpecificAction specificAction{};
};