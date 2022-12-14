#pragma once
#include <iostream>
#include "IEvent.h"
#include "AsynchAction.h"
#include "AlarmEvent.h"
#include "ClockSynchEvent.h"
#include "ReminderSchedluerEvent.h"
#include "Configuration.h"
#include <vector>

class EventsController
{
public:
  EventsController();
  ~EventsController();

  void PushEvent(std::vector <IEvent*> *p_vector, IEvent *p_event);
  EEventType PeekCurrentAsynchEventType(std::vector <IEvent*> *p_vector);
  void PopEvent(std::vector <IEvent*> *p_vector);
  void checkSynchEvents(std::vector <IEvent*> *p_vector);

  std::vector <IEvent*> asynchronousEvents;
  std::vector <IEvent*> synchronousEvents;
  
private:
  std::string GetEventName(EEventType p_event_type);
  void DisplayMessage(std::vector <IEvent*> *p_vector, IEvent * v_event, std::string message);
};