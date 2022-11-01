#pragma once
#include <iostream>
#include "IEvent.h"
#include "SpecificAction.h"
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
  //{EEventType::SPECIFIC_ACTION, 0, 0};
  IEvent* specificEvent = new SpecificAction{};

private:
  //void EventsInit(void);
  std::string GetEventName(EEventType p_event_type);
  void DisplayMessageFromPop(IEvent * v_event);
  void DisplayMessageFromPush();
  //uint8_t m_events_in_queue;
  //std::string m_event_type_strings[(uint8_t)EEventType::EVENTS_COUNT];
};