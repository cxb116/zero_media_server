//
// Created by cbb on 2024/11/23.
//

#include "Path.h"
string Path::exeDir() {
    auto path = exePath();
    return path.substr(0,path.rfind('/') + 1);
}

string Path::exePath() {
    char buffer[PATH_MAX * 2 + 1] = {0};
    int n = -1;
    // 读取符号链接的内容
    n = readlink ("/proc/self/exe",buffer,sizeof buffer);

    string filePath = "./";
    if (n > 0) {
        filePath = buffer;
    }
    return filePath;
}

string Path::exeName() {
    auto path = exePath();
    return path.substr(path.rfind('/') + 1);
}