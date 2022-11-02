#include "EventsController.h"
#include "Configuration.h"

EventsController::EventsController()
{
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<"events # EventsInit() START"<<std::endl; //Serial.println("events # EventsInit() START");
  #endif

  //eventsTest.push_back(specificEvent);
  PushEvent(specificEvent);
  PushEvent(alarmEvent);
  
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

void EventsController::PushEvent(IEvent *p_event)
{
  #if MUTE_ALARMS == 1
    if (p_event->m_type == EEventType::ALARM)
    {
      #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
        std::cout<<("events # ");
        std::cout<<*p_event;
        std::cout<<(" muted")<<std::endl;
      #endif
      return;
    }
  #endif
  eventsTest.push_back(p_event);
  DisplayMessage(p_event, "Pushed event --> ");
}

void EventsController::PopEvent(void)
{
  // /eventsTest.pop_back();
  DisplayMessage(eventsTest.at(0), "Poped event <-- ");
  eventsTest.erase(eventsTest.begin());
}

void EventsController::DisplayMessage(IEvent * v_event, std::string message){
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<"events # "<<message;
    std::cout<<*v_event;
    std::cout<<" in queue: ";
    std::cout<<eventsTest.size()<<std::endl;
  #endif
}