#include "Scheduler.h"

Scheduler::Scheduler(int p_schedule_cycle_time = def_schedule_cycle_time_in_seconds)
{
    m_schedule_cycle_time = p_schedule_cycle_time;
    m_time = getTime();
    std::cout<< "Time from SchedulerConstructor: "<< m_time<<std::endl;
    printTime();
}
void Scheduler::printTime(){
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
std::time_t Scheduler::getTime(){
//
    std::time_t v_time = {std::time(0)};
    return v_time;
}
bool Scheduler::checkCycleTime()
{ 
    std::time_t v_act_time = getTime();
    auto time_passed = v_act_time - m_time;
    #if 1//SERIAL_DEBUG_ON && SERIAL_DEBUG_MACHINE
        std::cout<<"Scheduler time: " << m_time
            <<" cycle time: "<<  m_schedule_cycle_time
            << " act time: " <<v_act_time 
            <<" time left: "<< m_schedule_cycle_time-time_passed
        <<std::endl;
    #endif
    if (time_passed > m_schedule_cycle_time){
        //std::cout<< "Time To do Sth"<<std::endl;  
        m_time = getTime();
        return true;
    }
    else{
        //std::cout<< "Still have :"<< m_schedule_cycle_time -(v_act_time - m_time) << "ms left"<<std::endl;
        return false;
    }
}
