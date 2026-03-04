#include <iostream>
#include "task2_1/stringlist.h"
#include "task2_2/stringlist2.h"

int main() {
    CStrings arrA;
    CStrings2 arrB;

    arrA.add_elem("123");
    std::cout << "Size of A: " << arrA.size() << std::endl;
    std::cout << "Size of B: " << arrB.size() << std::endl;
    arrA.add_elem("1234");
    std::cout << "Size of A: " << arrA.size() << std::endl;
    std::cout << "Size of B: " << arrB.size() << std::endl;
    arrB.add_elem("1");
    std::cout << "Size of A: " << arrA.size() << std::endl;
    std::cout << "Size of B: " << arrB.size() << std::endl;
    arrA.erase(1);
    std::cout << "Size of A: " << arrA.size() << std::endl;
    std::cout << "Size of B: " << arrB.size() << std::endl;




    return 0;
}
