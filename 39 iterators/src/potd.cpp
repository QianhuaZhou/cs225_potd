#include "potd.h"

// Your code here!
/** Returns the sum of elements between start to end. 
	The value at start is included, while the value at end is not.
	*/
double sum(vector<double>::iterator start, vector<double>::iterator end){
    double sum = 0;
    for(auto it = start; it != end; ++it){
        sum += *it;
    }
    return sum;
}

/** Returns an iterator that points to the element with the max_it value between start and end. */
vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end){
    vector<double>::iterator max_it = start;
    for(auto it = start; it != end; ++it){
        if(*max_it < *it) max_it = it;//make sure understand when to use *, when not
    }
    return max_it;
}

/** Sort, in descending order, part of an array between start to end. 
	Hint: use max_iter.
*/
void sort_vector(vector<double>::iterator start, vector<double>::iterator end){
    for(auto it = start; it != end; ++it){
        vector<double>::iterator max_it = max_iter(it, end);//auto max_it
        //std::swap(it, curr_max);
        if(max_it != it) std::swap(*it, *max_it);
    }
}

