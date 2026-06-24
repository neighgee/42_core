#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
            int _value;
            static const int _fractionalbits = 8;
    
    public:
            Fixed(); //default constructor
            Fixed(const Fixed& other); //copy consructor
            Fixed& operator=(const Fixed & other); //copy assignment operator overload
            ~Fixed(); //destructor

            int getRawBits(void) const;
            void setRawBits(int const raw);
};


#endif