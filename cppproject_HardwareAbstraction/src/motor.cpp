#include "motor.hpp"

// ===================== IMotor =====================
IMotor::~IMotor() {
    printf("[IMotor] Destruct Base Class\n");
}

// ===================== DJIMotor =====================
DJIMotor::DJIMotor(int can_id) : can_id_(can_id), current_(0) {}

void DJIMotor::SetOutput(int current) {
    current_ = current;
    printf("[CAN BUS] ID: 0x%03X, Send Current: %d (mA).\n", can_id_, current_);
}

int DJIMotor::GetSpeed() const {
    return fake_speed_;
}

void DJIMotor::Update() {
    printf("[DJIMotor] Hardware motor status update. Current current: %d (mA).\n", current_);
}

DJIMotor::~DJIMotor() {
    printf("[DJIMotor] CAN ID 0x%03X destructed.\n", can_id_);
}

// ===================== SimMotor =====================
SimMotor::SimMotor() : velocity_(0.0), input_force_(0) {}

void SimMotor::SetOutput(int force) {
    input_force_ = force;
    printf("[SimMotor] Setting input force: %d. no hardware communication.\n", input_force_);
}

int SimMotor::GetSpeed() const {
    return static_cast<int>(velocity_);
}

void SimMotor::Update() {
    double acceleration = (input_force_ - resistance_) * delta_t_;
    velocity_ += acceleration;
    if (velocity_ < 0) velocity_ = 0;
    printf("[SimMotor] Physical simulation update. Current speed: %.2f (rpm).\n", velocity_);
}

SimMotor::~SimMotor() {
    printf("[SimMotor] Destruct SimMotor\n");
}

// ===================== Trial Function =====================
void TestMotor(IMotor* motor, int speed) {
    printf("\n===== Start Testing the Motor =====\n");
    motor->SetOutput(speed);
    motor->Update();
    printf("current speed: %d rpm\n", motor->GetSpeed());
    printf("===== End Testing the Motor =====\n\n");
}

