#pragma once

#include <cstddef>
#include <iostream>
#include <list>

class Queue {
    public:
        int size() const;
        bool isEmpty() const;
        void enqueue(int value);
        int dequeue();
    private:
        std::list<int> l;
};