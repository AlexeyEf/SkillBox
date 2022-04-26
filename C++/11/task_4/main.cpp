#include <iostream>
#include <vector>

struct StrState
{
    bool valid = true;
    std::string winner;
};

StrState checkWinner(const std::vector<std::string> strings);
StrState checkStrings(const std::vector<std::string> strings);
StrState checkOneString(const std::string str);
std::vector<std::string> getColumns(std::vector<std::string> strings);
std::vector<std::string> getDiags(std::vector<std::string> strings);


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

    strings.push_back(str1);
    strings.push_back(str2);
    strings.push_back(str3);

    StrState gameWinner= checkWinner(strings);
    if(gameWinner.valid)
    {
        std::cout << gameWinner.winner << " won" << std::endl;
    }
    else
    {
        std::cout << "Incorrect" << std::endl;
    }

    return 0;
}

StrState checkWinner(const std::vector<std::string> strings)
{
    StrState result;

    if(strings.empty())
    {
        result.valid = false;
        return result;
    }

    StrState resultRow;
    StrState resultColumn;
    StrState resultDiag;

    resultRow = checkStrings(strings);
    resultColumn = checkStrings(getColumns(strings));
    resultDiag = checkStrings(getDiags(strings));

    result.valid = resultRow.valid && resultColumn.valid && resultDiag.valid &&
                   (!resultRow.winner.empty() || !resultColumn.winner.empty() ||
                   !resultDiag.winner.empty());

    //проверка если два победителя

    if(!resultRow.winner.empty())
    {
        result.winner = resultRow.winner;
    }
    else if(!resultColumn.winner.empty())
    {
        result.winner = resultColumn.winner;
    }
    else if(!resultDiag.winner.empty())
    {
        result.winner = resultDiag.winner;
    }

    return result;
}

std::vector<std::string> getColumns(std::vector<std::string> strings)
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

std::vector<std::string> getDiags(std::vector<std::string> strings)
{
    std::vector<std::string> result;
    std::string diag1;
    std::string diag2;

    for(int i = 0, j = 0; i < strings.size() && j < strings.front().length(); ++i, ++j)
    {
        diag1.push_back(strings[i][j]);
        diag2.push_back(strings[2 - i][2 - j]);
    }
    result.push_back(diag1);
    result.push_back(diag2);

    return result;
}

StrState checkOneString(const std::string str)
{
    StrState result;

    if(str.empty() || str.length() > 3)
    {
        result.valid = false;
        return result;
    }

    int countX = 0, countO = 0, countDot = 0;

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
        else if(str[i] == '.')
        {
            ++countDot;
        }
    }
    if(countX == 3)
    {
        result.winner = "Petya";
    }
    else if(countO == 3)
    {
        result.winner = "Vanya";
    }
    else if(countDot == 3)
    {
        result.winner = "Nobody";
    }
    else if((countX + countO + countDot) != 3)
    {
        result.valid = false;
    }

    return result;
}

StrState checkStrings(const std::vector<std::string> strings)
{
    StrState result;
    bool winner = false;

    for(int i = 0; i < strings.size(); ++i)
    {
        result = checkOneString(strings[i]);
        if(!result.valid)
        {
            break;
        }
        if(!result.winner.empty()) {
            if (winner) {
                result.valid = false;
                break;
            }
            winner = true;
        }
    }
    return result;
}
