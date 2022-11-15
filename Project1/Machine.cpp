#include "Machine.h"

Machine::Machine(ErrorChecker* p_error_checker): m_error_checker{p_error_checker}
{
    #if SERIAL_DEBUG_ON && SERIAL_DEBUG_MACHINE
        std::cout<<"machine # MachineInit() START"<<std::endl;
    #endif
    m_error_checker->SetStateController(&stateController);
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
    delete m_test_object;
}

void Machine::Control()
{
    std::cout<< "Machine Control"<<std::endl;
    auto v_actState = stateController.GetState();
    switch(v_actState)
    {
        case MachineStateEnum::INITIALIZATION:
        {
            std::cout<<"State: INITIALIZATION"<<std::endl;
            Init();
            //TODO pointer to  ErrorChecker.Start_error_checking(); or get directly into;
            break;
        }
        case MachineStateEnum::READY:
        {
            std::cout<<"State: READY"<<std::endl;
            stateController.trySetState(MachineStateEnum::RUNNING);
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
        case MachineStateEnum::RUNNING:
        {
            std::cout<<"State: RUNNING"<<std::endl;
            m_events.PeekCurrentAsynchEventType(&m_events.asynchronousEvents);
            m_events.checkSynchEvents(&m_events.synchronousEvents);
            m_test_object->Control();
            //TODO need a way to not just Spin single cycle on Event, but stay in Event unless some action will be finished
            break;
        }
        case MachineStateEnum::ERROR:
        {
            std::cout<<"State: ERROR"<<std::endl;
            resetController.Control();
            break;
        }
        case MachineStateEnum::RESETTING:
        {
            std::cout<<"State: RESETTING"<<std::endl;
            Reset();
            break;
        }
        case MachineStateEnum::FATAL_ERROR:
        {
            std::cout<<"State: FATAL_ERROR"<<std::endl;\
            break;
        }
        case MachineStateEnum::MACHINE_STATE_ENUM_GUARD:
        {
            std::cout<<"State: MACHINE_STATE_ENUM_GUARD"<<std::endl;\
            break;
        }
    }
}

void Machine::Reset()
{
    switch(m_resetState){
        case 1:
        {
            //reset all variables;
        }
        case 0:
        {
            stateController.trySetState(MachineStateEnum::READY);
        }
    }
}
void Machine::Init()
{
    IEvent* alarmEvent2 = new AlarmEvent{};
    m_events.asynchronousEvents.push_back(alarmEvent2);
    stateController.trySetState(MachineStateEnum::READY);
}
