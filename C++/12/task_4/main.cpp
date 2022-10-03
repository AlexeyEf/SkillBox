#include <iostream>

int main()
{
    const int size = 15;
    int a[15];

    std::cout << " Input 15 consecutive positive integers, two of which are repeated: ";

    for(int i = 0; i < size; ++i)
    {
        std::cin >> a[i];
    }

    int x = a[0] - 15;//принимаю за минимальное значение
    int repeatNumb = 0;
    int8_t counters[2*size] = {0};//счетчик разброса значений

    for(int i = 0; i < size; ++i)
    {
        if(++counters[a[i] - x] > 1)
        {
            repeatNumb = a[i];
            break;
        }
    }

    std::cout << "Repeating number = "
              << repeatNumb << std::endl;

    return 0;
}