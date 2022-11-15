#include "ReminderSchedluerEvent.h"

ReminderSchedluerEvent::ReminderSchedluerEvent(int m_schedule_cycle_time)
    :SynchEvent(m_schedule_cycle_time), IEvent(EEventType::SCHEDULER,0,0)
{}

void ReminderSchedluerEvent::Spin()
{
    #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
        std::cout<< *this;
    #endif
    if (checkCycleTime()){
        #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
            std::cout<< " -> Did You Forgot!" <<std::endl;
        #endif
    }
    else {
        #if SERIAL_DEBUG_ON && SERIAL_DEBUG_EVENTS
            std::cout<< " -> Just Watching..." <<std::endl;
        #endif
    }

}
void ReminderSchedluerEvent::print(std::ostream& os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[ReminderSchedulerEvent-> type:" << int(EEventType::SCHEDULER) << " cycle time: " << getCycleTime() << "]"<<std::endl;
}