#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <cstdio>

/*Abstract Base Class for Motors (universal standard)*/
class IMotor {
public:
    virtual void SetOutput(int current) = 0; // Set Output
    virtual int GetSpeed() const = 0;        // Read Feedback
    virtual void Update() = 0;               // Refresh Status
    virtual ~IMotor();                       // Virtual Destructor
};

/*DJI Hardware Motor (derived class A)*/
class DJIMotor : public IMotor {
private:
    int can_id_;                  // CAN bus ID
    int current_;                 // current output to motor (mA)
    const int fake_speed_ = 1000; // Fixed feedback speed
public:
    // Constructor
    DJIMotor(int can_id);
    // rewrite base class pure virtual functions
    void SetOutput(int current) override;
    int GetSpeed() const override;
    void Update() override;
    // Destructor
    ~DJIMotor() override;
};

/*Physical Simulation Motor (derived class B)*/
class SimMotor : public IMotor {
private:
    double velocity_;               // Current Actual Rotational Speed
    int input_force_;               // Input Control Force
    const double resistance_ = 0.5; // Simulated Resistance
    const double delta_t_ = 0.01;   // Control Period (seconds)
public:
    // Constructor
    SimMotor();
    // Rewrite base class pure virtual functions
    void SetOutput(int force) override;
    int GetSpeed() const override;
    void Update() override;
    // Destructor
    ~SimMotor() override;
};

/*Trial Function*/
void TestMotor(IMotor* motor, int speed);

#endif 
