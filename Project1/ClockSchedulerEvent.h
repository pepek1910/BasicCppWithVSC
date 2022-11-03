#pragma once
#include <iostream>
#include "Scheduler.h"
#include "IEvent.h"

class ClockSchedulerEvent : public Scheduler, public IEvent
{
public:
    ClockSchedulerEvent(int p_schedule_cycle_time = def_schedule_cycle_time);
    ~ClockSchedulerEvent() = default;

    virtual void Spin() override;
    virtual void print(std::ostream& os) const override;

private:
    static constexpr int def_schedule_cycle_time = 1000;
};