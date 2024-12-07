//
// Created by cbb on 2024/11/27.
//

#ifndef ZERO_MEDIA_SERVER_TASKQUEUE_H
#define ZERO_MEDIA_SERVER_TASKQUEUE_H
#include <mutex>
#include "../utils/List.h"
#include "semaphore.h"
// 实现一个基于函数对象的任务队列，该任务队列是线程安全的，任务队列任务数由信号量控制

template <typename T>
class TaskQueue {
public:
    //加入任务队列
    template<typename T1>
    void push_task(T1 &&task_func){
        {
            std::lock_guard<decltype(mutex_)> lock(mutex_);
            queue_.emplace_back(std::forward<T1>(task_func));
        }
        sem_.post();
    }

    template<class T1>
    void push_task_first(T1 &&task_func) {
        {
            std::lock_guard<decltype(mutex_)> lock(mutex_);
            queue_.emplace_front(std::forward<T1>(task_func));
        }
        sem_.post();
    }

    // 清空任务队列
    void push_exit(size_t n) {
        sem_.post(n);
    }

    // 从列队获取任务，由执行线程执行
    bool get_task(T &task) {
        sem_.wait();
        std::lock_guard<decltype(mutex_)> lock(mutex_);
        if(queue_.empty()) {
            return false;
        }
        task = std::move(queue_.front());
        queue_.pop_front();
        return true;
    }

    size_t size() const {
        std::lock_guard<decltype(mutex_)> lock(mutex_);
        return queue_.size();
    }

private:
    List<T> queue_;
    mutable std::mutex mutex_;
    semaphore sem_;
};

#endif //ZERO_MEDIA_SERVER_TASKQUEUE_H
