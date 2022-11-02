#pragma once
#include <iostream>
#include "Configuration.h"
#include "IEvent.h"

enum struct ESpecificActionState : uint8_t
{
  IDLE = 0,
  INITIALIZATION,
  CLEANUP,
  DONE
};

class SpecificAction :public IEvent
{
public:
  SpecificAction()
    :IEvent{def_event_type, def_param, def_param2}{
    };
  ~SpecificAction() = default;

  virtual void Spin() override;
  void Start();
  void Stop();
  ESpecificActionState GetState();
  virtual void print(std::ostream& os) const override;
  
  ESpecificActionState m_specific_action_state;
  uint8_t m_specific_action_finished;
  //static const char m_debug_module_name_with_decoration[] = "specificAction # ";
  uint8_t m_temp_variable = 0;
  //EventsController eventsController{};

private:
  static constexpr EEventType def_event_type = EEventType::SPECIFIC_ACTION;
  static constexpr int16_t def_param = 0;
  static constexpr int16_t def_param2 = 0;
};