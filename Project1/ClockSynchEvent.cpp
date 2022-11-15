#include "ClockSynchEvent.h"

ClockSynchEvent::ClockSynchEvent(int m_schedule_cycle_time)
    :SynchEvent(m_schedule_cycle_time), IEvent(EEventType::SCHEDULER,0,0)
{}

void ClockSynchEvent::Spin()
{
    #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
        std::cout << "[ClockSynchEvent-> type:" << int(EEventType::SCHEDULER) << " cycle time: " << getCycleTime() << "]";
    #endif
    if (checkCycleTime()){
        #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
            std::cout<< " -> ALARM" <<std::endl;
        #endif
    }
    else {
        #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
            std::cout<< " -> Tick Tack" <<std::endl;
        #endif
    }

}
void ClockSynchEvent::print(std::ostream& os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[ClockSynchEvent-> type:" << int(EEventType::SCHEDULER) << "cycle time: " << /*getCycleTime() <<*/ "]"<<std::endl;
}