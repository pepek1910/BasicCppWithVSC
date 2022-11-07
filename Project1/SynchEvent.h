#pragma once
#include <iostream>
#include <ctime>

class SynchEvent 
{
public:
    SynchEvent(int);
    ~SynchEvent() = default;
    void printTime();
    std::time_t getTime();
    bool checkCycleTime();
    int getCycleTime() const {return m_event_cycle_time;};
  
private:
    std::time_t m_time;
    int m_event_cycle_time;

private:
    static constexpr int def_event_cycle_time_in_seconds = 1000; 
};