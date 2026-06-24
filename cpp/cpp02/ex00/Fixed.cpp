#include "Fixed.hpp"

Fixed::Fixed() //Default constructor
{
    std::cout << "Default Constructor called. " << std::endl;
    _value = 0;
}

Fixed::Fixed(const Fixed& other) //copy constructor 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other; //"other" represents a second object of the same class
}

Fixed& Fixed::operator=(const Fixed & other) //copy assignment constructor
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _value = other.getRawBits(); //assign if this pointer has not been copied to that of "other"
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}