#include <iostream>

bool initWorld(int world[][5][10]);
bool inputWorld(int world[][5][10]);
bool showHorizLevel(int level, int world[][5][10]);

int main()
{
    int world[5][5][10];
    int level = 0;

    initWorld(world);//инициализация трехмерного массива нулями
                     //int world[5][5][10] = {0}; не срабатывает - вопрос почему?

    std::cout << "Input height of each world point (from 1 to 10): " << std::endl;
    inputWorld(world);

    do
    {
        std::cout << "Input horizontal level you want to see (from 0 to 9): ";
        std::cin >> level;

    }while(level < 0 || level > 9);

    showHorizLevel(level, world);

    return 0;
}

bool initWorld(int world[][5][10])
{
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            for(int k = 0; k < 10; ++k)
            {
                world[i][j][k] = 0;
            }
        }
    }
    return true;
}

bool inputWorld(int world[][5][10])
{
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0, input = 0; j < 5; ++j)
        {
            std::cin >> input;
            for(int k = 0; k < input; ++k)
            {
                world[i][j][k] = 1;
            }
        }
    }
    return true;
}

bool showHorizLevel(int level, int world[][5][10])
{
    std::cout << "World slice: " << level << std::endl;

    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            std::cout << world[i][j][level] << " ";
        }
        std::cout << std::endl;
    }
    return true;
}
