#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

//Сортировка слиянием

// при 10 элементах сортирует ~3*10^-6 сек
// при 15 элементах сортирует ~3*10^-6 сек
// при 100 элементах сортирует ~1.5*10^-5 сек
// при 500 элементах сортирует ~6.8*10^-5 сек
// при 1000 элементах сортирует ~0.14 мсек
// при 10 тыс элементов сортирует ~1.6 мсек
// при 100 тыс элементов сортирует ~20 мсек
// при 1 млн элементов сортирует ~220 мсек
// при 10 млн элементов сортирует ~2.4 сек
// при 100 млн элементов сортирует ~27 сек


void mergeSort(int* arr, int left, int right);
//слияние
void merge(int* arr, int left, int right);

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

    mergeSort(a, 0, size - 1);

    t = std::clock() - t;

    std::cout << "Count of elements = " << size << ", time of algorithm = " << (float)t/CLOCKS_PER_SEC << std::endl;

    return 0;
}

void mergeSort(int* arr, int left, int right)
{
    if(right <= left)
    {
        return;
    }
    int mid = left + (right - left)/2;
    //сортируем левую часть массива
    mergeSort(arr, left, mid);
    //и правую часть
    mergeSort(arr, mid + 1, right);
    //слияние
    merge(arr, left, right);
}

void merge(int* arr, int left, int right)
{
    int i = left,
            mid = left + (right - left)/2,
            j = mid + 1,
            pos = 0;
    //массив, куда складываются элементы после слияния
    int* b = new int[right - left + 1];

    //алгоритм слияния
    while(i <= mid && j <= right)
    {
        //"перестановка" элементов
        if(arr[i] <= arr[j])
        {
            b[pos++] = arr[i++];
        }
        else
        {
            b[pos++] = arr[j++];
        }
    }

    //запись остатка непросмотренного массива
    while(i <= mid)
    {
        b[pos++] = arr[i++];
    }

    while(j <= right)
    {
        b[pos++] = arr[j++];
    }

    for(i = 0; i < pos; ++i)
    {
        arr[left + i] = b[i];
    }
    delete[] b;

}
