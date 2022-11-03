#include "ClockSchedulerEvent.h"

ClockSchedulerEvent::ClockSchedulerEvent(int m_schedule_cycle_time)
    :Scheduler(m_schedule_cycle_time), IEvent(EEventType::SCHEDULER,0,0)
{}

void ClockSchedulerEvent::Spin()
{
    std::cout << "[ClockSchedulerEvent-> type:" << int(EEventType::SCHEDULER) << " cycle time: " << getCycleTime() << "]";

    if (checkCycleTime()){
        std::cout<< " -> ALARM" <<std::endl;
    }
    else {
        std::cout<< " -> Tick Tack" <<std::endl;
    }

}
void ClockSchedulerEvent::print(std::ostream& os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[ClockSchedulerEvent-> type:" << int(EEventType::SCHEDULER) << "cycle time: " << /*getCycleTime() <<*/ "]"<<std::endl;
}