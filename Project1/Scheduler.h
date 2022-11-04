#pragma once
#include <iostream>
#include <ctime>

class Scheduler 
{
public:
    Scheduler(int);
    ~Scheduler() = default;
    void printTime();
    std::time_t getTime();
    bool checkCycleTime();
    int getCycleTime() const {return m_schedule_cycle_time;};
  
private:
    std::time_t m_time;
    int m_schedule_cycle_time;

private:
    static constexpr int def_schedule_cycle_time_in_seconds = 1000; 
};