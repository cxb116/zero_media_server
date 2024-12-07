//
// Created by cbb on 2024/11/24.
//

#ifndef ZERO_MEDIA_SERVER_SEMAPHORE_H
#define ZERO_MEDIA_SERVER_SEMAPHORE_H

#include <mutex>
#include <condition_variable>
#include <semaphore.h>
class semaphore {
public:
    explicit semaphore(size_t initial = 0){
        sem_init(&sem_,0,initial);
    }

    ~semaphore() {
        sem_destroy(&sem_);
    }

    void post(size_t n = 1){
        while(n--) {
            sem_post(&sem_);
        }
    }

    void wait(){
        sem_wait(&sem_);
    }
private:
    sem_t sem_;
};


#endif //ZERO_MEDIA_SERVER_SEMAPHORE_H
