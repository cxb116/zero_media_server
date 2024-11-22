//
// Created by cbb on 2024/11/22.
//
#include <iostream>
#include "../base/utils/Thread.h"

int main() {
   // cout<<"Thread name:"<<Thread::getThreadName()<<"\n";
    cout<<"========================================\n";
    Thread::setThreadName("aike");
    cout<<"Thread name:"<< Thread::getThreadName()<<"\n";
//
//    cout<<"Thread tid: "<< Thread::getThreadId()<<"\n";


}