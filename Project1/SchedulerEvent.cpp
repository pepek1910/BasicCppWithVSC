#include "SchedulerEvent.h"

void SchedulerEvent::Spin(void)
{
    std::cout<<"Spin from Scheduler Event"<<std::endl;
    printTime();
    auto actTime = getTime();
    std::cout<< "Time from SchedulerEvent Spin :" <<actTime <<std::endl;
    std::cout<< "mtime :" <<m_time <<" mscheduleCycleTime: "<< m_schedule_cycle_time <<" actTime "<<actTime <<std::endl;

    if (m_time + m_schedule_cycle_time < actTime){
        std::cout<< "Time To do Sth"<<std::endl;  
        m_time = getTime();
    }
    else{
        std::cout<< "Still have :"<< m_schedule_cycle_time -(actTime - m_time) << "ms left"<<std::endl;
    }
}

void SchedulerEvent::print(std::ostream& os) const {
    os.precision(2);
    os << std::fixed;
    os << "[SchedulerEvent-> type:" << int(EEventType::SCHEDULER) << "param: " << m_param << "]";
}

void SchedulerEvent::printTime(){
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::cout << (now->tm_year + 1900) << '-' 
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << " : "
         << now->tm_hour << ":"
         << now->tm_min
         << "\n";
}
std::time_t SchedulerEvent::getTime(){
//
    std::time_t v_time = {std::time(0)};
    return v_time;
}