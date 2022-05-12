#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <iostream>
#include <memory>
#include "SharedPtr.h"

int main()
{
    SharedPtr<int> a(10);
    SharedPtr<int> b(a);
    {
        SharedPtr<int> c(b);
    }
    
    return 0;
}

#endif