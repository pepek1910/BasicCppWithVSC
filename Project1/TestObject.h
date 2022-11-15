#include "ErrorHandlingComponent.h"
#include "IBaseComponent.h"

class TestObject : public ErrorHandlingComponent, public IBaseComponent
{
public:
    TestObject(ErrorChecker* p_error_Checker, std::string p_name);
    ~TestObject()=default;

    void Control();
    virtual void OnError() override;

    int counter{0};
};