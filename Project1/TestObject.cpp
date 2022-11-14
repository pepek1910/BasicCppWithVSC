#include "TestObject.h"

TestObject::TestObject(ErrorChecker* p_error_Checker)
    :ErrorHandlingComponent(p_error_Checker)
    {}

void TestObject::Control()
{
    counter +=1;
    if(counter>10)
    {
        SetErrorByCodeAndPriority(ErrorEnum::COMPONENT_IS_ALREADY_BUSY,ErrorPriorityEnum::ERROR_PRIORYTY);
    }
}

void TestObject::OnError()
{
    m_on_error_actions_finished = true;
    std::cout<< "Error From TestObject" <<std::endl;
}