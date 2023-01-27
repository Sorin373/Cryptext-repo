#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

std::string text;

void readFile()
{
    std::ifstream inputTextFile("input.txt");
    if (!inputTextFile.good())
    {
        std::cerr << "Error: file can not be read!" << std::endl;
        return;
    }
    
    inputTextFile.seekg(0, std::ios::end);

    if (inputTextFile.tellg() == 0)
    {
        std::cout << "Error: the file is empty!" << std::endl;
        return;
    }

    inputTextFile.seekg(0, std::ios::beg);
    std::getline(inputTextFile, text);

    inputTextFile.close();
}

int main(int argc, char *argv[])
{
    // check if the program is being run with the correct number of command line arguments
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " [ -e | -d ] message key" << std::endl;
        std::cout << " -e : to encrypt the message" << std::endl;
        std::cout << " -d : to decrypt the message" << std::endl;
        return -1;
    }
    else if (argv[1] == "-h" || argv[1] == "--help")
    {
        std::cout << "Help: " << argv[0] << " [ -e | -d ] message key" << std::endl;
        std::cout << " -e : to encrypt the message" << std::endl;
        std::cout << " -d : to decrypt the message" << std::endl;
        return 0;
    }
    else
    {
        readFile();
        std::cout << text;
    }

    return 0;
}