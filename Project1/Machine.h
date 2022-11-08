#pragma once
#include <iostream>
#include "EventsController.h"
#include "MachineStateController.h"
//#include "AsynchAction.h"

class Machine
{
public:
  Machine();
  ~Machine();
  void Control();
private:
  void Init();
  
  MachineStateController machineStateController{};
  EventsController m_events{};
  IEvent* specificEvent = new AsynchAction{};
  IEvent* alarmEvent = new AlarmEvent{};
  IEvent* clockSchedulerEvent = new ClockSynchEvent{clock_cycle_time};
  IEvent* reminderSchedulerEvent = new ReminderSchedluerEvent{reminder_cycle_time};

private:
  static constexpr int16_t clock_cycle_time = 5;
  static constexpr int16_t reminder_cycle_time = 9;
};