#pragma once
#include <iostream>
#include "IEvent.h"
#include "SpecificAction.h"
#include "AlarmEvent.h"
#include "SchedulerEvent.h"
#include "ClockSchedulerEvent.h"
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
  std::vector <IEvent*> eventsTest;
  std::vector <IEvent*> scheduledAction;

  IEvent* specificEvent = new SpecificAction{};
  IEvent* alarmEvent = new AlarmEvent{};
  IEvent* schedulerEvent = new SchedulerEvent{};
  IEvent* clockSchedulerEvent = new ClockSchedulerEvent{};

private:
  std::string GetEventName(EEventType p_event_type);
  void DisplayMessage(std::vector <IEvent*> *p_vector, IEvent * v_event, std::string message);
};