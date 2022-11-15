#include "AlarmEvent.h"

void AlarmEvent::Spin(){
    #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
        std::cout<< "Spin from AlarmEvent" <<std::endl;
    #endif

}

void AlarmEvent::print(std::ostream& os) const {
    os.precision(2);
    os << std::fixed;
    os << "[AlarmEvent-> type:" << int(EEventType::ALARM) << "param: " << m_param << "]";
}