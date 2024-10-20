#include "Heap.h"
#include <iostream>

void Heap::_percolateDown(int hole) {//heapifyDown
    // your code here
    int size = _data.size() - 1;
    if(size < 1) return;
    int left_child = hole * 2;
    int right_child = left_child + 1;
    int currIdx = hole;
    if(left_child <= size && _data[left_child] > _data[currIdx]) currIdx = left_child;
    if(right_child <= size && _data[right_child] > _data[currIdx]) currIdx = right_child;
    if(currIdx != hole){
        std::swap(_data[currIdx], _data[hole]);
        _percolateDown(currIdx);
    }
    /*
    no recursive version
    int size = _data.size() - 1;
    if(size < 1) return;
    int value = _data[hole];
    while(hole * 2 <= size){
        int child = hole * 2;//left child index
        //right child exist and larger than left child
        int right_child = child + 1;
        if(right_child <= size && _data[right_child] > _data[child]){
            child++;//move to the right child
        }
        if(value >= _data[child]) break;
        _data[hole] = _data[child];
        hole = child;
    }
    _data[hole] = value;
    */
   
}

int Heap::size() const {
    return _data.size();
}

void Heap::enQueue(const int &x){
    _data.push_back(x);
    int hole = _data.size() - 1;
    for(; hole > 1 && x > _data[hole/2]; hole /= 2){
        _data[hole] = _data[hole/2];
    }
    _data[hole] = x;
}

int Heap::deQueue(){
    int minItem = _data[1];
    _data[1] = _data[_data.size() - 1];
    _data.pop_back();
    _percolateDown(1);
    return minItem;
}

void Heap::printQueue(){
    std::cout << "Current Priority Queue is: ";
    for(auto i = _data.begin() + 1; i != _data.end(); ++i){
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

std::vector<int> & Heap::getData() {
    return _data;
}
