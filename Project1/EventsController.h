#pragma once
#include <iostream>
#include "Event.h"
#include "Configuration.h"

class EventsController
{
public:
  EventsController();
  ~EventsController()=default;
  void PushEvent(SEvent p_event);
  EEventType PeekCurrentEventType(void);
  SEvent PopEvent(void);
  SEvent m_events_queue[EVENTS_QUEUE_SIZE];
private:
  //void EventsInit(void);
  std::string GetEventName(EEventType p_event_type);

  uint8_t m_events_in_queue;
  std::string m_event_type_strings[(uint8_t)EEventType::EVENTS_COUNT];
};