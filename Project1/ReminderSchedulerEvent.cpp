#include "ReminderSchedulerEvent.h"

ReminderSchedulerEvent::ReminderSchedulerEvent(int m_task_cycle_time)
    :SynchroTask(m_task_cycle_time), AsynchroTask(EEventType::SCHEDULER,0,0)
{}

void ReminderSchedulerEvent::Spin()
{
    std::cout<< *this;
    if (checkCycleTime()){
        std::cout<< " -> Did You Forgot!" <<std::endl;
    }
    else {
        std::cout<< " -> Just Watching..." <<std::endl;
    }
}
void ReminderSchedulerEvent::print(std::ostream& os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[ReminderSchedulerEvent-> type:" << int(EEventType::SCHEDULER) << " cycle time: " << getCycleTime() << "]"<<std::endl;
}