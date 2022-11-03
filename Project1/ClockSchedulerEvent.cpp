#include "ClockSchedulerEvent.h"

void ClockSchedulerEvent::Spin()
{
    std::cout << "[ClockSchedulerEvent-> type:" << int(EEventType::SCHEDULER) << " cycle time: " << v_schedule_cycle_time << "]";
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
    os << "[ClockSchedulerEvent-> type:" << int(EEventType::SCHEDULER) << "cycle time: " << v_schedule_cycle_time << "]";
}