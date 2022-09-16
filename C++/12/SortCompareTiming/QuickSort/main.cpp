#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

//Быстрая сортировка

// при 10 элементах сортирует ~8*10^-6 сек
// при 15 элементах сортирует ~9*10^-6 сек
// при 100 элементах сортирует ~2*10^-5 сек
// при 500 элементах сортирует ~7.7*10^-5 сек
// при 1000 элементах сортирует ~1.5*10^-4 сек
// при 10 тыс элементов сортирует ~1.6 мсек
// при 100 тыс элементов сортирует ~20 мсек
// при 1 млн элементов сортирует ~205 мсек
// при 10 млн элементов сортирует ~2 сек
// при 100 млн элементов сортирует ~20 сек

//Быстрая сортировка итеративным (нерекурсивным) алгоритмом
void quickSortI(int* arr, int size);

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

    quickSortI(a, size);

    t = std::clock() - t;

    std::cout << "Count of elements = " << size << ", time of algorithm = " << (float)t/CLOCKS_PER_SEC << std::endl;

    return 0;
}

void quickSortI(int* a, int size)
{
    int i, j;
    int left, right;
    int temp;
    int pivot;
    int pivotValue;
    std::stack<int> stk;

    left = 0;
    right = size - 1;
    pivot = 0;
    pivotValue = 0;
    stk.push(left);
    stk.push(right);

    do
    {
        right = stk.top();
        stk.pop();
        left = stk.top();
        stk.pop();

        i = left;
        j = right;

        pivot = (i + j)/2;
        pivotValue = a[pivot];

        do
        {
            while(a[i] < pivotValue)
            {
                ++i;
            }
            while(a[j] > pivotValue)
            {
                --j;
            }
            if(i <= j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                ++i;
                --j;
            }

        }while(i <= j);

        if(j > left)
        {
            stk.push(left);
            stk.push(j);
        }

        if(i < right)
        {
            stk.push(i);
            stk.push(right);
        }

    }while(!stk.empty());
}
