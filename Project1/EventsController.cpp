#include "EventsController.h"
#include "Configuration.h"

EventsController::EventsController()
{
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<"events # EventsInit() START"<<std::endl; //Serial.println("events # EventsInit() START");
  #endif

  uint8_t i = 0;
  //m_event_type_strings[i++] = "EVENT_BUTTON_PRESSED";
  //m_event_type_strings[i++] = "DISPLAY_UPDATE";
  m_event_type_strings[i++] = "SPECIFIC_ACTION";
  m_event_type_strings[i++] = "EVENT_ALARM";
  //m_event_type_strings[i++] = "SENSORS";
  //m_event_type_strings[i++] = "EVENT_LIMIT_SWITCH_CNT";
  m_event_type_strings[i++] = "EVENT_SCHEDULER";
  //m_event_type_strings[i++] = "EVENT_INC_ENCODER_UPDATE";
  //m_event_type_strings[i++] = "CALIBRATION";
  //m_event_type_strings[i++] = "MENU";
  //m_event_type_strings[i++] = "MOVEMENT_COMMAND";
  m_events_in_queue = 0;
  
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

void EventsController::PushEvent(SEvent p_event)
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


EEventType EventsController::PeekCurrentEventType(void)
{
  if (m_events_in_queue == 0)
  {
    return EEventType::EVENTS_COUNT;
  }
  return m_events_queue[0].m_type;
}

SEvent EventsController::PopEvent(void)
{
  SEvent v_event;
  if (m_events_in_queue != 0)
  {
    v_event = m_events_queue[0];
    for (uint8_t i = 0; i < m_events_in_queue; i++)
    {
      m_events_queue[i] = m_events_queue[i + 1];
    }
    m_events_in_queue--;
  }
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
  return v_event;
}
