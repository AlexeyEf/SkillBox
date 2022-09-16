#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

//Cортировка подсчетом   O(n)

// при 10 элементов сортирует ~2*10^-6 сек
// при 15 элементов сортирует ~2*10^-6 сек
// при 100 элементов сортирует ~2*10^-6 сек
// при 500 элементов сортирует ~7*10^-6 сек
// при 1000 элементов сортирует ~1.3*10^-5 сек
// при 10 тыс элементов сортирует ~0.28 мсек
// при 100 тыс элементов сортирует ~1.3 мсек
// при 1 млн элементов сортирует ~17 мсек
// при 10 млн элементов сортирует ~255 мсек
// при 100 млн элементов сортирует ~2.8 сек

int main()
{
    std::clock_t t;
    const int size = 10;
    const int range = 10;

    int* a = new int[size];

    int min = range;

    int* counters = new int[size]();

    std::srand(std::time(NULL));

    for(int i = 0; i < size; ++i)
    {
        a[i] = std::rand()%range;
        if(a[i] < min)
        {
            min = a[i];
        }
    }

    t = std::clock();

    for(int i = 0; i < size; ++i)
    {
        ++counters[a[i] - min];
    }

    for(int i = 0, k = 0; i < size; ++i)
    {
        for(int j = 0; j < counters[i]; ++j)
        {
            a[k++] = min + i;
        }
    }

    t = std::clock() - t;

    std::cout << "Count of elements = " << size << ", time of algorithm = " << (float)t/CLOCKS_PER_SEC << std::endl;

    return 0;
}
