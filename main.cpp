#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

class node
{
 public:
    char character;
    node *next;
};

node* head  = nullptr;

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

    return 0;
}