#include "Contact.hpp"

//Contact stores one contact

//Constructor (a special function)
//Runs automatically when a Contact object is created
//this is a special pointer that exists in every non-static function
//-points to the current object
Contact::Contact(void)
{
    this->_firstName = ""; //set object's firstName to empty string
    this->_lastName = ""; // set object's lastName to empty string
    this->_nickName = "";
    this->_phoneNumber = "";
    this->_darkestSecret = "";

}

//Destructor Function ( a special function)
Contact::~Contact(void)
{
}

/*Implementation of setter function
'Contact::' needed to show that you are defining it for Contact class
varaibles are declared via set details and then saved into this Contact object's variable*/
void Contact::setdetails(std::string firstname,
                         std::string lastname,
                         std::string nickname,
                         std::string phonenumber,
                         std::string darkestsecret)
{
    this->_firstName = firstname;
    this->_lastName = lastname;
    this->_nickName = nickname;
    this->_phoneNumber = phonenumber;
    this->_darkestSecret = darkestsecret;
}

//function returns the firstname that was saved
std::string Contact::get_first(void) const
{
    return (this->_firstName);
}

std::string Contact::get_last(void) const
{
    return (this->_lastName);
}

std::string Contact::get_nick(void) const
{
    return (this->_nickName);
}

std::string Contact::get_phone(void) const
{
    return (this->_phoneNumber);
}

std::string Contact::get_darkest(void) const
{
    return (this->_darkestSecret);
}
