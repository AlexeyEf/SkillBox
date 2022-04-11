#include <iostream>

std::string encrypt_caesar(std::string str, short shift);
std::string decrypt_caesar(std::string str, short shift);

int main()
{
    short mode = 0;
    short shift = 0;
    std::string input;

    std::cout << "Input mode (0 for encrypt string, 1 for decrypt) : ";
    std::cin >> mode;
    std::cout << "Input shift (from 1 to 28): ";
    std::cin >> shift;
    std::cout << "Input string: ";
    std::cin.ignore();// погуглил, вставил эту функцию; не понимаю почему без нее getline не работает
    std::getline(std::cin, input);

    if(mode == 0)
    {
        std::cout << encrypt_caesar(input, shift);
    }
    else if(mode == 1)
    {
        std::cout << decrypt_caesar(input, shift);
    }
    else
    {
        std::cout << "You entered wrong input mode";
    }

    return 0;
}

std::string encrypt_caesar(std::string str, short shift)
{
    if(str.empty())
    {
        return "error, empty input string";
    }

    std::string result;

    for (int i = 0; i < str.length(); ++i)
    {
        if(!((str[i] >= 'A') && (str[i] <= 'Z') ||
             (str[i] >= 'a') && (str[i] <= 'z')))
        {
            result += str[i];
        }
        else if((str[i] >= 'A') &&
                (str[i] <= 'Z') &&
                ((str[i] + shift > 'Z') ||
                 (str[i] + shift < 'A')))
        {
            if(str[i] + shift > 'Z')
            {
                result += 'A' + shift - ('Z' - str[i] + 1 );
            }
            else if(str[i] + shift < 'A')
            {
                result += 'Z' + shift + (str[i] - 'A'  + 1 );
            }
        }
        else if((str[i] >= 'a') &&
                (str[i] <= 'z') &&
                ((str[i] + shift > 'z')||
                (str[i] + shift < 'a')))
        {
            if(str[i] + shift > 'z')
            {
                result += 'a' + shift - ('z' - str[i] + 1 );
            }
            else if(str[i] + shift < 'a')
            {
                result += 'z' + shift + (str[i] - 'a'  + 1 );
            }
        }
        else
        {
            result += str[i] + shift;
        }
    }
    return result;
}

std::string decrypt_caesar(std::string str, short shift)
{
    return encrypt_caesar(str, shift*(-1));
}
