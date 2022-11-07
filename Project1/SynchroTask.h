#pragma once
#include <iostream>
#include <ctime>

class SynchroTask 
{
public:
    SynchroTask(int);
    ~SynchroTask() = default;
    void printTime();
    std::time_t getTime();
    bool checkCycleTime();
    int getCycleTime() const {return m_task_cycle_time;};
  
private:
    std::time_t m_time;
    int m_task_cycle_time;

private:
    static constexpr int def_task_cycle_time_in_seconds = 1000; 
};