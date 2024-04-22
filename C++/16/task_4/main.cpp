#include <iostream>

enum class notes
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main()
{
    std::string inputStr;

    std::cout << "input notes: ";
    std::cin >> inputStr;

    std::string result;

    for(int i = 0; i < inputStr.length(); ++i)
    {
        if(i + 1 < inputStr.length())
        {
            if ((inputStr[i] == '1')&&(inputStr[i+1] == '6'))
            {
                result += "SOL ";
            }
            else if ((inputStr[i] == '3')&&(inputStr[i+1] == '2'))
            {
                result += "LA ";
            }
            else if ((inputStr[i] == '6')&&(inputStr[i+1] == '4'))
            {
                result += "SI ";
            }
            else if (inputStr[i] == '1')
            {
                result += "DO ";
            }
        }
        else
        {
            if (inputStr[i] == '1')
            {
                result += "DO ";
            }
        }
        if (inputStr[i] == '2')
        {
            result += "RE ";
        }
        else if (inputStr[i] == '4')
        {
            result += "MI ";
        }
        else if (inputStr[i] == '8')
        {
            result += "FA ";
        }

    }
    std::cout << result;

    return 0;
}
