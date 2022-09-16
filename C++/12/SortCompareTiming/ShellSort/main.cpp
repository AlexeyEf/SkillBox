#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

//сортировка Шелла

//сортировка с исп. простого алгоритма
// при 10 элементов сортирует ~2*10^-6 сек
// при 15 элементов сортирует ~2*10^-6 сек
// при 100 элементов сортирует ~8*10^-6 сек
// при 500 элементов сортирует ~4.6*10^-5 сек
// при 1000 элементов сортирует ~1*10^-4 сек
// при 10 тыс элементов сортирует ~1.6 мсек
// при 100 тыс элементов сортирует ~25 мсек
// при 1 млн элементов сортирует ~330 мсек
// при 10 млн элементов сортирует ~4.7 сек
// при 100 млн элементов сортирует ~74 сек

//сортировка с исп. алгоритма Седжвика
// при 10 элементов сортирует ~2*10^-6 сек
// при 15 элементов сортирует ~2*10^-6 сек
// при 100 элементов сортирует ~7*10^-6 сек
// при 500 элементов сортирует ~4*10^-5 сек
// при 1000 элементов сортирует ~9*10^-5 сек
// при 10 тыс элементов сортирует ~1.3 мсек
// при 100 тыс элементов сортирует ~19 мсек
// при 1 млн элементов сортирует ~220 мсек
// при 10 млн элементов сортирует ~2.6 сек
// при 100 млн элементов сортирует ~28 сек

//сортировка с исп. простого алгоритма
void shellSortB(int* a, int size);
//сортировка с исп. алгоритма Седжвика
void shellSortS(int* a, int size);

//вычисление интервала по алгоритму Сэджвика
int increment(int* interval, int size)
{
    int counter = -1, multiplier1 = 1, multiplier2 = 1, multiplier3 = 1;

    do
    {
        if(++counter % 2)
        {
            multiplier2 *= 2;
            interval[counter] = 8*multiplier1 - 6*multiplier2 + 1;
        }
        else
        {
            interval[counter] = 9*multiplier1 - 9*multiplier3 + 1;
            multiplier3 *= 2;
        }
        multiplier1 *= 2;
    }while(3*interval[counter] < size);

    return  ((counter > 0) ? (--counter) : (0));

}

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

    shellSortB(a, size);

    t = std::clock() - t;

    std::cout << "Count of elements = " << size << ", time of algorithm = " << (float)t/CLOCKS_PER_SEC << std::endl;

    return 0;
}

void shellSortB(int* a, int size)
{
    int interval = size / 2;

    while(interval > 0)
    {
        for(int i = interval, j = 0, temp = 0; i < size; ++i)
        {
            temp = a[i];

            for(j = i - interval; j >= 0 && a[j] > temp; j-=interval)
            {
                a[j + interval] = a[j];
                a[j] = temp;

            }
        }
        interval /= 2;
    }
}

void shellSortS(int* a, int size)
{
    int interval;
    int interval_arr[50];
    int counter;

    counter = increment(interval_arr, size);

    while(counter >= 0)
    {
        interval = interval_arr[counter--];

        for(int i = interval, j = 0, temp = 0; i < size; ++i)
        {
            temp = a[i];

            for(j = i - interval; j >= 0 && a[j] > temp; j-=interval)
            {
                a[j + interval] = a[j];
                a[j] = temp;

            }
        }
    }
}
