#pragma once
#include <iostream>
#include "Configuration.h"
#include "IEvent.h"

class AlarmEvent :public IEvent
{
public:
  AlarmEvent()
    :IEvent{def_event_type, def_param, def_param2}{
    };
  ~AlarmEvent() = default;

  virtual void Spin() override;
  virtual void print(std::ostream& os) const override;
  
private:
  uint8_t m_specific_action_finished;
  uint8_t m_temp_variable = 0;

private:
  static constexpr EEventType def_event_type = EEventType::ALARM;
  static constexpr int16_t def_param = 0;
  static constexpr int16_t def_param2 = 0;
  
};