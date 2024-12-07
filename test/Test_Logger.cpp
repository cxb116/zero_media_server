//
// Created by cbb on 2024/12/2.
//


#include "../base/utils/Logger.h"
#include <iostream>
using namespace zero;
int main() {
    // 初始化终端输出:
    Logger::Instance().add(std::make_shared<ConsoleChannel>());
    std::cout<<"Logger::instance() \n";
    return 0;
}