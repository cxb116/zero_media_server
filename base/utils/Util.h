//
// Created by cbb on 2024/12/1.
//

#ifndef ZERO_MEDIA_SERVER_UTIL_H
#define ZERO_MEDIA_SERVER_UTIL_H
//#include <ctime>
//#include <cstdio>
//#include <cstring>
//#include <memory>
//#include <string>
//#include <sstream>
//#include <vector>
//#include <atomic>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include <atomic>
#include <unordered_map>

#define INSTANCE_IMP(class_name, ...) \
class_name &class_name::Instance() { \
    static std::shared_ptr<class_name> s_instance(new class_name(__VA_ARGS__)); \
    static class_name &s_instance_ref = *s_instance; \
    return s_instance_ref; \
}


namespace zero
{
    // 设置线程名
void setThreadName(const char* name);

    // 获取线程名
std::string getThreadName();

std::string demangle(const char *mangled);

class Any {
public:
    using Ptr = std::shared_ptr<Any>;
    Any() = default;
    ~Any() = default;

    Any(const Any &that) = default;
    Any(Any &&that) {
        type_ = that.type_;
        data_ = std::move(that.data_);
    }

    Any &operator = (const Any &that) = default;
    Any &operator = (Any &&that) {
        type_ = that.type_;
        data_ = std::move(that.data_);
        return *this;
    }

    template<typename T,typename... ArgsType>
    void set(ArgsType &&...args) {
        type_ = &typeid(T);
        data_ = reset(new T(std::forward<ArgsType>(args)...),[](void *ptr){delete(T *)ptr;});
    }

    template<typename T>
    void set(std::shared_ptr<T> data) {
        if(data) {
            type_ = &typeid(T);
            data_ = std::move(data);
        } else {
            reset();
        }
    }

    template <typename T>
    T &get(bool safe = true) {
        if(!data_) {
            throw std::invalid_argument("Any is empty ");
        }
        if (safe && !is<T>()) {
            throw std::invalid_argument("Any::get(): " + demangle(type_->name())+" unable case to  "
            + demangle(typeid(T).name()));
        }
        return *((T *)data_.get());
    }

    template<typename T>
    const T &get(bool safe = true) const {
        return const_cast<Any &>(*this).template get<T>(safe);
    }

    template<typename T>
    bool is() const {
        return type_ && typeid(T) == *type_;
    }

    operator bool () const { return data_.operator bool(); }
    bool empty() const { return !bool(); }

    void reset() {
        type_ = nullptr;
        data_ = nullptr;
    }

    Any &operator = (std::nullptr_t) {
        reset();
        return *this;
    }

    std::string type_name() const {
        if(!type_) {
            return "";
        }
        return demangle(type_->name());
    }

private:
    const std::type_info* type_ = nullptr;
    std::shared_ptr<void> data_;
};

}



#endif //ZERO_MEDIA_SERVER_UTIL_H
