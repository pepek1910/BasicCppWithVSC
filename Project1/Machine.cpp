#include "Machine.h"

Machine::Machine()
{
    #if SERIAL_DEBUG_ON && SERIAL_DEBUG_MACHINE
        std::cout<<"machine # MachineInit() START"<<std::endl;
    #endif
    m_events.PushEvent(&m_events.asynchronousEvents , specificEvent);
    m_events.PushEvent(&m_events.asynchronousEvents , alarmEvent);

    m_events.PushEvent(&m_events.synchronousEvents , clockSchedulerEvent);
    m_events.PushEvent(&m_events.synchronousEvents , reminderSchedulerEvent);
}

Machine::~Machine(){
    std::cout<<"Machine Deconstructor"<<std::endl;
    delete specificEvent;
    delete alarmEvent;
    delete clockSchedulerEvent;
    delete reminderSchedulerEvent;
}

void Machine::Control()
{
    std::cout<< "Machine Control"<<std::endl;
    auto v_actState = machineStateController.GetState();
    switch(v_actState)
    {
        case MachineStateEnum::INITIALIZATION:
        {
            std::cout<<"State: INITIALIZATION"<<std::endl;
            Init();
            break;
        }
        case MachineStateEnum::READY:
        {
            std::cout<<"State: READY"<<std::endl;
            machineStateController.trySetState(MachineStateEnum::RUNNING);
            // #if BEGIN_WITH_SPECIFIC_ACTION == 0
            //     #if SPECIFIC_ACTION
            //         MachineSetState(EMachineState::SPECIFIC_ACTION);
            //         m_events.PushEvent(SEvent(EEventType::SPECIFIC_ACTION, 1));
            //     #else
            //         machineStateController.trySetState(MachineStateEnum::READY);
            //     #endif
            // #else
            //     if (m_events.PeekCurrentEventType() != m_events.EEventType::EVENTS_COUNT)
            //     {
            //         SEvent v_event = PopEvent();
            //         if (v_event.m_type == EEventType::SPECIFIC_ACTION)
            //         {
            //         #if SPECIFIC_ACTION
            //             MachineSetState(EMachineState::SPECIFIC_ACTION);
            //             PushEvent(SEvent(EEventType::SPECIFIC_ACTION, 1));
            //         #else
            //             MachineSetState(EMachineState::PRE_RUNNING);
            //         #endif
            //         }
            //     }
            // #endif
            break;
        }
        case RUNNING:
        {
            std::cout<<"State: RUNNING"<<std::endl;
            m_events.PeekCurrentAsynchEventType(&m_events.asynchronousEvents);
            m_events.checkSynchEvents(&m_events.synchronousEvents);
            //TODO need a way to not just Spin single cycle on Event, but stay in Event unless some action will be finished
            break;
        }
        case (ERROR):
        {
            std::cout<<"State: ERROR"<<std::endl;
            break;
        }
        case MachineStateEnum::MACHINE_STATE_ENUM_GUARD:
        {
            std::cout<<"State: MACHINE_STATE_ENUM_GUARD"<<std::endl;\
            break;
        }
    }
}

void Machine::Init()
{
    IEvent* alarmEvent2 = new AlarmEvent{};
    m_events.asynchronousEvents.push_back(alarmEvent2);
    machineStateController.trySetState(MachineStateEnum::READY);
}
