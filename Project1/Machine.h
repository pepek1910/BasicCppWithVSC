#pragma once
#include <iostream>
#include "EventsController.h"
#include "MachineStateController.h"
//#include "AsynchAction.h"

enum struct EMachineState : uint8_t //TODO
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
  ~Machine();
  void machineSpin();
private:
    MachineStateController machineStateController{};
    //uint32_t g_current_millis = millis();
    std::string m_machine_state_strings[(uint8_t)EMachineState::STATES_COUNT];
    EventsController m_events{};

    IEvent* specificEvent = new AsynchAction{};
    IEvent* alarmEvent = new AlarmEvent{};
    IEvent* clockSchedulerEvent = new ClockSynchEvent{clock_cycle_time};
    IEvent* reminderSchedulerEvent = new ReminderSchedluerEvent{reminder_cycle_time};

private:
  static constexpr int16_t clock_cycle_time = 5;
  static constexpr int16_t reminder_cycle_time = 9;
};