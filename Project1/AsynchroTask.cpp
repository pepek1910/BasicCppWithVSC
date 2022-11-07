#include "AsynchroTask.h"

std::ostream& operator<<(std::ostream& os, const AsynchroTask& obj){
	obj.print(os);
	return os;
}