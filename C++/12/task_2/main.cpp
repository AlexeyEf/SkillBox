#include <iostream>

void sort(float* arr, int size);

int main()
{
    const int size = 15;
    float numbs[size];

    std::cout << "Input " << size << " float numbers: " << std::endl;

    for(int i = 0; i < size; ++i)
    {
        std::cin >> numbs[i];
    }

    sort(numbs, size);

    std::cout << "Sorted numbers: ";

    for(int i = 0; i < size; ++i)
    {
        std::cout << numbs[i] << " ";
    }

    return 0;
}

//Сортировка Шелла с использ. простого алгоритма вычисления интервала
void sort(float* arr, int size)
{
    int interval = size / 2;

    while(interval > 0)
    {
        for(int i = interval, j = 0, temp = 0; i < size; ++i)
        {
            //j = i - interval;
            temp = arr[i];

            for(j = i - interval; j >= 0 && arr[j] < temp; j-=interval)
            {
                //перестановка элементов
                arr[j + interval] = arr[j];
                arr[j] = temp;

            }
        }
        interval /= 2;
    }
}