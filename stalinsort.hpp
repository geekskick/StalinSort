#pragma once 

#include <functional>
#include <iterator>
#include <vector>

template <typename InputIt,
          typename Compare = std::greater<typename std::iterator_traits<InputIt>::value_type> >
std::vector<typename std::iterator_traits<InputIt>::value_type>
stalinsort(InputIt first, InputIt last) {
    const auto cmp = Compare{};
    auto rc = std::vector<typename std::iterator_traits<InputIt>::value_type>(first, std::next(first));

    for(auto it = std::next(first); it != last; ++it){
        if(cmp(*it, rc.back())){
            rc.push_back(*it);
        }
    }
    return rc;
        
}