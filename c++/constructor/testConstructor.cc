#include <iostream>  
#include <vector>  
#include <utility> // for std::move  
  
class MyClass {  
public:  
    MyClass() { std::cout << "Default Constructor\n"; }  
    MyClass(const MyClass&) { std::cout << "Copy Constructor\n"; }  
    MyClass(MyClass&&) noexcept { std::cout << "Move Constructor\n"; }  
    ~MyClass() { std::cout << "Destructor\n"; }  
};  
  
void process(MyClass obj) {  
    // Do something with obj  
}  
  
int main() {  
    MyClass a; // 调用默认构造函数  
    MyClass b = a; // 调用拷贝构造函数  
    process(std::move(a)); // 调用移动构造函数（因为a被std::move转换为右值）  
    MyClass c = MyClass(); // 调用默认构造函数，然后调用移动构造函数（因为MyClass()是临时对象）  
  
    std::vector<MyClass> vec;  
    vec.push_back(MyClass()); // 调用默认构造函数，然后调用移动构造函数将临时对象添加到vector中  
  
    return 0;  
}

//explicit
//当多个构造函数重载时 编译出错
// void processFD(FDWrapper fd) {  
//     // 处理文件描述符...  
// }  
  
// void processFD(int fd) {  
//     // 直接处理文件描述符（不使用FDWrapper）...  
// }  
  
// int main() {  
//     int rawFD = 42; // 假设这是一个有效的文件描述符  
//     processFD(rawFD); // 这里会调用哪个函数？  
  
//     return 0;  
// }

//使用explicit关键字后，编译器将不再允许隐式转换，你必须显式地创建FDWrapper对象：
// int main() {  
//     int rawFD = 42; // 假设这是一个有效的文件描述符  
//     processFD(FDWrapper(rawFD)); // 显式创建FDWrapper对象  
//     // 或者  
//     FDWrapper wrappedFD(rawFD);  
//     processFD(wrappedFD); // 使用已创建的FDWrapper对象  
  
//     return 0;  
// }