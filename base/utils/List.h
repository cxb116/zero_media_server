//
// Created by cbb on 2024/11/27.
//

#ifndef ZERO_MEDIA_SERVER_LIST_H
#define ZERO_MEDIA_SERVER_LIST_H
#include <ctime>
#include <cstdio>
#include <cstring>
#include <memory>
#include <string>
#include <sstream>
#include <list>
#include <type_traits>

template<typename T>
class List : public std::list<T> {
public:
    template<typename ... Args>
    List(Args &&...args) : std::list<T>(std::forward<Args>(args)...){};

    ~List() = default;

    void append(List<T> &other) {
        if(other.empty()) {
            return;
        }
        this->insert(this->end(),other.begin(),other.end());
        other.clear();
    }

    template<typename FUNC>
    void for_each(FUNC &&func) {
        for(auto &t : *this) {
            func(t);
        }
    }

    template<typename FUNC>
    void for_each(FUNC &&func) const {
        for(auto &t : *this) {
            func(t);
        }
    }
};


#endif //ZERO_MEDIA_SERVER_LIST_H
