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

    StateMachine(const StateMachine& source){
        std::cout << "StateMachine: Copy Constructor" << std::endl;
    }

    StateMachine(StateMachine&& source) {
        std::cout << "StateMachine: Move Constructor" << std::endl;
    }

    StateMachine& operator=(const StateMachine& source) {
        std::cout << "StateMachine: Copy Assignment" << std::endl;
        return *this;
    }

    StateMachine& operator=(StateMachine&& source) {
        std::cout << "StateMachine: Move Assignment" << std::endl;
        return *this;
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

inline void take_machine(StateMachine robot) {
    std::cout << "Inside take_machine" << std::endl;

}

inline void rule_of_five() {
    StateMachine robot;
    StateMachine robot2(robot);

    StateMachine robot3;
    StateMachine robot4(std::move(robot3));

    StateMachine robot5;
    StateMachine robot6;
    robot6 = robot5;

    StateMachine robot7;
    StateMachine robot8;
    robot8 = std::move(robot7);

    take_machine(robot);
}





