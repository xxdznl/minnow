#include <iostream>  
#include <vector>  
#include <utility> // for std::move  
  
class MyClass {  
public:  
    MyClass(int size) : data(new int[size]), size(size) {  
        std::cout << "Constructor called\n";  
    }  
  
    MyClass(const MyClass& other) : data(new int[other.size]), size(other.size) {  
        std::cout << "Copy constructor called\n";  
        std::copy(other.data, other.data + size, data);  
    }  
  
    MyClass& operator=(const MyClass& other) {  
        if (this == &other) return *this; // self-assignment check  
        delete[] data; // clean up existing resources  
        data = new int[other.size]; // allocate new resources  
        size = other.size;  
        std::copy(other.data, other.data + size, data); // copy data  
        return *this;  
    }  
  
    MyClass(MyClass&& other) noexcept : data(other.data), size(other.size) {  
        std::cout << "Move constructor called\n";  
        other.data = nullptr; // nullify other's data pointer  
        other.size = 0; // set other's size to 0  
    }  
  
    MyClass& operator=(MyClass&& other) noexcept {  
        if (this == &other) return *this; // self-move check  
        delete[] data; // clean up existing resources  
        data = other.data; // transfer ownership of resources  
        size = other.size;  
        other.data = nullptr; // nullify other's data pointer  
        other.size = 0; // set other's size to 0  
        return *this;  
    }  
  
    ~MyClass() {  
        delete[] data; // clean up resources  
        std::cout << "Destructor called\n";  
    }  
  
private:  
    int* data;  
    int size;  
};  
  
int main() {  
    MyClass a(10); // Constructor called  
    MyClass b(a);  // Copy constructor called  
    MyClass c = std::move(a); // Move constructor called, a is now in a valid but unspecified state  
    b = a; // Copy assignment, a's resources are copied to b  
    c = std::move(b); // Move assignment, b's resources are moved to c, b is now in a valid but unspecified state  
  
    return 0; // Destructors called in reverse order of construction  
}