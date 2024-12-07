
//
// Created by cbb on 2024/11/27.
//
#include <iostream>
#include "../base/utils/List.h"

int main (){

    List<int> list;
    list.emplace_back(1);
    list.emplace_back(2);
    list.emplace_back(3);

    for(const auto& item: list){
        std::cout<<item<<"\n";
    }

    for(auto it = list.begin(); it !=list.end(); ++it) {
        std::cout<<"Element index： "<<*it<<"\n";
    }

}