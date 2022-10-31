#include "EventsController.h"
#include "Configuration.h"

EventsController::EventsController()
{
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<"events # EventsInit() START"<<std::endl; //Serial.println("events # EventsInit() START");
  #endif

  uint8_t i = 0;
  m_event_type_strings[i++] = "SPECIFIC_ACTION";
  m_event_type_strings[i++] = "EVENT_ALARM";
  m_event_type_strings[i++] = "EVENT_SCHEDULER";
  m_events_in_queue = 0;
  
  //eventsTest.push_back(specificEvent);

  if (i != (uint8_t)EEventType::EVENTS_COUNT)
  {
    #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<"events # EventsInit() ERROR wrong number of m_event_type_strings!!!"<<std::endl; //Serial.println("events # EventsInit() ERROR wrong number of m_event_type_strings!!!");
    #endif
  }
  
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<"events # EventsInit() END"<<std::endl;//    Serial.println("events # EventsInit() END");
  #endif
}

void EventsController::PushEvent(IEvent p_event)
{
  #if MUTE_ALARMS == 1
    if (p_event.m_type == EEventType::ALARM)
    {
      #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
        std::cout<<("events # ");
        std::cout<<(m_event_type_strings[(uint8_t)p_event.m_type]);
        std::cout<<(" ");
        std::cout<<(p_event.m_param);
        std::cout<<(" muted")<<std::endl;
      #endif
      return;
    }
  #endif
  
  m_events_queue[m_events_in_queue] = p_event;
  m_events_in_queue++;
  DisplayMessageFromPush();
}


EEventType EventsController::PeekCurrentEventType(void)
{
  if (m_events_in_queue == 0)
  {
    return EEventType::EVENTS_COUNT;
  }
  specificEvent.Spin(); //TODO use vector of events and use Spin from just first element.
  PopEvent();
  return m_events_queue[0].m_type;
}

IEvent EventsController::PopEvent(void)
{
  IEvent v_temp_event;
  if (m_events_in_queue != 0)
  {
    v_temp_event = m_events_queue[0];
    for (uint8_t i = 0; i < m_events_in_queue; i++)
    {
      m_events_queue[i] = m_events_queue[i + 1];
    }
    m_events_in_queue--;
  }
  DisplayMessageFromPop(v_temp_event);
  return v_temp_event;
}

void EventsController::DisplayMessageFromPop(IEvent v_event){
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<"events # ";
    std::cout<<"<-- ";
    std::cout<<m_event_type_strings[(uint8_t)v_event.m_type];
    std::cout<<" ";
    std::cout<<v_event.m_timestamp;
    std::cout<<" ";
    std::cout<<v_event.m_param;
    std::cout<<" ";
    std::cout<<v_event.m_param2;
    std::cout<<" in queue: ";
    std::cout<<m_events_in_queue<<std::endl;
  #endif
}
void EventsController::DisplayMessageFromPush()
{
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<("events # ");
    std::cout<<("--> ");
    std::cout<<(m_event_type_strings[(uint8_t)m_events_queue[m_events_in_queue - 1].m_type]);
    std::cout<<(" ");
    std::cout<<(m_events_queue[m_events_in_queue - 1].m_timestamp);
    std::cout<<(" ");
    std::cout<<(m_events_queue[m_events_in_queue - 1].m_param);
    std::cout<<(" ");
    std::cout<<(m_events_queue[m_events_in_queue - 1].m_param2);
    std::cout<<(" in queue: ");
    std::cout<<(m_events_in_queue)<<std::endl;
  #endif
}