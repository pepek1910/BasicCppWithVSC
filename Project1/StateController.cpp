#include "StateController.h"

StateController::StateController(){
    #if SERIAL_DEBUG_ON
        std::cout<<"Allowed Transition initialization"<<std::endl;
    #endif
    for(int i =0; i<MachineStateEnum::MACHINE_STATE_ENUM_GUARD; i++){
        for(int j=0; j<MachineStateEnum::MACHINE_STATE_ENUM_GUARD; j++){
            m_allowedTransitions[i][j] = false;
        }
    }
    m_allowedTransitions[MachineStateEnum::INITIALIZATION][MachineStateEnum::ERROR]=true;
    m_allowedTransitions[MachineStateEnum::INITIALIZATION][MachineStateEnum::READY]=true;
    m_allowedTransitions[MachineStateEnum::READY][MachineStateEnum::ERROR]=true;
    m_allowedTransitions[MachineStateEnum::READY][MachineStateEnum::RUNNING]=true;
    m_allowedTransitions[MachineStateEnum::RUNNING][MachineStateEnum::ERROR]=true;
    m_allowedTransitions[MachineStateEnum::ERROR][MachineStateEnum::RESETTING]=true;
    m_allowedTransitions[MachineStateEnum::RESETTING][MachineStateEnum::INITIALIZATION]=true;
    
}

bool StateController::trySetState(MachineStateEnum p_state)
{
    auto v_actState = GetState();
    if(m_allowedTransitions[v_actState][p_state]==true){
        std::cout<<"State Set "<<(p_state)<<std::endl;
        m_machineState = p_state;
        return true;
        // #if SERIAL_DEBUG_ON && SERIAL_DEBUG_MACHINE 
        //     std::cout<<"machine # MachineSetState()=";
        //     if (m_machine_state_strings[(uint8_t)p_state] == "")
        //     {
        //         std::cout<<"???"<<std::endl;
        //     }
        //     else
        //     {
        //     std::cout<<(m_machine_state_strings[(uint8_t)p_state])<<std::endl;
        //     }
        // #endif    
    }
    else{
        std::cout<<"Unable to State Set "<<(p_state)<<std::endl;
        trySetState(MachineStateEnum::FATAL_ERROR);
        return false;
    }
}

MachineStateEnum StateController::GetState(void)
{
  return m_machineState;
}