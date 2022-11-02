#include "SchedulerEvent.h"

void SchedulerEvent::Spin(void)
{
    std::cout<<"Spin from Scheduler Event"<<std::endl;
}

void SchedulerEvent::print(std::ostream& os) const {
    os.precision(2);
    os << std::fixed;
    os << "[SchedulerEvent-> type:" << int(EEventType::SCHEDULER) << "param: " << m_param << "]";
}