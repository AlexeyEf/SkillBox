#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <ctime>

// при 10 элементов сортирует ~3*10^-6 сек
// при 15 элементов сортирует ~3*10^-6 сек
// при 100 элементов сортирует ~1*10^-5 сек
// при 500 элементов сортирует ~5*10^-5 сек
// при 1000 элементов сортирует ~1.1*10^-4 сек
// при 10 тыс элементов сортирует ~1.4 мсек
// при 100 тыс элементов сортирует ~19 мсек
// при 1 млн элементов сортирует ~205 мсек
// при 10 млн элементов сортирует ~2.3 сек
// при 100 млн элементов сортирует ~26 сек


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

    std::sort(a, a+size);

    t = std::clock() - t;

    std::cout << "Count of elements = " << size << ", time of algorithm = " << (float)t/CLOCKS_PER_SEC << std::endl;

    return 0;
}
