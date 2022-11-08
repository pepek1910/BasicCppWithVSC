#include <iostream>
#include "Machine.h"

int main()
{
    Machine machine{};
    while(true){
        machine.Control();
    }
    return 0;
}