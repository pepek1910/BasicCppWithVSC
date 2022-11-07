#include "ClockSynchEvent.h"

ClockSynchEvent::ClockSynchEvent(int m_schedule_cycle_time)
    :SynchEvent(m_schedule_cycle_time), IEvent(EEventType::SCHEDULER,0,0)
{}

void ClockSynchEvent::Spin()
{
    std::cout << "[ClockSynchEvent-> type:" << int(EEventType::SCHEDULER) << " cycle time: " << getCycleTime() << "]";

    if (checkCycleTime()){
        std::cout<< " -> ALARM" <<std::endl;
    }
    else {
        std::cout<< " -> Tick Tack" <<std::endl;
    }

}
void ClockSynchEvent::print(std::ostream& os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[ClockSynchEvent-> type:" << int(EEventType::SCHEDULER) << "cycle time: " << /*getCycleTime() <<*/ "]"<<std::endl;
}