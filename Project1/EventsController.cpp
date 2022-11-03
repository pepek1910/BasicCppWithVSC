#include "EventsController.h"
#include "Configuration.h"

EventsController::EventsController()
{
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<"events # EventsController Initialization START"<<std::endl; //Serial.println("events # EventsInit() START");
  #endif
  
  if (eventsTest.size() != (uint8_t)EEventType::EVENTS_COUNT)
  {
    #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<"events # EventsController Initialization ERROR wrong number of m_event_type_strings!!!"<<std::endl; //Serial.println("events # EventsInit() ERROR wrong number of m_event_type_strings!!!");
    #endif
  }
  
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<"events # EventsController Initialization END"<<std::endl;//    Serial.println("events # EventsInit() END");
  #endif
}

EventsController::~EventsController(){
  // delete specificEvent;
  // delete alarmEvent;
  // delete schedulerEvent;
}

EEventType EventsController::PeekCurrentEventType(std::vector <IEvent*> *p_vector)
{
  if (p_vector->size() == 0)
  {
    return EEventType::EVENTS_COUNT;
  }
  p_vector->at(0)->Spin();
  auto eventType = p_vector->at(0)->getEventType();
  PopEvent(p_vector);
  return eventType;
}

void EventsController::PushEvent(std::vector <IEvent*>* p_vector, IEvent *p_event)
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
  p_vector->push_back(p_event);
  DisplayMessage(p_vector, p_event, "Pushed event --> ");
}

void EventsController::PopEvent(std::vector <IEvent*> *p_vector)
{
  DisplayMessage(p_vector, p_vector->at(0), "Poped event <-- ");
  auto refVect = p_vector->at(0);
  delete refVect;
  p_vector->erase(p_vector->begin());
}

void EventsController::DisplayMessage(std::vector <IEvent*> *p_vector, IEvent * p_event, std::string message){
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<"events # "<<message;
    std::cout<<*p_event;
    std::cout<<" in queue: ";
    std::cout<<p_vector->size()<<std::endl;
  #endif
}

void EventsController::checkScheduleToRun(std::vector <IEvent*> *p_vector)
{
    for(int i =0; i<p_vector->size(); i++){
        p_vector->at(i)->Spin();
    }
}