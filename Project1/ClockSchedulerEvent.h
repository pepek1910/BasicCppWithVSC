#pragma once
#include <iostream>
#include "Scheduler.h"
#include "IEvent.h"

class ClockSchedulerEvent : public Scheduler, public IEvent
{
public:
    ClockSchedulerEvent()
    :Scheduler(v_schedule_cycle_time), IEvent{EEventType::SCHEDULER,0,0}{};
    ~ClockSchedulerEvent() = default;

    virtual void Spin() override;
    virtual void print(std::ostream& os) const override;

private:
    static constexpr int v_schedule_cycle_time = 100;
};