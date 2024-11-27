//
// Created by cbb on 2024/11/22.
//

#ifndef ZERO_MEDIA_SERVER_NONCOPYABLE_H
#define ZERO_MEDIA_SERVER_NONCOPYABLE_H


class noncopyable {
public:
    noncopyable(const noncopyable &) = delete;
    void operator=(const noncopyable &) = delete;
protected:
    noncopyable() = default;
    ~noncopyable() = default;
};


#endif //ZERO_MEDIA_SERVER_NONCOPYABLE_H
