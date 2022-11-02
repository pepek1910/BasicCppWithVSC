#include "Machine.h"

Machine::Machine(){
    #if SERIAL_DEBUG_ON && SERIAL_DEBUG_MACHINE
        std::cout<<"machine # MachineInit() START"<<std::endl;
    #endif

    uint8_t i = 0;
    m_machine_state_strings[i++] = "UNKNOWN";
    m_machine_state_strings[i++] = "INITIALIZATION";
    m_machine_state_strings[i++] = "INITIALIZATION_DONE";
    m_machine_state_strings[i++] = "CALIBRATION";
    m_machine_state_strings[i++] = "CALIBRATION_DONE";
    m_machine_state_strings[i++] = "PRE_RUNNING";
    m_machine_state_strings[i++] = "RUNNING";
    m_machine_state_strings[i++] = "ERROR";

    if (i != (uint8_t)EMachineState::STATES_COUNT)
    {
        #if SERIAL_DEBUG_ON && SERIAL_DEBUG_MACHINE
        std::cout<<"machine # MachineInit() ERROR wrong number of m_machine_state_strings!!!"<<std::endl;
        #endif
    }
 
    m_machine_state = EMachineState::INITIALIZATION;

    #if SERIAL_DEBUG_ON && SERIAL_DEBUG_MACHINE
        std::cout<<"machine # MachineInit() END"<<std::endl;
    #endif

    MachineSetState(EMachineState::INITIALIZATION_DONE);
}

void Machine::machineSpin()
{
    std::cout<< "Machine Spin"<<std::endl;
    if (m_machine_state == EMachineState::INITIALIZATION_DONE)
    {
        #if BEGIN_WITH_SPECIFIC_ACTION == 0
            #if SPECIFIC_ACTION
                MachineSetState(EMachineState::SPECIFIC_ACTION);
                m_events.PushEvent(SEvent(EEventType::SPECIFIC_ACTION, 1));
            #else
                MachineSetState(EMachineState::PRE_RUNNING);
            #endif
        #else
            if (m_events.PeekCurrentEventType() != m_events.EEventType::EVENTS_COUNT)
            {
                SEvent v_event = PopEvent();
                if (v_event.m_type == EEventType::SPECIFIC_ACTION)
                {
                #if SPECIFIC_ACTION
                    MachineSetState(EMachineState::SPECIFIC_ACTION);
                    PushEvent(SEvent(EEventType::SPECIFIC_ACTION, 1));
                #else
                    MachineSetState(EMachineState::PRE_RUNNING);
                #endif
                }
            }
        #endif
    }
    else if (m_machine_state == EMachineState::PRE_RUNNING)
    {
        std::cout<<"PRE RUNNING"<<std::endl;
        //m_events.eventsTest.push_back(m_events.eventsTest.specificEvent);
        MachineSetState(EMachineState::RUNNING);
    }
    else if (m_machine_state == EMachineState::RUNNING)
    {
        std::cout<<"RUNNING"<<std::endl;
        m_events.PeekCurrentEventType();
   }
}

void Machine::MachineSetState(EMachineState p_state)
{
  m_machine_state = p_state;

  #if SERIAL_DEBUG_ON && SERIAL_DEBUG_MACHINE 
    std::cout<<"machine # MachineSetState()=";
    if (m_machine_state_strings[(uint8_t)p_state] == "")
    {
      std::cout<<"???"<<std::endl;
    }
    else
    {
      std::cout<<(m_machine_state_strings[(uint8_t)p_state])<<std::endl;
    }
  #endif
}

EMachineState Machine::MachineGetState(void)
{
  return m_machine_state;
}
