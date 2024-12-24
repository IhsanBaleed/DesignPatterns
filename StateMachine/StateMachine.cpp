#include "StateMachine.hh"


void RobotState::set_context(StateMachine* context) {
    state_machine_context_ = context;
}

// Repair State ------------------------------------------------------------
void RepairState::sleep() {
    std::cout << "RepairState: Going to Sleep." << std::endl;
    state_machine_context_->update_state(std::make_unique<ChargingState>());
}

void RepairState::wakeUp() {
    std::cout << "RepairState: Waking up" << std::endl;
    state_machine_context_->update_state(std::make_unique<OperatingState>());
}

void RepairState::take_order() {
    std::cout << "RepairState: Taking order" << std::endl;
    state_machine_context_->update_state(std::make_unique<OperatingState>());
}

void RepairState::repair() {
    std::cout << "RepairState: Already repairing." << std::endl;
}   

// Operating State ------------------------------------------------------------
void OperatingState::sleep() {
    std::cout << "OperatingState: Going to Sleep." << std::endl;
    state_machine_context_->update_state(std::make_unique<ChargingState>());
}

void OperatingState::wakeUp() {
    std::cout << "OperatingState: Already a wake." << std::endl;
}

void OperatingState::take_order() {
    std::cout << "OperatingState: Already taking orders." << std::endl;
}

void OperatingState::repair() {
    std::cout << "OperatingState: Repairing" << std::endl;
    state_machine_context_->update_state(std::make_unique<RepairState>());
} 

// Charging State ------------------------------------------------------------
void ChargingState::sleep() {
    std::cout << "ChargingState: Already a sleep." << std::endl;
}

void ChargingState::wakeUp() {
    std::cout << "ChargingState: Waking up" << std::endl;
    state_machine_context_->update_state(std::make_unique<OperatingState>());
}

void ChargingState::take_order() {
    std::cout << "ChargingState: Taking order" << std::endl;
    state_machine_context_->update_state(std::make_unique<OperatingState>());
}

void ChargingState::repair() {
    std::cout << "ChargingState: Repairing" << std::endl;
    state_machine_context_->update_state(std::make_unique<RepairState>());
}

void state_machine_test() {

    std::cout << "State Machine Menu:\n";
    std::cout << "1. Start Charging\n";
    std::cout << "2. Take Order\n";
    std::cout << "3. Wakeup\n";
    std::cout << "4. Repair\n";
    std::cout << "Type 'exit' to quit\n";
    std::cout << "Enter your choice: \n";

    StateMachine robot;

    while (true) {

        std::string input;
        std::cin >> input;
    
        if (input == "exit") {
            break;
        } else if (input == "1") {
            robot.start_charging();
        } else if (input == "2") {
            robot.take_order();
        } else if (input == "3") {
            robot.wakeup();
        } else if (input == "4") {
            robot.repair();
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}