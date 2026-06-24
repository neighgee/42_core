#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream> //used to perform input & output operations
# include <iomanip> //input/output manipulator library
# include <string> //enable the creation and manipulation of text


class  PhoneBook
{
private:
    Contact _contacts[8]; //there can only be 8 contacts
    int     _count;
    int     _next;

public:
    PhoneBook(void);
    ~PhoneBook(void);

    void add(void);
    void search(void) const;
};

#endif