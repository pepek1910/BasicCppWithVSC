#pragma once
#include <iostream>
#include "IEvent.h"
#include "SpecificAction.h"
#include "AlarmEvent.h"
#include "SchedulerEvent.h"
#include "Configuration.h"
#include <vector>

class EventsController
{
public:
  EventsController();
  ~EventsController()=default;

  void PushEvent(IEvent *p_event);
  EEventType PeekCurrentEventType(void);
  void PopEvent(void);
  std::vector <IEvent*> eventsTest;
  
private:
  IEvent* specificEvent = new SpecificAction{};
  IEvent* alarmEvent = new AlarmEvent{};
  IEvent* schedulerEvent = new SchedulerEvent{};

private:
  std::string GetEventName(EEventType p_event_type);
  void DisplayMessage(IEvent * v_event, std::string message);
};