// FIN (very basic): https://www.youtube.com/watch?v=ZzaPdXTrSb8
// lesson #10: https://www.youtube.com/watch?v=TAB86Bt8Xi4

// Compile and run:
// g++ main.cpp includes/calcs.cpp -o main
// ./main

#include <iostream>

// type definition
typedef unsigned int age_t;
typedef unsigned char byte;



int main() {
    byte b = 255;
    std::cout << unsigned(b) << std::endl;
    return 0;
}