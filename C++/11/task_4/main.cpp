#include <iostream>
#include <vector>

//уместно ли использовать в качестве возвр. значений char и вектора из char
char checkGame(const std::vector<std::string> strings);
std::vector<char> checkStrings(const std::vector<std::string> strings);
std::vector<char> checkOneString(const std::string str);
bool checkCorrectInputString(const std::string inputStr);
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

    //правильно и корректно ли применять такую конструкцию ниже (3 функции подряд в условии цикла)?
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
        //корректно ли сообщать об ошибке в вызывающую функцию с помощью -1?
    else if(gameWinner == -1)
    {
        std::cout << "Incorrect" << std::endl;
    }

    return 0;
}

bool checkCorrectInputString(const std::string inputStr)
{
    if(inputStr.empty() || inputStr.length() != 3)
    {
        return false;
    }

    for(int i = 0; i < inputStr.length(); ++i)
    {
        if((inputStr[i] != 'X') && (inputStr[i] != 'O') && (inputStr[i] != '.'))
        {
            return false;
        }
    }
    return true;
}

char checkGame(const std::vector<std::string> strings)
{
    //целесообразно ли здесь объявлять 3 переменные?
    std::vector<char> result1 = {0, 0, 0};
    std::vector<char> result2 = {0, 0, 0};
    std::vector<char> result3 = {0, 0, 0};

    result1 = checkStrings(strings);
    result2 = checkStrings(getColumns(strings));
    result3 = checkStrings(getDiags(strings));

    //уместна ли здесь такая громоздкая конструкция?
    if(result1[2] == -1 || result2[2] == -1 || result3[2] == -1      ||
       result1[2] != '.' &&  result2[2] != '.' && result3[2] != '.'  &&
       (result1[2] == result2[2] || result2[2] == result3[2] || result1[2] == result3[2]))
    {
        return -1;
    }
    else if(result1[2] == '.' && result2[2] == '.' && result3[2] == '.')
    {
        return '.';
    }
    else if(result1[2] == 'X' || result2[2] == 'X' || result3[2] == 'X')
    {
        if((result1[0] - result1[1]) != 1)
        {
            return -1;
        }
        else
        {
            return 'X';
        }
    }
    else if(result1[2] == 'O' || result2[2] == 'O' || result3[2] == 'O')
    {
        if((result1[1] - result1[0]) != 1)
        {
            return -1;
        }
        else
        {
            return 'O';
        }
    }
}

std::vector<char> checkStrings(const std::vector<std::string> strings)
{
    bool winner = false;
    std::vector<char> resultFunc = {0, 0, 0}; //возвращение результата данной функции в формате
    //{сколько X, сколько O, победитель}
    std::vector<char> result = {0, 0}; //возвращение результата функции проверки одной строки
    //выдает количество знаков X или O в строке

    for(int i = 0; i < strings.size(); ++i)
    {
        result = checkOneString(strings[i]);

        for(int j = 0; j < result.size(); ++j)
        {
            resultFunc[j] += result[j];
        }

        if((result.at(0) == 3) || (result.at(1) == 3))
        {
            if(winner)
            {
                resultFunc[2] = -1;
                return resultFunc;
            }
            else
            {
                winner = true;
                if(result.at(0) == 3)
                {
                    resultFunc[2] = 'X';
                }
                else if((result.at(1) == 3))
                {
                    resultFunc[2] = 'O';
                }
            }
        }
    }
    if(!winner)
    {
        resultFunc[2] = '.';
    }
    return resultFunc;
}

std::vector<char> checkOneString(const std::string str)
{
    std::vector<char> result = {0, 0};

    for(int i = 0; i < str.length(); ++i)
    {
        if(str[i] == 'X')
        {
            ++result[0];
        }
        else if(str[i] == 'O')
        {
            ++result[1];
        }
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
