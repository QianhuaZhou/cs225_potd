//
// Write a templated function `fewer` which takes in two variables of the same
// type and returns whichever variable is fewer than (`<`) the other.
//
#pragma once

template<typename T> const T & fewer(const T &one, const T &two) {
    // your code here
    if(one < two) return one;
    return two;
}

