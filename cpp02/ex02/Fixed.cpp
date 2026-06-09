#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}//Default constructor

Fixed::Fixed(const int n)
{
    _value = n << _fractionalbits; //converts to fixed point int using bitwise operations
}

Fixed::Fixed(const float n)
{
    _value = roundf(n * (1 << _fractionalbits)); //converts to fixed point value using bitwise operations & multiplication
                                                //1 << 8 converts it to 256
}

Fixed::Fixed(const Fixed& other) //copy constructor 
{
    *this = other; //"other" represents a second object of the same class
}

Fixed& Fixed::operator=(const Fixed & other) //copy assignment constructor
{
    if (this != &other)
        _value = other._value; //assign if this pointer has not been copied to that of "other"
    return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
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

bool Fixed::operator>(const Fixed& other) const
{
    return (_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (_value < other._value);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (_value <= other._value);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (_value != other._value);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits (_value + other._value);
    return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits (_value - other._value);
    return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result.setRawBits (((long)_value * other._value) >> _fractionalbits); //need to shift after if not the result will become 16 bit
    return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    result.setRawBits (((long)_value << _fractionalbits) / other._value); //can shift before you divide as it will get cancelled out
    return (result);
}

Fixed& Fixed::operator++() //pre-increment, no parameters
{
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int) //parameters tells compiler it is post increment
{
    Fixed temp(*this);
    ++_value;
    return (temp);
}

Fixed& Fixed::operator--() //no parameters it is pre
{
    --_value;
    return *this;
}

Fixed Fixed::operator--(int) //parameters are here it is post
{
    Fixed temp(*this);
    --_value;
    return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b ? a : b); //ternary same as if else, if:use first condition, else: do 2nd
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b ? a : b);
}

//used to teach compiler how to print variable of Fixed class, usually compiler only knows ur standard variables
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat(); //"out <<": pushes converted flat value into output stream
                            //"fixed.toFloat() calls member function to convert fixed point int to readable float" 
    return (out);
}