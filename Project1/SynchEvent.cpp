#include "SynchEvent.h"

SynchEvent::SynchEvent(int p_schedule_cycle_time = def_event_cycle_time_in_seconds)
{
    m_event_cycle_time = p_schedule_cycle_time;
    m_time = getTime();
    #if SERIAL_DEBUG_ON
        std::cout<< "Time from SchedulerConstructor: "<< m_time<<std::endl;
    #endif
    printTime();
}
void SynchEvent::printTime(){
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::cout << (now->tm_year + 1900) << '-' 
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << " : "
         << now->tm_hour << ":"
         << now->tm_min << ":"
         << now->tm_sec
         << "\n";
}
std::time_t SynchEvent::getTime(){
//
    std::time_t v_time = {std::time(0)};
    return v_time;
}
bool SynchEvent::checkCycleTime()
{ 
    std::time_t v_act_time = getTime();
    auto time_passed = v_act_time - m_time;
    #if (SERIAL_DEBUG_ON && SERIAL_DEBUG_MACHINE)
        std::cout<<"Scheduler time: " << m_time
            <<" cycle time: "<<  m_event_cycle_time
            << " act time: " <<v_act_time 
        <<std::endl;
        std::cout<<" time left: "<< m_event_cycle_time-time_passed<<std::endl;
    #endif
    if (time_passed > m_event_cycle_time){
        //std::cout<< "Time To do Sth"<<std::endl;  
        m_time = getTime();
        return true;
    }
    else{
        //std::cout<< "Still have :"<< m_event_cycle_time -(v_act_time - m_time) << "ms left"<<std::endl;
        return false;
    }
}
