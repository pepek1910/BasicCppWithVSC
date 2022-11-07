#pragma once
#include <iostream>
#include "SynchEvent.h"
#include "IEvent.h"

class ClockSynchEvent : public SynchEvent, public IEvent
{
public:
    ClockSynchEvent(int p_event_cycle_time = def_event_cycle_time);
    ~ClockSynchEvent() = default;

    virtual void Spin() override;
    virtual void print(std::ostream& os) const override;

private:
    static constexpr int def_event_cycle_time = 1000;
};