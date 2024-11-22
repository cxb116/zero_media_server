//
// Created by cbb on 2024/11/21.
//

#include "Thread.h"
thread_local string g_threadName;
thread_local int g_tid = -1;

Thread::Thread() {
    std::cout<<"Thread \n";
}


Thread::~Thread() {
    std::cout << "~THread \n";
}

int Thread::getThreadId() {
    if(g_tid != -1) {
        return  g_tid;
    }
    // syscall(SYS_gettid) 调用了 gettid 系统调用，返回当前线程的 TID
    g_tid = syscall(SYS_gettid);
    return g_tid;
}
string Thread::getThreadName(){

    if(!g_threadName.empty()) {
        return g_threadName;
    }
    string name;
    name.resize(32);

    pthread_t tid = pthread_self();
    //获取内核及其接口中可见的线程名
    pthread_getname_np(tid,(char*)name.data(),name.size());
    cout<<"getThreadName==> name:"<<name.data()<<"  tid:"<<pthread_self()<<"\n";
    if(name.empty()) {
        return to_string((uint64_t)tid);
    }
    name.resize(strlen(name.data()));
    return name;
}
void Thread::setThreadName(const string& name) {
    assert(name.size() < 16);
    // 设置线程名在内核及其接口中可见。
    pthread_setname_np(pthread_self(),name.data());
    pthread_getname_np(pthread_self(),(char*)name.data(),name.size());
    cout<<"setThreadName==>  name:"<<name.data()<<"  tid:"<<pthread_self()<<"\n";
}


