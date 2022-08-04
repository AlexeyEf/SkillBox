#include <iostream>
#include <vector>

char checkGame(const std::vector<std::string> strings);
char checkStrings(const std::vector<std::string> strings);
char checkOneString(const std::string str);
bool checkCorrectInputString(const std::string inputStr);
std::vector<char> countSymbols(const std::vector<std::string> strings);
std::vector<std::string> getColumns(const std::vector<std::string> strings);
std::vector<std::string> getDiags(const std::vector<std::string> strings);


int main()
{
    std::string str1;
    std::string str2;
    std::string str3;
    std::vector<std::string> strings;

    std::cout << "Input tic-tac-toe strings sequentially: " << std::endl;
    std::cin >> str1;
    std::cin >> str2;
    std::cin >> str3;

    while(!(checkCorrectInputString(str1) && checkCorrectInputString(str2) && checkCorrectInputString(str3)))
    {
        std::cout << "Invalid input" << std::endl;
        std::cout << "Input tic-tac-toe strings sequentially: " << std::endl;
        std::cin >> str1;
        std::cin >> str2;
        std::cin >> str3;
    }

    strings.push_back(str1);
    strings.push_back(str2);
    strings.push_back(str3);

    char gameWinner = checkGame(strings);

    if(gameWinner == 'X')
    {
        std::cout << "Petya won" << std::endl;
    }
    else if(gameWinner == 'O')
    {
        std::cout << "Vanya won" << std::endl;
    }
    else if(gameWinner == '.')
    {
        std::cout << "Nobody" << std::endl;
    }
        //корректно ли при возвр. типе char сообщать об ошибке с помощью символа '0'?
        //или лучше использовать пустой символ ''?
    else if(gameWinner == '0')
    {
        std::cout << "Incorrect" << std::endl;
    }

    return 0;
}

bool checkCorrectInputString(const std::string inputStr)
{
    if(inputStr.length() != 3)
    {
        return false;
    }

    //компилятор выдает предупреждение: comparison between signed and unsigned integer expressions
    //как его устранить?
    //как корректно сравнивать целые числа с размером контейнера?
    for(int i = 0; i < inputStr.length(); ++i)
    {
        if((inputStr[i] != 'X') && (inputStr[i] != 'O') && (inputStr[i] != '.'))
        {
            return false;
        }
    }
    return true;
}

std::vector<char> countSymbols(const std::vector<std::string> strings)
{
    std::vector<char> result = {0, 0};

    for(int i = 0; i < strings.size(); ++i)
    {
        for(int j = 0; j < strings[i].length(); ++j)
        {
            if(strings[i][j] == 'X')
            {
                ++result[0];
            }
            else if(strings[i][j] == 'O')
            {
                ++result[1];
            }
        }
    }

    return result;
}

char checkGame(const std::vector<std::string> strings)
{
    std::vector<char> countSymb = {0, 0};

    char result1;
    char result2;
    char result3;

    countSymb = countSymbols(strings);
    result1 = checkStrings(strings);
    result2 = checkStrings(getColumns(strings));
    result3 = checkStrings(getDiags(strings));

    if(result1 == '0' || result2 == '0' || result3 == '0'    ||
       (result1 != '.' &&  result2 != '.' && result3 != '.'  &&
        (result1 == result2 || result2 == result3 || result1 == result3)))
    {
        return '0';
    }
    else if(result1 == '.' && result2 == '.' && result3 == '.')
    {
        if((countSymb[0] == countSymb[1]) || (countSymb[0] - countSymb[1]) == 1)
        {
            return '.';
        }
        else
        {
            return '0';
        }
    }
    else if(result1 == 'X' || result2 == 'X' || result3 == 'X')
    {
        if((countSymb[0] - countSymb[1]) != 1)
        {
            return '0';
        }
        else
        {
            return 'X';
        }
    }
    else if(result1 == 'O' || result2 == 'O' || result3 == 'O')
    {
        if(countSymb[1] != countSymb[0])
        {
            return '0';
        }
        else
        {
            return 'O';
        }
    }
}

char checkStrings(const std::vector<std::string> strings)
{
    bool winner = false;
    char result;
    char resultFunc;

    for(int i = 0; i < strings.size(); ++i)
    {
        result = checkOneString(strings[i]);

        if((result == 'X') || (result == 'O'))
        {
            if(winner)
            {
                resultFunc = '0';
                return resultFunc;
            }
            else
            {
                winner = true;
                if(result == 'X')
                {
                    resultFunc = 'X';
                }
                else if(result == 'O')
                {
                    resultFunc = 'O';
                }
            }
        }
    }
    if(!winner)
    {
        resultFunc = '.';
    }
    return resultFunc;
}

char checkOneString(const std::string str)
{
    char result;
    //можно ли например объявить 2 переменные ниже типом char?
    //если диапазон счета маленький (например всегда до 100)
    //и если они не будут никогда содержать символов, а только цифры
    int countX = 0;
    int countO = 0;

    for(int i = 0; i < str.length(); ++i)
    {
        if(str[i] == 'X')
        {
            ++countX;
        }
        else if(str[i] == 'O')
        {
            ++countO;
        }
    }
    if(countX == 3)
    {
        result = 'X';
    }
    else if(countO == 3)
    {
        result = 'O';
    }
    else
    {
        result = '.';
    }
    return result;
}

std::vector<std::string> getColumns(const std::vector<std::string> strings)
{
    std::vector<std::string> result;
    std::string column;

    for(int j = 0; j < strings.front().length(); ++j)
    {
        for(int i = 0; i < strings.size(); ++i)
        {
            column.push_back(strings[i][j]);
        }
        result.push_back(column);
        column.clear();
    }
    return result;
}

std::vector<std::string> getDiags(const std::vector<std::string> strings)
{
    std::vector<std::string> result;
    std::string diag1;
    std::string diag2;

    for(int i = 0, j = 0; i < strings.size() && j < strings.front().length(); ++i, ++j)
    {
        diag1.push_back(strings[i][j]);
        diag2.push_back(strings[2 - i][j]);
    }
    result.push_back(diag1);
    result.push_back(diag2);

    return result;
}
