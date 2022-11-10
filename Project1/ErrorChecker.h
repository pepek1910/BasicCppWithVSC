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
    void RegisterComponent(ErrorHandlingComponent*);
    void UnRegisterComponent(ErrorHandlingComponent*);
    
private:
    void Check();
    void ClearErrorHandlingComponents();
    //void SetMachineState(StateController* p_machine_state_controller_pointer);
    void StartErrorChecking();
    void UnRegisterAll();
    //Unregister_redundant_components chyba nie potrzebne bo zrobimy dynamicznie

    bool m_block_checking_error{true};
    bool m_error_on_component{false};
    bool m_machine_error_handling_finished{true};
    bool m_set_error_state_trigger{false};
    bool m_first_error_occured{false};
    const static int16_t max_component_count = 1000;
};


// m_count_registered_components : INT:=0;
//  :BOOL:=FALSE;
// m_error_on_component				:BOOL:=FALSE;
// m_set_error_state_trigger : R_TRIG;
// m_machine_state_controller_ref :	IStateController;
// m_block_checking_error	:BOOL:=TRUE;
// m_first_error_occured : BOOL := FALSE;