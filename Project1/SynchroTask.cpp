#include "SynchroTask.h"

SynchroTask::SynchroTask(int p_task_cycle_time = def_task_cycle_time_in_seconds)
{
    m_task_cycle_time = p_task_cycle_time;
    m_time = getTime();
    std::cout<< "Time from SynchroTask Constructor: "<< m_time<<std::endl;
    printTime();
}
void SynchroTask::printTime(){
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
std::time_t SynchroTask::getTime(){
//
    std::time_t v_time = {std::time(0)};
    return v_time;
}
bool SynchroTask::checkCycleTime()
{ 
    std::time_t v_act_time = getTime();
    auto time_passed = v_act_time - m_time;
    #if (SERIAL_DEBUG_ON && SERIAL_DEBUG_MACHINE)
        std::cout<<"Synchro Task time: " << m_time
            <<" cycle time: "<<  m_task_cycle_time
            << " act time: " <<v_act_time 
        <<std::endl;
    #endif
    std::cout<<" time left: "<< m_task_cycle_time-time_passed<<std::endl;
    if (time_passed > m_task_cycle_time){
        //std::cout<< "Time To do Sth"<<std::endl;  
        m_time = getTime();
        return true;
    }
    else{
        //std::cout<< "Still have :"<< m_task_cycle_time -(v_act_time - m_time) << "ms left"<<std::endl;
        return false;
    }
}
