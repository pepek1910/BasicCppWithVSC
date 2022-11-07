#pragma once
#include <iostream>
#include "SynchroTask.h"
#include "AsynchroTask.h"

class ClockSchedulerEvent : public SynchroTask, public AsynchroTask
{
public:
    ClockSchedulerEvent(int p_task_cycle_time = def_task_cycle_time);
    ~ClockSchedulerEvent() = default;

    virtual void Spin() override;
    virtual void print(std::ostream& os) const override;

private:
    static constexpr int def_task_cycle_time = 1000;
};