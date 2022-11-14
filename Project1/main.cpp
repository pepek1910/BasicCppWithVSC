#include <iostream>
#include "Machine.h"
#include "ErrorChecker.h"

int main()
{
    ErrorChecker errorChecker{};
    Machine machine{&errorChecker};
    while(true){
        machine.Control();
        errorChecker.Check();
    }
    return 0;
}