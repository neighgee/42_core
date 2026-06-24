#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
            int _value;
            static const int _fractionalbits = 8;
    
    public:
            Fixed(); //default constructor
            Fixed(const int n); //constructor which only accpets int
            Fixed (const float n); //constructor which only accepts float
            Fixed(const Fixed& other); //copy consructor
            Fixed& operator=(const Fixed & other); //copy assignment operator overload
            ~Fixed(); //destructor

            int getRawBits(void) const;
            void setRawBits(int const raw);

            float toFloat(void) const;
            int   toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif