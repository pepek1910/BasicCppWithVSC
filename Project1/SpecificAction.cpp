#include "SpecificAction.h"

SpecificAction::SpecificAction(void)
{
    // DEBUG_FUNCTION_START
    m_specific_action_state = ESpecificActionState::IDLE;
    // DEBUG_FUNCTION_END
}


void SpecificAction::Spin(void)
{
  //SpecificActionSpinInner();

  // // if (eventsController.PeekCurrentEventType() != EEventType::SPECIFIC_ACTION)
  // //   return;

  // SEvent v_event = eventsController.PopEvent();
  
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_CALIBRATION && (SERIAL_DEBUG_CALIBRATION >= 2)
    Serial.println("SpecificAction # event");
  #endif
  Start();

  // if (eventsController.m_events_queue->getEventType() == EEventType::SPECIFIC_ACTION)
  // {
  //   switch (v_event.m_param)
  //   {
  //     case 0:
  //     {
  //       Stop();
  //       break;
  //     }
  //     case 1:
  //     {
  //       Start();
  //       break;
  //     }
  //     case 2:
  //     {
  //       m_specific_action_finished = v_event.m_param2;
  //       break;
  //     }
  //     default:
  //     {
  //       //std::cout<<m_debug_module_name_with_decoration;
  //       std::cout<<(__FUNCTION__);
  //       std::cout<<" ERROR unknown event type ";
  //       std::cout<<(uint8_t)v_event.m_type<<std::endl;
  //       break;
  //     }
  //   }
  // }
}

ESpecificActionState SpecificAction::GetState()
{
  return m_specific_action_state;
}

void SpecificAction::Start()
{
  //DEBUG_FUNCTION_START
  m_temp_variable = 0;
  m_specific_action_state = ESpecificActionState::INITIALIZATION;
  //DEBUG_FUNCTION_END
}

void SpecificAction::Stop()
{
  //DEBUG_FUNCTION_START
  // TODO : zatrzymac silniki itp.
  m_temp_variable = 0;
  m_specific_action_state = ESpecificActionState::IDLE;
  //DEBUG_FUNCTION_END
}