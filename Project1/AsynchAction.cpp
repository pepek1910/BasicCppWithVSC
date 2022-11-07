#include "AsynchAction.h"

void AsynchAction::Spin(void)
{
  //SpecificActionSpinInner();

  // // if (eventsController.PeekCurrentEventType() != EEventType::SPECIFIC_ACTION)
  // //   return;

  // SEvent v_event = eventsController.PopEvent();
  
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_CALIBRATION && (SERIAL_DEBUG_CALIBRATION >= 2)
    Serial.println("AsynchAction # event");
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

EAsynchActionState AsynchAction::GetState()
{
  return m_specific_action_state;
}

void AsynchAction::Start()
{
  //DEBUG_FUNCTION_START
  m_temp_variable = 0;
  m_specific_action_state = EAsynchActionState::INITIALIZATION;
  std::cout<<"Start from Specific Action Event"<<std::endl;
  //DEBUG_FUNCTION_END
}

void AsynchAction::Stop()
{
  //DEBUG_FUNCTION_START
  m_temp_variable = 0;
  m_specific_action_state = EAsynchActionState::IDLE;
  //DEBUG_FUNCTION_END
}

void AsynchAction::print(std::ostream& os) const {
    os.precision(2);
    os << std::fixed;
    os << "[AsynchAction-> type:" << int(EEventType::ASYNCH_ACTION) << "param: " << m_param << "]";
}