#include "PhoneBook.hpp"

//Phonebook handles adding/searching the contact details

//Constructor function
PhoneBook::PhoneBook(void)
{
    this->_count = 0;
    this->_next = 0;
}

//Destructor Function
PhoneBook:: ~PhoneBook(void)
{
}

//helper function that repeatedly asks user for input that is non-empty
//used to ask for the 5 fields in add
static std::string get_input(std::string prompt)
{
    std::string input; //empty string created

    while (input.empty()) //empty is a function that returns true if empty
    {
        std::cout << prompt; //will print the prompt as output
        if (!std::getline(std::cin, input)) //if reading fails, return empty string
            return ("");
        if (input.empty())
            std::cout << "Field cannot be empty" << std::endl;
    }
    return (input);
}

bool valid_num(std::string phone)
{
    size_t i = 0;
    if (phone.empty())
        return(false);
    if (phone[0] == '+')
    {    
        if (phone.length() == 1)
            return (false);
        i = 1;
    }
    while (i < phone.length())
    {
        if (phone[i] < '0' || phone[i] > '9')
            return (false);
        i++;
    }
    return(true);
}

//Function fills one contact, sores it inside contacts[next] until there is 8 contacts
void    PhoneBook::add(void)
{
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phonenumber;
    std::string darkestsecret;

    firstname = get_input("First Name: ");
    if (firstname.empty())
        return ;
    lastname = get_input("Last Name: ");
    if (lastname.empty())
        return ;
    nickname = get_input("Nickname: ");
    if (nickname.empty())
        return ;
    while (1)
    {
        phonenumber = get_input("Phone Number: ");
        if (phonenumber.empty())
            return ;
        if (valid_num(phonenumber))
            break ;
        std::cout << "You can only enter numbers." << std::endl;
    }
    darkestsecret = get_input("Darkest Secret: ");
    if (darkestsecret.empty())
        return ;
    this->_contacts[this->_next].setdetails(firstname, lastname, nickname, phonenumber, darkestsecret);
    this->_next++;
    if (this->_next == 8)
        this->_next = 0;
    if (this->_count < 8)
        this->_count++;
}

static std::string reduce_length(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + "."); //formatting according to subject
    return (str);
}

static void print_row(int index, Contact contact) //iomanip library used
{
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << reduce_length(contact.get_first()) << "|";
    std::cout << std::setw(10) << reduce_length(contact.get_last()) << "|";
    std::cout << std::setw(10) << reduce_length(contact.get_nick()) << std::endl;
}

static void print_full(Contact contact)
{
    std::cout <<"First name: " << contact.get_first() << std::endl;
    std::cout <<"Last name: " << contact.get_last() << std::endl;
    std::cout <<"Nickname: " << contact.get_nick() << std::endl;
    std::cout <<"Phone number: " << contact.get_phone() << std::endl;
    std::cout <<"Darkest secret: " << contact.get_darkest() << std::endl;
}

//const shows that members variables are not modified
void PhoneBook ::search(void) const
{
    std::string input;
    int index;
    int  i;
    if (this->_count == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return ;
    }
    std::cout << std::setw(10) << "Index" << '|';
    std::cout << std::setw(10) << "First Name" << '|';
    std::cout << std::setw(10) << "Last Name" << '|';
    std::cout << std::setw(10) << "Nickname" << std::endl;
    i = 0;
    while (i < this->_count)
    {
        print_row(i, this->_contacts[i]);
        i++;
    }
    std::cout << "What is the index?" << std::endl;
    if (!std::getline(std::cin, input))
        return ;
    if (input.length() != 1 || input[0] < '0' || input[0] > '7') // can only store 8 contacts
    {
        std::cout << "Invalid index." << std::endl;
        return ;
    }
    index = input[0] - '0';
    if (index < 0 || index >= this->_count)
    {
        std::cout << "Invalid index." << std::endl;
        return ;
    }
    print_full(this->_contacts[index]);
}