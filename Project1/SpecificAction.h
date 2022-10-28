#pragma once
#include <iostream>
#include "Configuration.h"
#include "EventsController.h"

enum struct ESpecificActionState : uint8_t
{
  IDLE = 0,
  INITIALIZATION,
  CLEANUP,
  DONE
};

class SpecificAction
{
public:
    SpecificAction();
    ~SpecificAction() = default;
    void Spin();
    void Start();
    void Stop();
    ESpecificActionState GetState();

    ESpecificActionState m_specific_action_state = ESpecificActionState::IDLE;
    uint8_t m_specific_action_finished = 0;
    //static const char m_debug_module_name_with_decoration[] = "specificAction # ";
    uint8_t m_temp_variable = 0;
    //EventsController eventsController{};

};