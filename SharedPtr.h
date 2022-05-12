#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <memory>
#include <iostream>

namespace MemoryManagement
{
    constexpr bool verbose = true;

    template <typename T>
    class SharedPtr
    {
        int* referenceCounter = nullptr;
        T* data;

        public:
        SharedPtr(size_t dataSize)
        {
            if constexpr (verbose) std::cout<<"in SharedPtr constructor"<<'\n';

            referenceCounter = new int;
            *referenceCounter = 1;

            if constexpr (verbose)
            {
                std::cout<<"reference counter="<<std::to_string(*referenceCounter)<<'\n';
            }
            
            data = new T[dataSize];
        }

        SharedPtr(SharedPtr& other)
        {
            if constexpr (verbose) std::cout<<"in SharedPtr copy constructor"<<'\n';
            referenceCounter = other.referenceCounter;
            
            if constexpr (verbose)
            {
            std::cout<<"new ref counter = "
                <<referenceCounter
                <<" old ref counter = "
                << other.referenceCounter
                << '\n';
            }

            (*referenceCounter)++;

            if constexpr (verbose)
            {
                std::cout<<"reference counter="<<std::to_string(*referenceCounter)<<'\n';
            }
        }

        ~SharedPtr()
        {
            if constexpr (verbose) std::cout<<"in SharedPtr destructor"<<'\n';

            (*referenceCounter)--;

            if constexpr (verbose)
            {
                std::cout<<"reference counter="<<std::to_string(*referenceCounter)<<'\n';
            }

            if (*referenceCounter == 0)
            {
                delete referenceCounter;
                delete[] data;
            }
        }
    };
}
#endif