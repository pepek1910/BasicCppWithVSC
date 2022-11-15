#include "AsynchAction.h"

void AsynchAction::Spin(void)
{  
  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
    std::cout<<"AsynchAction # event";
  #endif
  Start();
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