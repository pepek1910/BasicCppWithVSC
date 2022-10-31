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
    :IEvent{EEventType::SPECIFIC_ACTION, 0,0}{
    };
  ~SpecificAction() = default;

  void Spin();
  void Start();
  void Stop();
  ESpecificActionState GetState();

  ESpecificActionState m_specific_action_state;
  uint8_t m_specific_action_finished;
  //static const char m_debug_module_name_with_decoration[] = "specificAction # ";
  uint8_t m_temp_variable = 0;
  //EventsController eventsController{};
private:
  static constexpr uint8_t def_specific_action_finished = 0;
  static constexpr ESpecificActionState def_specific_action_state = ESpecificActionState::IDLE;
};