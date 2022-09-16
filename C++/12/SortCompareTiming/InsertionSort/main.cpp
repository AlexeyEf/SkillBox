#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

//сортировка вставками

// при 10 элементов сортирует ~2*10^-6 сек
// при 15 элементов сортирует ~2*10^-6 сек
// при 100 элементов сортирует ~1*10^-5 сек
// при 500 элементов сортирует ~2*10^-4 сек
// при 1000 элементов сортирует ~8*10^-4 сек
// при 10 тыс элементов сортирует ~80 мсек
// при 100 тыс элементов сортирует ~7 сек
// при 1 млн элементов сортирует ~12 мин

int main()
{
    std::clock_t t;
    const int size = 10;
    const int range = 10;

    int* a = new int[size];

    std::srand(std::time(NULL));

    for(int i = 0; i < size; ++i)
    {
        a[i] = std::rand()%range;
    }

    t = std::clock();

    for(int i = 1, j = 0, temp = 0; i < size; ++i)
    {
        temp = a[i];

        for(j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j + 1] = a[j];
            a[j] = temp;
        }
    }

    t = std::clock() - t;

    std::cout << "Count of elements = " << size << ", time of algorithm = " << (float)t/CLOCKS_PER_SEC << std::endl;

    return 0;
}

