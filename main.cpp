#include <iostream>     //input/output operations
#include <fstream>      //file manipulation
#include <cstring>      //string manipulation

char text[1001], msg_enc[1001] = "", msg_dec[1001] = "";
unsigned int key;

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
    inputTextFile.get(text, 1001);
    inputTextFile.close();
}

void encrypt()
{
    for (unsigned int i = 0; i < strlen(text); i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            c = toupper(c);
            c = ((c - 65 + key) % 26) + 65;
        }

        msg_enc[i] += c;
    }
    strcpy(text, msg_enc);
}

void decrypt()
{
    for (unsigned int i = 0; i < strlen(text); i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            c = toupper(c);
            c = ((c - 65 - key + 26) % 26) + 65;
        }

        msg_dec[i] += c;
    }
    strcpy(text, msg_dec);
}

int main(int argc, char *argv[])
{
    // check if the program is being run with the correct number of command line arguments
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " [ -e | -d ] key" << std::endl;
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
        readFile();                 //change the text in the input file

        std::ofstream outputTextFile;
        outputTextFile.open("output.txt", std::fstream::app);
    
        key = std::stoi(argv[2]);   //converting the key

        if (!(key >= 1 && key <= 25))
        {
            std::cerr << "Invalid key! Key must be between 1 and 25" << std::endl;
            return -1;   
        }
        else
        {
            std::ofstream outputResetFile("input.txt");
            switch (argv[1][1])
            {
                case 'e':
                    encrypt();
                    std::cout << "Encrypted text: ";
                    std::cout << text << std::endl;
                    outputTextFile << "Key: " << key << std::endl;
                    outputTextFile << "E: " << text << std::endl << std::endl;
                    outputResetFile << text;
                    break;
                case 'd':
                    decrypt();
                    std::cout << "Decrypted text: ";
                    std::cout << text << std::endl;
                    outputTextFile << "Key: " << key << std::endl;
                    outputTextFile << "D: " << text << std::endl << std::endl;
                    outputResetFile << text;
                    break;
                default:
                    std::cout << "Invalid character" << std::endl;
                    break;
            }
            outputResetFile.close();
        }
        
        outputTextFile.close();
    }
    return 0;
}