#include <iostream>
#include <vector>

struct StrState
{
    bool valid;
    std::string winner;

};

std::string getElement(std::vector<std::string>, ushort xIndex, ushort yIndex);
bool checkTicTacToeStrings(std::vector<std::string> strings);
StrState checkWinner(std::vector<std::string> strings);
StrState checkRow(std::string row);
StrState checkColumn(std::string column);
StrState checkDiag(std::string column);


int main()
{
    std::string str1;
    std::string str2;
    std::string str3;
    std::vector<std::string> strings;


    std::cout << "Input tic-tac-toe strings sequentially: ";
    std::cin >> str1;
    std::cin >> str2;
    std::cin >> str3;

    strings.push_back(str1);
    strings.push_back(str2);
    strings.push_back(str3);

    if(checkTicTacToeStrings(strings))
    {
        if(checkWinner(strings))
        {
            std::cout << "Petya won" << std::endl;
        }
        else
        {
            std::cout << "Vanya won" << std::endl;
        }
    }
    else
    {
        std::cout << "Incorrect" << std::endl;
    }

    return 0;
}

bool checkTicTacToeStrings(std::vector<std::string> strings)
{
    if(strings.empty())
    {
        return false;
    }

    StrState state;

    for(int i = 0; i < strings.size(); ++i)
    {
        state = checkRow(strings[i]);

        if(!state.valid)
        {
            return false;
        }
        state.winner;

        for(int j = 0; j < strings[i].length(); ++j)
        {
            str = getElement(strings, i, j);
        }
    }
}

StrState checkWinner(std::vector<std::string> strings)
{
    if(strings.empty())
    {
        return StrState(false, "");

    }

    for(int i = 0; i < strings.size(); ++i)
    {

    }
}
