#include <iostream>
#include <memory>
using namespace std;

// Static storage duration
int global = 100;

class Demo {
public:
    Demo(const char* name) : name(name) {
        cout << "Constructor: " << name << endl;
    }
    ~Demo() {
        cout << "Destructor: " << name << endl;
    }
private:
    const char* name;
};

// Static local variable
void static_local_example() {
    static Demo static_local("static_local");  // Constructed only once
    cout << "Function called" << endl;
}

int main() {
    cout << "=== Program Start ===" << endl;
    
    // Automatic storage duration
    Demo auto_obj("auto_obj");
    
    // Static local variable demonstration
    static_local_example();
    static_local_example();  // Second call, static_local will not be reconstructed
    
    // Dynamic storage duration
    Demo* dynamic_obj = new Demo("dynamic_obj");
    delete dynamic_obj;  // Must delete manually
    
    // Smart pointer (recommended)
    unique_ptr<Demo> smart_ptr(new Demo("smart_ptr"));
    // Automatically managed, no need to delete
    
    cout << "=== Program End ===" << endl;
    return 0;
}  // auto_obj and smart_ptr automatically destructed
