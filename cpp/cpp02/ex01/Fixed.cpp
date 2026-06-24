#include "Fixed.hpp"

Fixed::Fixed() //Default constructor
{
    std::cout << "Default Constructor called. " << std::endl;
    _value = 0;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    _value = n << _fractionalbits; //converts to fixed point int using bitwise operations
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(n * (1 << _fractionalbits)); //converts to fixed point value using bitwise operations & multiplication
                                                //1 << 8 converts it to 256
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

float Fixed::toFloat(void) const
{
    return((float)_value / (1 << _fractionalbits));
}

int Fixed::toInt(void) const
{
    return(_value >> _fractionalbits);
}

//used to teach compiler how to print variable of Fixed class, usually compiler only knows ur standard variables
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat(); //"out <<": pushes converted flat value into output stream
                            //"fixed.toFloat() calls member function to convert fixed point int to readable float" 
    return (out);
}