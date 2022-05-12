#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <memory>
#include <iostream>

template <typename T>
class SharedPtr
{
    int* referenceCounter = nullptr;
    T* data;

    public:
    SharedPtr(size_t dataSize)
    {
        std::cout<<"in SharedPtr constructor"<<'\n';
        referenceCounter = new int;
        *referenceCounter = 1;
        std::cout<<"reference counter="<<std::to_string(*referenceCounter)<<'\n';
        data = new T[dataSize];
    }

    SharedPtr(SharedPtr& other)
    {
        std::cout<<"in SharedPtr copy constructor"<<'\n';
        referenceCounter = other.referenceCounter;
        
        std::cout<<"new ref counter = "
            <<referenceCounter
            <<" old ref counter = "
            << other.referenceCounter
            << '\n';
        (*referenceCounter)++;
        std::cout<<"reference counter="<<std::to_string(*referenceCounter)<<'\n';
    }

    ~SharedPtr()
    {
        std::cout<<"in SharedPtr destructor"<<'\n';

        (*referenceCounter)--;
        std::cout<<"reference counter="<<std::to_string(*referenceCounter)<<'\n';
        if (*referenceCounter == 0)
        {
            delete referenceCounter;
            delete[] data;
        }
    }
};

#endif