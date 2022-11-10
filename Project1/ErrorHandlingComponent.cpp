/// \brief ErrorHandlingComponent if p_register_in_error_checker = NULL will not register component
#include "ErrorHandlingComponent.h"
#include "ErrorChecker.h"

ErrorHandlingComponent::ErrorHandlingComponent(ErrorChecker* p_error_Checker ):error_Checker(p_error_Checker)
{
    if(error_Checker)//the same as -error_Checker !=NULL
    {
        error_Checker->RegisterComponent(this);
    }
}

ErrorHandlingComponent::~ErrorHandlingComponent()
{
    error_Checker->UnRegisterComponent(this);
}

void ErrorHandlingComponent::OnError()
{
    std::cout<<"Contructor"<<std::endl;
}

void ErrorHandlingComponent::SetErrorByCodeAndPriority(ErrorEnum p_error_enum,ErrorPriorityEnum p_priority)
{
    ErrorType v_error;
    v_error.m_code= p_error_enum;
    v_error.m_priority = p_priority;
    SetError(v_error);
}

void ErrorHandlingComponent::Clear_error_handling_flag()
{
    m_on_error_actions_finished=false;
}
