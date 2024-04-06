// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    const char* cstr = "It is a very smart function!";
    std::cout << "Function faStr1: " << faStr1(cstr) << std::endl;
    std::cout << "Function faStr2: " << faStr2(cstr) << std::endl;
    std::cout << "Function faStr3: " << faStr3(cstr) << std::endl;
    return 0;
}
