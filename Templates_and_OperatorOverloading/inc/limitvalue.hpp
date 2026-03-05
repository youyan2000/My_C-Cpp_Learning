#ifndef LIMITVALUE_H
#define LIMITVALUE_H

// 模板类完整定义（包含所有成员函数）
template <typename T>
class LimitValue {
private:
    T current_value;
    T min_value;
    T max_value;

    // 限制值范围的核心函数
    void clamp(T& val) {
        if (val < min_value) val = min_value;
        if (val > max_value) val = max_value;
    }

public:
    // 构造函数
    LimitValue(T init_val, T min_val, T max_val) 
        : current_value(init_val), min_value(min_val), max_value(max_val) {
        clamp(current_value);
    }

    // 重载 -= 运算符（必须是成员函数，返回引用）
    LimitValue<T>& operator-=(const T& val) {
        current_value -= val;
        clamp(current_value);
        return *this;
    }

    // 重载 += 运算符（补充，方便测试）
    LimitValue<T>& operator+=(const T& val) {
        current_value += val;
        clamp(current_value);
        return *this;
    }

    // getValue 方法（必须是 public 且返回 T 类型）
    T getValue() const {
        return current_value;
    }
};

#endif