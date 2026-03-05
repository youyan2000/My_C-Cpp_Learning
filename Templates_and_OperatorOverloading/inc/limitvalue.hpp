#ifndef LIMITVALUE_H
#define LIMITVALUE_H

template <typename T>
class LimitValue {
private:
    T current_value;
    T min_value;
    T max_value;

    //core function to clamp the value within limits
    void clamp(T& val) {
        if (val < min_value) val = min_value;
        if (val > max_value) val = max_value;
    }

public:
    //core constructor
    LimitValue(T init_val, T min_val, T max_val) 
        : current_value(init_val), min_value(min_val), max_value(max_val) {
        clamp(current_value);
    }

    //reload = operator
    LimitValue<T>& operator =(const T& val) {
        current_value = val;
        clamp(current_value);
        return *this;
    }

    //reload += operator
    LimitValue<T>& operator +=(const T& val) {
        current_value += val;
        clamp(current_value);
        return *this;
    }

    //reload -= operator
    LimitValue<T>& operator -=(const T& val) {
        current_value -= val;
        clamp(current_value);
        return *this;
    }

    //getValue function
    T val() const {
        return current_value;
    }
};

#endif