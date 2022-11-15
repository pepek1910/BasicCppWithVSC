#pragma once
#include <iostream>
#include "EventsController.h"
#include "StateController.h"
#include "ResetController.h"
#include "TestObject.h"
#include "ErrorChecker.h"

class Machine
{
public:
  Machine(ErrorChecker* m_error_checker);
  ~Machine();
  void Control();
private:
  void Init();
  void Reset();
  
  ErrorChecker* m_error_checker{};
  StateController stateController{};
  ResetController resetController{stateController};
  EventsController m_events{};
  IEvent* specificEvent = new AsynchAction{};
  IEvent* alarmEvent = new AlarmEvent{};
  IEvent* clockSchedulerEvent = new ClockSynchEvent{clock_cycle_time};
  IEvent* reminderSchedulerEvent = new ReminderSchedluerEvent{reminder_cycle_time};
  TestObject* m_test_object = new TestObject{m_error_checker, "Test Object"};

  uint8_t m_resetState{0};
private:
  static constexpr int16_t clock_cycle_time = 5;
  static constexpr int16_t reminder_cycle_time = 9;
};