#include <iostream>
#include <fstream> //allows you to read & write into files simulataneously
#include <sstream>
#include <string>


/* 
find() for algorithms: 
 -when found it returns an iterator pointing to the first occurence of that element
 -when not found it returns the end iterator of the range you searched
find() for strings: 
 -when found it returns the starting index of the first occurence
 -when not found it returns a special constant called std::string:npos */
std::string replacefile(std::string content, std::string s1, std::string s2)
{
    std::string result;
    size_t  position;
    size_t  start;

    start = 0;
    position = content.find(s1, start); //finds first occurence of s1
    while (position != std::string::npos) //npos represent position not found, find() returns that if position is not found
    {
        result += content.substr(start, position - start); //appends start till start of s1
        result += s2; //appends s2 into where s1 is supposed to be
        start = position + s1.length(); //move starting position past s1
        position = content.find(s1, start); //find s1 again & advance position to the next s1
    }
    result += content.substr(start); //appends any leftover from the last start
    return (result);
}

int main(int argc, char **argv)
{
    std::ifstream input;
    std::ofstream output;
    std::stringstream buffer;
    std::string content;
    std::string replaced;
    std::string output_file;

    if (argc != 4)
    {
        std::cerr << "This format is necessary: ./replace <file> <s1> <s2> " << std::endl;
        return (1);
    }
    if (std::string(argv[2]).empty())
    {
        std::cerr << "Error: s1 cannot be an empty string" << std::endl;
        return (1);
    }
    input.open(argv[1]);
    if (!input)
    {
        std::cerr << "Error: problem with input file" << std::endl;
        return (1);
    }
    buffer << input.rdbuf(); // basically copying, input.rdbuf returns a pointer to stream buffer of input
    content = buffer.str(); // converts raw data into an actual string
    input.close();
    replaced = replacefile(content, argv[2], argv[3]);
    output_file = std::string(argv[1]) + ".replace";
    output.open(output_file.c_str()); //converts to a c string, not c++
    if (!output)
    {
        std::cerr << "Error: output file creation failed" << std::endl;
        return (1);
    }
    output << replaced; //append replaced to output
    output.close();
    return (0);
}