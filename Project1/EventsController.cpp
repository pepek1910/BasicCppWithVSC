#include "EventsController.h"
#include "Configuration.h"

EventsController::EventsController()
{
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<"events # EventsInit() START"<<std::endl; //Serial.println("events # EventsInit() START");
  #endif

  //eventsTest.push_back(specificEvent);
  PushEvent(specificEvent);
  //eventsTest.push_back(specificEvent);
  
  if (eventsTest.size() != (uint8_t)EEventType::EVENTS_COUNT)
  {
    #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<"events # EventsInit() ERROR wrong number of m_event_type_strings!!!"<<std::endl; //Serial.println("events # EventsInit() ERROR wrong number of m_event_type_strings!!!");
    #endif
  }
  
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<"events # EventsInit() END"<<std::endl;//    Serial.println("events # EventsInit() END");
  #endif
}

void EventsController::PushEvent(IEvent *p_event)
{
  #if MUTE_ALARMS == 1
    if (p_event->m_type == EEventType::ALARM)
    {
      #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
        std::cout<<("events # ");
        std::cout<<p_event;
        // std::cout<<(" ");
        // std::cout<<(p_event->m_param);
        std::cout<<(" muted")<<std::endl;
      #endif
      return;
    }
  #endif
  eventsTest.push_back(p_event);
  DisplayMessageFromPush();
}


EEventType EventsController::PeekCurrentEventType(void)
{
  if (eventsTest.size() == 0)
  {
    return EEventType::EVENTS_COUNT;
  }
  eventsTest.at(0)->Spin();
  auto eventType = eventsTest.at(0)->getEventType();
  PopEvent();
  return eventType;
}

void EventsController::PopEvent(void)
{
  eventsTest.pop_back();
}

void EventsController::DisplayMessageFromPop(IEvent * v_event){
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
  //TODO Use std::ostream& operator<<(std::ostream& os, const I_Printable& obj){
    std::cout<<"events # ";
    std::cout<<"<-- ";
    std::cout<<(int)v_event->m_type;
    std::cout<<" ";
    std::cout<<v_event->m_timestamp;
    std::cout<<" ";
    std::cout<<v_event->m_param;
    std::cout<<" ";
    std::cout<<v_event->m_param2;
    std::cout<<" in queue: ";
    std::cout<<eventsTest.size()+1<<std::endl;
  #endif
}
void EventsController::DisplayMessageFromPush()
{
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<("events # ");
    std::cout<<("--> ");
    // std::cout<<(m_event_type_strings[(uint8_t)m_events_queue[m_events_in_queue - 1]->m_type]);
    // std::cout<<(" ");
    // std::cout<<(m_events_queue[m_events_in_queue - 1]->m_timestamp);
    // std::cout<<(" ");
    // std::cout<<(m_events_queue[m_events_in_queue - 1]->m_param);
    // std::cout<<(" ");
    // std::cout<<(m_events_queue[m_events_in_queue - 1]->m_param2);
    std::cout<<(" in queue: ");
    std::cout<<eventsTest.size()+1<<std::endl;
  #endif
}