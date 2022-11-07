#pragma once
#include <iostream>
#include "Configuration.h"
#include "AsynchroTask.h"

class AlarmEvent :public AsynchroTask
{
public:
  AlarmEvent()
    :AsynchroTask{def_event_type, def_param, def_param2}{
    };
  ~AlarmEvent() = default;

  virtual void Spin() override;
  virtual void print(std::ostream& os) const override;

private:
  static constexpr EEventType def_event_type = EEventType::ALARM;
  static constexpr int16_t def_param = 0;
  static constexpr int16_t def_param2 = 0;
};