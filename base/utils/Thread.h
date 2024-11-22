//
// Created by cbb on 2024/11/21.
//

#ifndef ZERO_MEDIA_SERVER_THREAD_H
#define ZERO_MEDIA_SERVER_THREAD_H
#include <iostream>
#include <pthread.h>
#include <cstring>
#include <thread>
#include <unistd.h>
#include <sys/syscall.h>
#include <assert.h>
using namespace std;
class Thread {
public:
    Thread();
   ~Thread();
public:
    static int getThreadId();
    static string getThreadName();
    static void setThreadName(const string& name);
};


#endif //ZERO_MEDIA_SERVER_THREAD_H
