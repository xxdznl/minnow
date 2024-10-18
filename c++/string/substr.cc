#include <iostream>  
#include <vector>  
#include <algorithm>  
int main() {  
    std::string str = "abcde";
    std::string result = str.substr(3);//不标记终止位默认到尽头
    // 输出结果  result: de
    std::cout << "result: " << result << std::endl; 
  
    return 0;  
}




