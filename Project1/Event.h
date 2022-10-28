#pragma once
#include <iostream>

enum struct EEventType
{
  //BUTTON_PRESSED= 0 ,
  //DISPLAY_UPDATE,
  SPECIFIC_ACTION =0,
  ALARM,
  //SENSORS,
  //LIMIT_SWITCH_CNT,
  SCHEDULER,
  //INC_ENCODER_UPDATE,
  //CALIBRATION,
  //MENU,
  //MOVEMENT_COMMAND,
  EVENTS_COUNT
};

class SEvent
{
public:
  SEvent(EEventType p_type = EEventType::EVENTS_COUNT, int16_t p_param = 0, int16_t p_param2 = 0)
  {
    m_type = p_type;
    //m_timestamp = g_current_millis;
    m_param = p_param;
    m_param2 = p_param2;
  }
  EEventType getEventType(){ return m_type;};

  EEventType m_type;
  unsigned long m_timestamp;
  int16_t m_param;
  int16_t m_param2;
};