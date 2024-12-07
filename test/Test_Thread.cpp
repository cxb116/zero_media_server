//
// Created by cbb on 2024/11/22.
//
#include <iostream>
#include "../base/thread/threadgroup.h"

void fun1(){
    int i = 0;
    while (1) {
        std::cout<<"i:"<<i<<"\n";
    }
}

int main() {

    thread_group threadGroup;
//    thread_group threadGroup1 = threadGroup.create_thread(fun1());
}