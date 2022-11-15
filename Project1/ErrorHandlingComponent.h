#pragma once
#include <iostream>
//#include "Error.h"
#include "Structures/ErrorEnum.h"
#include "Structures/ErrorPriorityEnum.h"

class ErrorChecker;

struct ErrorType{
    ErrorEnum m_code{ErrorEnum::OK};
    ErrorPriorityEnum m_priority{ErrorPriorityEnum::DEBUG};
};

class ErrorHandlingComponent
{
public:
    ErrorHandlingComponent(ErrorChecker* error_Checker = NULL);
    ~ErrorHandlingComponent();

    virtual void OnError();
    ErrorType GetError(){return m_error;};
    void ResetError(){m_error.m_code=ErrorEnum::OK; m_error.m_priority=ErrorPriorityEnum::DEBUG;};
    void SetError(ErrorType p_error){m_error=p_error;};
    void SetErrorByCodeAndPriority(ErrorEnum p_error_enum,ErrorPriorityEnum p_priority);
    void Clear_error_handling_flag();

    bool m_on_error_actions_finished;
    ErrorType m_error;//{ErrorEnum::OK, ErrorPriorityEnum::DEBUG};
    ErrorChecker* error_Checker;
};
