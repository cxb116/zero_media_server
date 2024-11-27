//
// Created by cbb on 2024/11/24.
//

#ifndef ZERO_MEDIA_SERVER_THREADGROUP_H
#define ZERO_MEDIA_SERVER_THREADGROUP_H

#include <stdexcept>
#include <thread>
#include <unordered_map>
#include <memory>

class thread_group {
private:
    thread_group(thread_group const &);
    thread_group &operator=(thread_group const &);

public:
    thread_group() {}
    ~thread_group() {
       thread_map_.clear();
    }

    bool is_this_thread_in() {
        auto thread_id = std::this_thread::get_id();
        if(thread_id_ == thread_id) {
            return true;
        }
        return thread_map_.find(thread_id) !=thread_map_.end();
    }

    template<typename T>
    std::thread *create_thread(T &&threadFunc) {
        auto thread_new = std::make_shared<std::thread>(std::forward<T>(threadFunc));
        thread_id_ = thread_new.get();
        thread_map_[thread_id_] = thread_new;
        return thread_new.get();
    }

    void remove_thread(std::thread *thread) {
        auto it = thread_map_.find(thread->get_id());
        if (it != thread_map_.end()) {
            thread_map_.erase(it);
        }
    }

    void join_all() {
        if(is_this_thread_in()) {
            throw std::runtime_error("尝试加入thread_group");
        }
        for (auto &it : thread_map_) {
            if(it.second->joinable()) {
                it.second->join();
            }
        }
        thread_map_.clear();
    }

    size_t size() {
        return thread_map_.size();
    }

private:
    std::thread::id thread_id_;
    std::unordered_map<std::thread::id,std::shared_ptr<std::thread>> thread_map_;
};


#endif //ZERO_MEDIA_SERVER_THREADGROUP_H
