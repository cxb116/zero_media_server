//
// Created by cbb on 2024/12/1.
//

#ifndef ZERO_MEDIA_SERVER_FUNCTION_TRAITS_H
#define ZERO_MEDIA_SERVER_FUNCTION_TRAITS_H
#include <tuple>
#include <functional>
#include <cstdio>

namespace zero {

template<typename T>
struct function_traits;

template<typename Ret,typename... Args>
struct function_traits<Ret(Args...)> {
public:
    enum { arity = sizeof...(Args) };
    typedef Ret function_type(Args...);
    typedef Ret return_type;
    using stl_function_type = std::function<function_type>;
    typedef Ret(*pointer)(Args...);

    template<size_t I>
    struct args
    {
        static_assert(I < arity, "index is out of range, index must less than sizeof Args");
        using type = typename std::tuple_element<I, std::tuple<Args...> >::type;
    };


};


}

#endif //ZERO_MEDIA_SERVER_FUNCTION_TRAITS_H
