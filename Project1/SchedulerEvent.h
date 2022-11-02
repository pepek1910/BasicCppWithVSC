#pragma once
#include <iostream>
#include <ctime>
#include "Configuration.h"
#include "IEvent.h"

class SchedulerEvent :public IEvent
{
public:
  SchedulerEvent(int p_schedule_cycle_time = def_schedule_cycle_time)
    :IEvent{def_event_type, def_param, def_param2}{
      std::time_t v_time = {std::time(0)};
      m_time = v_time;
      std::cout<< "Time from SchedulerEvent Constructor: "<< m_time<<std::endl;
      m_schedule_cycle_time = p_schedule_cycle_time;
    };
  ~SchedulerEvent() = default;

  virtual void Spin() override;
  void Start();
  void Stop();
  virtual void print(std::ostream& os) const override;
  //m_timestamp = g_current_millis;
  void printTime();
  std::time_t getTime();
  
private:
  std::time_t m_time;
  int m_schedule_cycle_time;
  uint8_t m_scheduler_finished;
  uint8_t m_temp_variable = 0;
  

private:
  static constexpr EEventType def_event_type = EEventType::SCHEDULER;
  static constexpr int16_t def_param = 0;
  static constexpr int16_t def_param2 = 0;
  static constexpr int def_schedule_cycle_time = 1000;
};