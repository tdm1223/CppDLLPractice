#include <iostream>
#include "MathLibrary.h"
int main()
{
    // 피보나치 시퀀스 초기화
    fibonacci_init(1, 1);

    // overflow가 일어날때까지 피보나치 출력
    do {
        std::cout << fibonacci_index() << ": " << fibonacci_current() << std::endl;
    } while (fibonacci_next());
    std::cout << fibonacci_index() + 1 <<" Fibonacci sequence values fit in an unsigned 64-bit integer." << std::endl;
    while (1);
    return 0;
}