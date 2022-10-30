#include <iostream>
#include <vector>

char checkGame(const std::vector<std::string> strings);
char checkStrings(const std::vector<std::string> strings);
char checkOneString(const std::string str);
std::vector<char> countSymbols(const std::vector<std::string> strings);
std::vector<std::string> getColumns(const std::vector<std::string> strings);
std::vector<std::string> getDiags(const std::vector<std::string> strings);

int main()
{
    std::string str1 = "...";
    std::string str2 = "...";
    std::string str3 = "...";
    std::vector<std::string> strings {str1, str2, str3};
    int x = 0, y = 0;
    char input;

    for(int i = 0; i < 9 && checkGame(strings) == '.'; ++i)
    {
        if (i % 2 == 0)
        {
            std::cout << "Odd player turn" << std::endl;
            input = 'X';
        }
        else
        {
            std::cout << "Even player turn" << std::endl;
            input = 'O';
        }
        std::cout << "Input coordinates of position on the playing field:";
        std::cin >> x >> y;

        if ((x < 1) || (x > 3) ||
            (y < 1) || (y > 3))
        {
            std::cout << "Incorrect input, try again";
            --i;
            continue;
        }
        else if(strings[y - 1][x - 1] == 'X' ||
                strings[y - 1][x - 1] == 'O' )
        {
            std::cout << "This position has already been specified, try again";
            --i;
            continue;
        }

        strings[y - 1][x - 1] = input;

        std::cout << strings[0] << std::endl;
        std::cout << strings[1] << std::endl;
        std::cout << strings[2] << std::endl;
    }

    char gameWinner = checkGame(strings);

    if(gameWinner == 'X')
    {
        std::cout << "First player won" << std::endl;
    }
    else if(gameWinner == 'O')
    {
        std::cout << "Second player won" << std::endl;
    }
    else if(gameWinner == '.')
    {
        std::cout << "Nobody" << std::endl;
    }

    else if(gameWinner == '0')
    {
        std::cout << "Incorrect" << std::endl;
    }

    return 0;
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
