#include <iostream>

bool initShell(bool shell[12][12]);
bool showShellOnScreen(bool shell[12][12]);
int  burstShell(bool shell[12][12], int beginX, int beginY, int endX, int endY);

int main()
{
    // инициализацию всего массива одним и тем же значением
    // нельзя ли осуществить таким образом: bool shell[12][12] = {true} ?
    bool shell[12][12];
    int beginX = 0;
    int beginY = 0;
    int endX = 0;
    int endY = 0;
    int count = 144;

    initShell(shell);
    showShellOnScreen(shell);

    do
    {
        std::cout << "Input begin and end coordinates of burst shell region in form beginX, beginY, endX, endY:";
        std::cin >> beginX >> beginY >> endX >> endY;

        if(!( beginX >= 0 && beginX < 12 &&
              beginY >= 0 && beginY < 12 &&
              endX   >= 0 && endX   < 12 &&
              endY   >= 0 && endY   < 12    ))
        {
            std::cout << "Input wrong, out of shell range indexes, try again" << std::endl;
            continue;
        }

        count -= burstShell(shell, beginX, beginY, endX, endY);
        std::cout << "count = " << count << " " << std::endl;
        showShellOnScreen(shell);

    }while(count > 0);

    return 0;
}

bool initShell(bool shell[12][12])
{
    for(int i = 0; i < 12; ++i)
    {
        for(int j = 0; j < 12; ++j)
        {
            shell[i][j] = true;
        }
    }
    return true;
}

bool showShellOnScreen(bool shell[12][12])
{
    for(int i = 0; i < 12; ++i)
    {
        for(int j = 0; j < 12; ++j)
        {
            if(shell[i][j])
            {
                std::cout << "O" << " ";
            }
            else
            {
                std::cout << "X" << " ";
            }
        }
        std::cout << std::endl;
    }
}

int burstShell(bool shell[12][12], int beginX, int beginY, int endX, int endY)
{
    int count = 0;
    for(int i = beginX; i <= endX; ++i)
    {
        for(int j = beginY; j <= endY; ++j)
        {
            if(shell[i][j])
            {
                shell[i][j] = false;
                ++count;
            }
        }
    }
    return count;
}
