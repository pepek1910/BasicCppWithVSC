#include "TestObject.h"

TestObject::TestObject(ErrorChecker* p_error_Checker, std::string p_name)
    :ErrorHandlingComponent(p_error_Checker), IBaseComponent(p_name)
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
    std::cout<< "Error From: " << IBaseComponent::GetName() <<std::endl;
}