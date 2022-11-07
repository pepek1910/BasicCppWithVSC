#pragma once
#include <iostream>
#include "AsynchroTask.h"
#include "SpecificAction.h"
#include "AlarmEvent.h"
#include "ClockSchedulerEvent.h"
#include "ReminderSchedulerEvent.h"
#include "Configuration.h"
#include <vector>

class EventsController
{
public:
  EventsController();
  ~EventsController();
  /*
  TODO add MachineState and add function eventAvailable - which check if this event is available in current state
    add arr_available_state - add in IEvent
  TODO make type for PeekCurrentEventType and checkScheduleToRun, depends on 
  
  TODO add to event - states in which it is available !
  */
  void PushEvent(std::vector <AsynchroTask*> *p_vector, AsynchroTask *p_event);
  EEventType PeekCurrentEventType(std::vector <AsynchroTask*> *p_vector);
  void PopEvent(std::vector <AsynchroTask*> *p_vector);
  void checkScheduleToRun(std::vector <AsynchroTask*> *p_vector);

  std::vector <AsynchroTask*> eventsTest;
  std::vector <AsynchroTask*> scheduledAction;

private:
  std::string GetEventName(EEventType p_event_type);
  void DisplayMessage(std::vector <AsynchroTask*> *p_vector, AsynchroTask * v_event, std::string message);
};