cmake -S . -B build #构建程序 
make -j8 #修改完后重新编译
cmake --build build --target check_webget #在名为 build 的目录中，使用 CMake 生成的构建系统（如 Makefile），构建名为 check_webget 的目标。
make check_webget #在build目录下,也可以生成目标程序 但是cmake 是将.txt转成makefile  make是根据makefile编译程序
