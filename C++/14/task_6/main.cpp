#include <iostream>

bool initArr1(int arr[5][5]);
bool initArr2(int arr[5][5]);
bool showArrOnScreen(int shell[5][5]);

int main()
{
    int arr[5][5];

    initArr2(arr);
    showArrOnScreen(arr);

    return 0;
}

//1 способ, c доп. переменной number
bool initArr1(int arr[5][5])
{
    for(int i = 0, number = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            arr[i][i%2 ? 4-j: j] = ++number;
        }
    }
    return true;
}

//2 способ, без доп. переменной number
bool initArr2(int arr[5][5])
{
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            arr[i][j] = (i%2)*((i+1)*5 - j) + ((i+1)%2)*(i*5 + j + 1);
        }
    }
    return true;
}

bool showArrOnScreen(int arr[5][5])
{
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
