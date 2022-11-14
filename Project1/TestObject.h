#include "ErrorHandlingComponent.h"

class TestObject : public ErrorHandlingComponent
{
public:
    TestObject(ErrorChecker* p_error_Checker);
    ~TestObject()=default;

    void Control();
     virtual void OnError() override;

    int counter{0};
};