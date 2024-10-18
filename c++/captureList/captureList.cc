#include <iostream>  
#include <vector>  
#include <algorithm>  
  
int main() {  
    std::vector<int> vec = {1, 2, 3, 4, 5};  
    int sum = 0;  
  
    // // 使用 lambda 表达式，以引用方式捕获所有外部变量  
    // std::for_each(vec.begin(), vec.end(), [&]() {  
    //     sum += *this; // 注意：这里的 this 是不正确的，应使用外部变量，例如 *it  
    //     // 正确的做法是使用迭代器来访问元素，如下面的修正代码  
    // });  
  
    // 修正后的代码  
    std::for_each(vec.begin(), vec.end(), [&](int& value) {  
        sum += value; // 正确访问并修改外部变量 sum，以及当前元素 value  
    });  
  
    std::cout << "Sum: " << sum << std::endl; // 输出结果  
  
    return 0;  
}