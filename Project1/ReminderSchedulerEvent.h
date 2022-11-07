#pragma once
#include <iostream>
#include "SynchroTask.h"
#include "AsynchroTask.h"

class ReminderSchedulerEvent : public SynchroTask, public AsynchroTask
{
public:
    ReminderSchedulerEvent(int p_task_cycle_time = def_task_cycle_time);
    ~ReminderSchedulerEvent() = default;

    virtual void Spin() override;
    virtual void print(std::ostream& os) const override;

private:
    static constexpr int def_task_cycle_time = 50;
};