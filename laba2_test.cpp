#include "Matrix.h"
#include <iostream>
#include <cassert>

int main() {
    Matrix m1(3, 3);
    m1.fillRandom();
    std::cout << "Matrix 1" << std::endl;
    std::cout << m1 << std::endl;

    Matrix m2(3, 3);
    m2.fillRandom1();
    std::cout << "Matrix 2" << std::endl;
    std::cout << m2 << std::endl;

    Matrix m3 = m1 + m2;
    std::cout << "Sum" << std::endl;
    std::cout << m3 << std::endl;

    Matrix m4 = m1 - m2;
    std::cout << "Difference" << std::endl;
    std::cout << m4 << std::endl;

    Matrix m5 = m1 * m2;
    std::cout << "Multiply" << std::endl;
    std::cout << m5 << std::endl;

    assert(m1 != m2);
    assert(m1 == m1);

    return 0;
}