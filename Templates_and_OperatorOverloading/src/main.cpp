#include <iostream>
#include "limitvalue.hpp"

int main() {
    // 测试 int 类型的 LimitValue
    LimitValue<int> servo_angle(90, 0, 180);
    servo_angle += 100;  // 90+100=190 → 被限制为 180
    std::cout << "Servo angle after +=100: " << servo_angle.getValue() << std::endl;
    servo_angle -= 200;  // 180-200=-20 → 被限制为 0
    std::cout << "Servo angle after -=200: " << servo_angle.getValue() << std::endl;

    // 测试 float 类型的 LimitValue
    LimitValue<float> pwm_duty(50.5, 0.0, 100.0);
    pwm_duty += 60.0;  // 50.5+60=110.5 → 被限制为 100.0
    std::cout << "PWM duty after +=60: " << pwm_duty.getValue() << std::endl;
    pwm_duty -= 150.0; // 100-150=-50 → 被限制为 0.0
    std::cout << "PWM duty after -=150: " << pwm_duty.getValue() << std::endl;

    return 0;
}
