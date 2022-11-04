#include "ReminderSchedluerEvent.h"

ReminderSchedluerEvent::ReminderSchedluerEvent(int m_schedule_cycle_time)
    :Scheduler(m_schedule_cycle_time), IEvent(EEventType::SCHEDULER,0,0)
{}

void ReminderSchedluerEvent::Spin()
{
    //std::cout << "[ReminderSchedluerEvent-> type:" << int(EEventType::SCHEDULER) << " cycle time: " << getCycleTime() << "]";
    std::cout<< *this;
    if (checkCycleTime()){
        std::cout<< " -> Did You Forgot!" <<std::endl;
    }
    else {
        std::cout<< " -> Just Watching..." <<std::endl;
    }

}
void ReminderSchedluerEvent::print(std::ostream& os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[ReminderSchedluerEvent-> type:" << int(EEventType::SCHEDULER) << " cycle time: " << getCycleTime() << "]"<<std::endl;
}