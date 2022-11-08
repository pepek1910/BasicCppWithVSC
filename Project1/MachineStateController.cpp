#include "MachineStateController.h"
#define stringify( name ) #name

MachineStateController::MachineStateController(){
    std::cout<<"Allowed Transition initialization"<<std::endl;
    for(int i =0; i<MACHINE_STATE_ENUM_GUARD; i++){
        for(int j=0; j<MACHINE_STATE_ENUM_GUARD; j++){
            m_allowedTransitions[i][j] = false;
        }
    }
    m_allowedTransitions[MachineStateEnum::INITIALIZATION][MachineStateEnum::ERROR]=true;
    m_allowedTransitions[MachineStateEnum::INITIALIZATION][MachineStateEnum::READY]=true;
    m_allowedTransitions[MachineStateEnum::READY][MachineStateEnum::ERROR]=true;
    m_allowedTransitions[MachineStateEnum::READY][MachineStateEnum::RUNNING]=true;
    m_allowedTransitions[MachineStateEnum::RUNNING][MachineStateEnum::ERROR]=true;
}
bool MachineStateController::trySetState(MachineStateEnum p_state)
{
    auto v_actState = GetState();
    if(m_allowedTransitions[v_actState][p_state]==true){
        std::cout<<"State Set "<<std::to_string(p_state)<<std::endl;
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
        std::cout<<"Unable to State Set "<<std::to_string(p_state)<<std::endl;
        trySetState(MachineStateEnum::ERROR);
        return false;
    }
}

MachineStateEnum MachineStateController:: GetState(void)
{
  return m_machineState;
}