#include "AlarmEvent.h"

void AlarmEvent::Spin(){
    std::cout<< "Spin from AlarmEvent" <<std::endl;
}

void AlarmEvent::print(std::ostream& os) const {
    os.precision(2);
    os << std::fixed;
    os << "[AlarmEvent-> type:" << int(EEventType::ALARM) << "param: " << m_param << "]";
}