#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include <conio.h>

std::string text;
const char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
unsigned int key;
bool vDecrypt = false;

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

void encrypt()
{
    vDecrypt = true;
    std::cout << key;

    getch();
}

void decrypt()
{
    if (!vDecrypt)
        return;
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

        unsigned int menu;

        do
        {
            std::cout << "\033c";

            std::cout << "MENU" << std::endl;
            std::cout << "1. Encrypt message" << std::endl;
            std::cout << "2. Decrypt message" << std::endl;
            std::cout << "0. Exit"
                      << "\n\n";

            std::cout << "Choice: ";
            std::cin >> menu;

            switch (menu)
            {
            case 1:
                key = atoi(argv[2]);
                encrypt();
                break;
            case 2:
                break;
            }
        } while (menu != 0);
    }

    return 0;
}