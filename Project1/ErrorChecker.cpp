#include "ErrorChecker.h"

//ErrorChecker::ErrorChecker(StateController* p_machine_state_controller_pointer): m_machine_state_controller_pointer{p_machine_state_controller_pointer}{};
void ErrorChecker::SetStateController(StateController* p_machine_state_controller_ref)
{
    m_machine_state_controller_ref = p_machine_state_controller_ref;
}
void ErrorChecker::Check(){
    if (m_block_checking_error)
        return;

    for(size_t i =0; i<m_vector_error_handling_components.size(); i++){
        auto v_error = m_vector_error_handling_components.at(i)->GetError();
        if (v_error.m_code != ErrorEnum::OK)
        {
            if (v_error.m_priority == ErrorPriorityEnum::ERROR_PRIORYTY || v_error.m_priority == ErrorPriorityEnum::ERROR_PRIORYTY || v_error.m_priority == ErrorPriorityEnum::FATAL_ERROR_PRIORYTY)
            {
                m_error_on_component =true;
                m_machine_error_handling_finished = false;
            }
            // ADSLOGSTR(ADSLOG_MSGTYPE_WARN, '%s', CONCAT(m_error_handling_components[v_i]^.Get_name(),TO_STRING(v_error.m_code)));
            m_vector_error_handling_components.at(i)->ResetError();
        }
    }
    bool v_all_actions_finished{false};
    if (m_error_on_component)
    {
        if (!set_error_only_once)
        {
            set_error_only_once=true;
            if (!m_machine_state_controller_ref->trySetState(MachineStateEnum::ERROR))
            {
                m_machine_state_controller_ref->trySetState(MachineStateEnum::FATAL_ERROR);
            }
        }
        v_all_actions_finished = true;
        for(size_t i =0; i<m_vector_error_handling_components.size(); i++){
            if (!m_vector_error_handling_components.at(i)->m_on_error_actions_finished)
            {
                m_vector_error_handling_components.at(i)->OnError();
                v_all_actions_finished = false;
            }
        }
        if (v_all_actions_finished)
        {
            set_error_only_once=true;
            m_machine_error_handling_finished = true;
            m_error_on_component = false;
            // for(size_t i =0; i<m_vector_error_handling_components->size(); i++){
            //     if (m_error_handling_components[v_i]^.Is_busy())
            //     {
            //         ADSLOGSTR(ADSLOG_MSGTYPE_WARN, '%s', CONCAT(m_error_handling_components[v_i]^.Get_name(),' busy after onError actions finished'));
            //     }
            // }
        }
    }
}

void ErrorChecker::ClearErrorHandlingComponents()
{
    for(size_t i =0; i<m_vector_error_handling_components.size(); i++){
        m_vector_error_handling_components.at(i)->Clear_error_handling_flag();
    }
}

void ErrorChecker::StartErrorChecking()
{
    m_block_checking_error = false; 
}

void ErrorChecker::RegisterComponent(ErrorHandlingComponent* p_pointer_to_error_handling_component)
{
    m_vector_error_handling_components.push_back(p_pointer_to_error_handling_component);
}

void ErrorChecker::UnRegisterAll()
{
    for(size_t i =0; i<m_vector_error_handling_components.size(); i++)
    {
	    m_vector_error_handling_components.pop_back();
    }
}

void ErrorChecker::UnRegisterComponent(ErrorHandlingComponent* p_pointer_to_error_handling_component)
{
    // m_vector_error_handling_components.erase(
    //     std::find(m_vector_error_handling_components.begin(),
    //     m_vector_error_handling_components.end(), 
    //     p_pointer_to_error_handling_component)
    //     );
        
    // m_vector_error_handling_components.erase(
    //     m_vector_error_handling_components.find(
    //         m_vector_error_handling_components.begin(),
    //         m_vector_error_handling_components.end(), 
    //         p_pointer_to_error_handling_component)
    //     );
    // for(size_t i =0; i<m_vector_error_handling_components->size(); i++)
    // {
    //     if (m_pointer_to_error_handling_component == p_pointer_to_error_handling_component)
    //     {
            
    //     }
    // }
}


