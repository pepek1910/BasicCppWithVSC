#pragma once
#include <iostream>
#include "Configuration.h"
#include "IEvent.h"

enum struct EAsynchActionState : uint8_t
{
  IDLE = 0,
  INITIALIZATION,
  CLEANUP,
  DONE
};

class AsynchAction :public IEvent
{
public:
  AsynchAction()
    :IEvent{def_event_type, def_param, def_param2}{
    };
  ~AsynchAction() = default;

  virtual void Spin() override;
  void Start();
  void Stop();
  EAsynchActionState GetState();
  virtual void print(std::ostream& os) const override;

private:
  EAsynchActionState m_specific_action_state;
  uint8_t m_specific_action_finished;
  uint8_t m_temp_variable = 0;

private:
  static constexpr EEventType def_event_type = EEventType::ASYNCH_ACTION;
  static constexpr int16_t def_param = 0;
  static constexpr int16_t def_param2 = 0;
};