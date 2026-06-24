#include "Fixed.hpp"


int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return (0);
}

// int main( void ) 
// {
//     Fixed a(6);
//     Fixed b(2);
    
//     std::cout << "Comparison tests" << std::endl;
//     std::cout << "6 > 2: " << (a > b) << std::endl;
//     std::cout << "6 < 2: " << (a < b) << std::endl;
//     std::cout << "6 >= 2: " << (a >= b) << std::endl;
//     std::cout << "6 <= 2: " << (a <= b) << std::endl;
//     std::cout << "6 == 2: " << (a == b) << std::endl;
//     std::cout << "6 != 2: " << (a != b) << std::endl;

//     std::cout << std::endl;
//     std::cout << "Arithmetic tests" << std::endl;
//     std::cout << "6 + 2 = " << (a + b) << std::endl;
//     std::cout << "6 - 2 = " << (a - b) << std::endl;
//     std::cout << "6 / 2 = " << (a / b) << std::endl;

//     std::cout << std::endl;
//     std::cout << "Decrement tests" << std::endl;
//     std::cout << "a starts as: " << a << std::endl;
//     std::cout << "--a returns: " << --a << std::endl;
//     std::cout << "a is now: " << a << std::endl;
//     std::cout << "a-- returns: " << a-- << std::endl;
//     std::cout << "a is now: " << a << std::endl;

//     return (0);
// }
