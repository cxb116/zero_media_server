//
// Created by cbb on 2024/12/1.
//

#include "Util.h"
#include <string>
#include <sys/time.h>
#include <pthread.h>
namespace zero {
static std::string limitString(const char* name,size_t max_size) {
    std::string str = name;
    if(str.size() + 1 > max_size) {
        auto erased = str.size() + 1 - max_size + 3;
        str.replace(5,erased,"...");
    }
    return str;
}


void setThreadName(const char* name){
    pthread_setname_np(pthread_self(),limitString(name,16).data());
}

std::string getThreadName() {
    std::string ret;
    ret.resize(32);
    auto tid = pthread_self();
    pthread_getname_np(tid, (char *) ret.data(), ret.size());
    if (ret[0]) {
        ret.resize(strlen(ret.data()));
        return ret;
    }
    return std::to_string((uint64_t) tid);
};

std::string demangle(const char* mangled) {
    int status = 0;
    char *demangled = nullptr;
#if HAS_CXA_DEMANGLE
    demangled = abi::__cxa_demangle(mangled, nullptr, nullptr, &status);
#endif
   std::string out;
    if (status == 0 && demangled) { // Demangling succeeeded.
        out.append(demangled);
#ifdef ASAN_USE_DELETE
        delete [] demangled; // 开启asan后，用free会卡死
#else
        free(demangled);
#endif
    } else {
        out.append(mangled);
    }
    return out;
}
}




