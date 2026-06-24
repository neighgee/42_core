#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook  phonebook;
    std::string command;
    while (1)
    {
        std::cout << "Write your instruction please." << std::endl;
        if (!std::getline(std::cin, command))
            break ;
        if (command == "ADD")
            phonebook.add();
        else if (command == "SEARCH")
            phonebook.search();
        else if (command == "EXIT")
            break ;
    }
    return (0);
}