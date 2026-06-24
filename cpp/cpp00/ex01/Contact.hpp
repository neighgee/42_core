#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string> //has std::string class that atuo manages memory

//public: members accessible from outside class
//private:members cannot be accessed/viewed from outside class
//protected: only inherited classes & members  access members
class Contact
{

private: //members cannot be accessed/viewed from outside class
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact(void);  //constructor to initialise the contact
    ~Contact(void); //'~' is the destructor symbol

    //public member functions provides controlled access to private data
    //below is the setter function to interact with the variables from Contact
    void setdetails(std::string firstname,
                    std::string lastname,
                    std::string nickname,
                    std::string phonenumber,
                    std::string darkestsecret);
    
    //below are getter functions, allow outside code to read private values
    std::string get_first(void) const; //const is used to indicate that the function does not change the value, only read
    std::string get_last(void) const;
    std::string get_nick(void) const;
    std::string get_phone(void) const;
    std::string get_darkest(void) const;
};

#endif