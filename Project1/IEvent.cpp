#include "IEvent.h"

std::ostream& operator<<(std::ostream& os, const IEvent& obj){
	obj.print(os);
	return os;
}