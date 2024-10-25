#pragma once

#include <iostream>
#include <memory>

// forward declare to break circular dependency
class StateMachine;

/* The interface by which the state changes
* If we give the state a reference to the context/machine, this allows
* it to change the state without the need of doing that through the context
*/
class RobotState {

public:

    RobotState(std::string state) {
        std::cout << "RobotState: Current state = " << state << std::endl;
    }

    ~RobotState() {
        std::cout << "RobotState: Destructor" << std::endl;
    }
    
    virtual void sleep() = 0;
    virtual void wakeUp() = 0;
    virtual void take_order() = 0;
    virtual void repair() = 0;

    void set_context(StateMachine* context);

protected:
    StateMachine* state_machine_context_; 

};

class RepairState : public RobotState {

public:

    RepairState() : RobotState("RepairState") {}

    void sleep() override;
    void wakeUp() override;
    void take_order() override;
    void repair() override;
};

class OperatingState : public RobotState {

public:

    OperatingState() : RobotState("OperatingState") {}

    void sleep() override;
    void wakeUp() override;
    void take_order() override;
    void repair() override;
};

class ChargingState : public RobotState {

public:

    ChargingState() : RobotState("ChargingState") {}

    void sleep() override;
    void wakeUp() override;
    void take_order() override;
    void repair() override;
};

class StateMachine {   

public:
    StateMachine() {

        current_state_ = std::make_unique<ChargingState>();
        current_state_->set_context(this);
    }

    ~StateMachine() {
        std::cout << "StateMachine: Destructor" << std::endl;
    }

    void start_charging() {
        current_state_->sleep();
    }

    void stop_charging() {
        current_state_->wakeUp();
    }

    void wakeup(){ 
        stop_charging(); 
    }

    void take_order() {
        current_state_->take_order();
    }

    void repair() {
        current_state_->repair();
    }

    void update_state(std::unique_ptr<RobotState> state) {
        current_state_ = std::move(state);
        current_state_->set_context(this);
    }

private:
    std::unique_ptr<RobotState> current_state_;
};










