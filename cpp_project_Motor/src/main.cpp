#include <iostream>
#include "limitvalue.hpp"
#include "motor.hpp"

int main() {
    //test int type LimitValue
    LimitValue<int> servo_angle(90, 0, 180);
    servo_angle += 100;  // 90+100=190 → be limited as 180
    std::cout << "Servo angle after +=100: " << servo_angle.val() << std::endl;
    servo_angle -= 200;  // 180-200=-20 → be limited as 0
    std::cout << "Servo angle after -=200: " << servo_angle.val() << std::endl;
    servo_angle = 123;  // 123
    std::cout << "Servo angle after =123: " << servo_angle.val() << std::endl;

    //test float type LimitValue
    LimitValue<float> pwm_duty(50.5, 0.0, 100.0);
    pwm_duty += 60.0;  // 50.5+60=110.5 → be limited as 100.0
    std::cout << "PWM duty after +=60: " << pwm_duty.val() << std::endl;
    pwm_duty -= 150.0; // 100-150=-50 → be limited as 0.0
    std::cout << "PWM duty after -=150: " << pwm_duty.val() << std::endl;
    pwm_duty = 123.4;  // 123.4 → be limited as 100.0
    std::cout << "PWM duty after =123.4: " << pwm_duty.val() << std::endl;

    //test DJI Hardware Motor（CAN ID 0x201）
    IMotor* dji_motor = new DJIMotor(0x201);
    TestMotor(dji_motor, 500);  // First Control: Small Output
    TestMotor(dji_motor, 1000); // Second Control: Large Output
    TestMotor(dji_motor, 0);    // Third Control: Stop Output
    delete dji_motor; 
    
    //test Physical Simulation Motor
    IMotor* sim_motor = new SimMotor();
    TestMotor(sim_motor, 500);  // First Control: Small Output
    TestMotor(sim_motor, 1000); // Second Control: Large Output
    TestMotor(sim_motor, 0);    // Third Control: Stop Output
    delete sim_motor;

    return 0;
}
