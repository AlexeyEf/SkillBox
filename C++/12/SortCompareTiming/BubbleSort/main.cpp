#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

//сортировка пузырьком

// при 10 элементов сортирует ~2*10^-6 сек
// при 15 элементов сортирует ~2*10^-6 сек
// при 100 элементов сортирует ~2.3*10^-5 сек
// при 500 элементов сортирует ~5*10^-4 сек
// при 1000 элементов сортирует ~2.5 мсек
// при 10 тыс элементов сортирует ~260 мсек
// при 100 тыс элементов сортирует ~25 сек
// при 1 млн элементов сортирует ~42 мин

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

    for(int i = 0, j = 0, temp = 0; i < size; ++i)
    {
        for(j = 0; j < size - i - 1; ++j)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    t = std::clock() - t;

    std::cout << "Count of elements = " << size << ", time of algorithm = " << (float)t/CLOCKS_PER_SEC << std::endl;

    return 0;
}
