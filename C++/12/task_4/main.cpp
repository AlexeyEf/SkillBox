#include <iostream>

//Для сокращения используемой памяти
//использовал типы переменных
//в зависимости от возможных
//принимаемых значений этих переменных.
//Вместо int использовал тип int8_t,
//т.к. возможные значения этих переменных малы.
//Стоит ли вообще так поступать?
//В программистской практике так делают?

int main()
{
    const int8_t size = 15;
    int x;

    std::cout << " Input initial number X: ";
    std::cin >> x;

    int a[size] = {x+1, x+6, x+9, x+2, x, x+3, x+10, x+5,
                   x+3, x+4, x+13, x+11, x+8, x+12, x+7};

    int repeatNumb = 0;
    int8_t counters[size] = {0};

    for(int8_t i = 0; i < size; ++i)
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
