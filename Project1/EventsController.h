#pragma once
#include <iostream>
#include "IEvent.h"
#include "SpecificAction.h"
#include "AlarmEvent.h"
#include "ClockSchedulerEvent.h"
#include "ReminderSchedluerEvent.h"
#include "Configuration.h"
#include <vector>

class EventsController
{
public:
  EventsController();
  ~EventsController();

  void PushEvent(std::vector <IEvent*> *p_vector, IEvent *p_event);
  EEventType PeekCurrentEventType(std::vector <IEvent*> *p_vector);
  void PopEvent(std::vector <IEvent*> *p_vector);
  void checkScheduleToRun(std::vector <IEvent*> *p_vector);

  std::vector <IEvent*> eventsTest;
  std::vector <IEvent*> scheduledAction;
  
private:
  std::string GetEventName(EEventType p_event_type);
  void DisplayMessage(std::vector <IEvent*> *p_vector, IEvent * v_event, std::string message);
};