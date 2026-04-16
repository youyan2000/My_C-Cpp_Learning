#include <iostream>
#include <memory>
#include <string>

class Resource {
public:
    Resource(const std::string& name) : name_(name) {
        std::cout << "Resource [" << name_ << "] 创建\n";
    }
    ~Resource() {
        std::cout << "Resource [" << name_ << "] 销毁\n";
    }
    void doWork() const {
        std::cout << "Resource [" << name_ << "] 工作中...\n";
    }
private:
    std::string name_;
};

// 演示 unique_ptr：独占所有权
void demo_unique() {
    std::cout << "\n=== unique_ptr 演示 ===\n";
    auto u1 = std::make_unique<Resource>("唯一资源");
    u1->doWork();

    // 转移所有权
    auto u2 = std::move(u1);
    if (!u1) std::cout << "u1 现在是空的\n";
    u2->doWork();

    // 离开作用域，u2 自动销毁 Resource
}

// 演示 shared_ptr：共享所有权
void demo_shared() {
    std::cout << "\n=== shared_ptr 演示 ===\n";
    auto s1 = std::make_shared<Resource>("共享资源");
    std::cout << "引用计数: " << s1.use_count() << "\n";

    {
        auto s2 = s1;  // 拷贝，引用计数增加
        std::cout << "进入内层作用域，引用计数: " << s1.use_count() << "\n";
        s2->doWork();
    } // s2 销毁，计数减少

    std::cout << "离开内层作用域，引用计数: " << s1.use_count() << "\n";
    // 离开外层作用域，s1 销毁，计数归零，Resource 被释放
}

// 演示 weak_ptr：打破循环引用，观察 shared_ptr
struct Node {
    std::string name;
    std::shared_ptr<Node> next;   // 强引用
    std::weak_ptr<Node> prev;     // 弱引用，避免循环

    Node(const std::string& n) : name(n) {
        std::cout << "Node [" << name << "] 创建\n";
    }
    ~Node() {
        std::cout << "Node [" << name << "] 销毁\n";
    }
};

void demo_weak() {
    std::cout << "\n=== weak_ptr 演示 ===\n";
    auto node1 = std::make_shared<Node>("Node1");
    auto node2 = std::make_shared<Node>("Node2");

    // 建立双向链接，prev 用 weak_ptr 不会增加强引用计数
    node1->next = node2;
    node2->prev = node1;  // weak_ptr 可从 shared_ptr 赋值

    std::cout << "node1 引用计数: " << node1.use_count() << "\n";
    std::cout << "node2 引用计数: " << node2.use_count() << "\n";

    // 使用 weak_ptr 时需要 lock() 提升为 shared_ptr
    if (auto prev = node2->prev.lock()) {
        std::cout << "node2 的前一个节点是: " << prev->name << "\n";
    }

    // 离开作用域，node1 和 node2 正确销毁（没有循环引用泄漏）
}

int main() {
    demo_unique();
    demo_shared();
    demo_weak();
    return 0;
}
