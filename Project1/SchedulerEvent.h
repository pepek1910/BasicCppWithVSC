#pragma once
#include <iostream>
#include "Configuration.h"
#include "IEvent.h"

class SchedulerEvent :public IEvent
{
public:
  SchedulerEvent()
    :IEvent{def_event_type, def_param, def_param2}{
    };
  ~SchedulerEvent() = default;

  virtual void Spin() override;
  void Start();
  void Stop();
  virtual void print(std::ostream& os) const override;
  
  uint8_t m_scheduler_finished;
  uint8_t m_temp_variable = 0;

private:
  static constexpr EEventType def_event_type = EEventType::SCHEDULER;
  static constexpr int16_t def_param = 0;
  static constexpr int16_t def_param2 = 0;
};