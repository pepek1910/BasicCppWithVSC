#pragma once
#include <iostream>
#include "ErrorHandlingComponent.h"
#include "StateController.h"
#include <vector>

class ErrorChecker
{
public:
    ErrorChecker()=default;
    //ErrorChecker(StateController* p_machine_state_controller_pointer);
    ~ErrorChecker()=default;
    std::vector<ErrorHandlingComponent*> m_vector_error_handling_components;
    void SetStateController(StateController* p_machine_state_controller_ref);
    void RegisterComponent(ErrorHandlingComponent*);
    void UnRegisterComponent(ErrorHandlingComponent*);
    void Check();
    
private:
    void ClearErrorHandlingComponents();
    //void SetMachineState(StateController* p_machine_state_controller_pointer); To set Fatal Error is it neccesairy?
    void StartErrorChecking();
    void UnRegisterAll();
    //Unregister_redundant_components chyba nie potrzebne bo zrobimy dynamicznie

    bool m_block_checking_error{false};
    bool m_error_on_component{false};
    bool m_machine_error_handling_finished{true};
    bool m_set_error_state_trigger{false};
    bool m_first_error_occured{false};
    StateController* m_machine_state_controller_ref{};
    bool set_error_only_once{false};

};


// m_count_registered_components : INT:=0;
//  :BOOL:=FALSE;
// m_error_on_component				:BOOL:=FALSE;
// m_set_error_state_trigger : R_TRIG;
// m_machine_state_controller_ref :	IStateController;
// m_block_checking_error	:BOOL:=TRUE;
// m_first_error_occured : BOOL := FALSE;