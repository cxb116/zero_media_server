//
// Created by cbb on 2024/11/23.
//

#ifndef ZERO_MEDIA_SERVER_PATH_H
#define ZERO_MEDIA_SERVER_PATH_H
#include <string>
#include <unistd.h>
#include <limits.h>
#include <memory>

using namespace std;

class Path {
public:
    Path() {}
    ~Path() {}
public:
    static string exePath();
    static string exeDir();
    static string exeName();

};


#endif //ZERO_MEDIA_SERVER_PATH_H
