#pragma once
#include <iostream>

enum struct EEventType
{
  SPECIFIC_ACTION =0,
  ALARM,
  SCHEDULER,
  EVENTS_COUNT
};

class IEvent
{
public:
  IEvent(EEventType p_type = def_type, int16_t p_param = def_param, int16_t p_param2 = def_param2)
  {
    m_type = p_type;
    //m_timestamp = g_current_millis;
    m_param = p_param;
    m_param2 = p_param2;
  }
  ~IEvent()=default;
  EEventType getEventType(){ return m_type;};
  void Spin();

  EEventType m_type;
  unsigned long m_timestamp;
  int16_t m_param;
  int16_t m_param2;
  
private:
  static constexpr EEventType def_type = EEventType::EVENTS_COUNT;
  static constexpr int16_t def_param = 0;
  static constexpr int16_t def_param2 = 0;
};