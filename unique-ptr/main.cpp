#include <iostream>
#include "unique_ptr.h"

int main()
{
    unique_ptr<int> ptr1(new int(5));
    std::cout << *ptr1 << std::endl;

    unique_ptr<int> ptr2(new int{7});
    unique_ptr<int> ptr3 = nullptr; // nullptr ctor
    ptr3 = nullptr; // nullptr assignment 

    ptr3 = std::move(ptr2);
    std::cout << *ptr3 << std::endl;

    // ptr1 = ptr3; // cannot copy assign
}
