#include <iostream> //used to perform input & output operations
#include <cctype> //used to classify & transform indv characters


//std::cout used to print text to terminal
//std::endl used to insert newline & flush output buffer
//statid_cast<char>: explicit conversion to variable of type char
int main (int argc, char **argv)
{
    int i;
    int j;

    if (argc == 1) //if no other args
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 1;
    while (i < argc) //as long as there is 1 arg
    {
        j = 0;
        while(argv[i][j])
        {
            std::cout << static_cast<char>(std::toupper(argv[i][j])); //Uppercase int values of argv[i][j] converted to char
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return (0);
}