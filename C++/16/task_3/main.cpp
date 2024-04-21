#include <iostream>

bool checkCommandString(std::string command);
int  getMathCommandIdx(std::string command);
char getMathCommandSign(std::string command);
std::string getFirstCommandPart(std::string command);
std::string getSecondCommandPart(std::string command);
bool checkDigitsCommandPart(std::string str);


int main()
{
    std::string command;
    std::cout << "Input calculate command in format: number1+-*/number2: " ;
    std::cin >> command;

    if(checkCommandString(command))
    {
        double number1 = std::stod(getFirstCommandPart(command));
        double number2 = std::stod(getSecondCommandPart(command));
        double result;
        char mathSign = getMathCommandSign(command);
        if(mathSign == '+')
        {
            result = number1 + number2;
        }
        else if(mathSign == '-')
        {
            result = number1 - number2;
        }
        else if(mathSign == '*')
        {
            result = number1 * number2;
        }
        else if(mathSign == '/')
        {
            result = number1 / number2;
        }
        std::cout << result;
    }
    else
    {
        std::cout << "Incorrect format input string";
    }

    return 0;
}

bool checkCommandString(std::string command)
{
    return (checkDigitsCommandPart(getFirstCommandPart(command)) &&
            checkDigitsCommandPart(getSecondCommandPart(command)));
}

int getMathCommandIdx(std::string command)
{
    int idx = 0, count = 0;
    for(int i = 0; i < command.length(); ++i)//
    {
        if(command[i] == '+' || command[i] == '-'
           || command[i] == '*' || command[i] == '/')
        {
            if (++count > 1)
            {
                break;
            }
            idx = i;
        }
    }
    return (count == 1) ? idx : (-1);
}

char getMathCommandSign(std::string command)
{
    return command[getMathCommandIdx(command)];
}

std::string getFirstCommandPart(std::string command)
{
    int idx = getMathCommandIdx(command);

    return (idx == (-1)) ? "-1" : command.substr(0, idx);
}

std::string getSecondCommandPart(std::string command)
{
    int idx = getMathCommandIdx(command);

    return ((idx == (-1)) ? "-1" : command.substr(idx + 1, command.length() - (idx + 1)));
}

bool checkDigitsCommandPart(std::string str)
{
    if ((str == "-1") ||
        (str.length() < 1) ||
        (str.length() > 15))
    {
        return false;
    }

    for(int i = 0; i < str.length(); ++i)
    {
        if (!(((str[i] >= '0') && (str[i] <= '9'))))
        {
            if(str[i] != '.')
            {
                return false;
            }
        }
    }
    return true;
}


