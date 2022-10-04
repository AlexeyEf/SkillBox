#include <iostream>
#include <vector>

int main()
{
    int n;
    int x;
    std::cout << "Input vector size: ";
    std::cin >> n;
    std::vector<int> vec;
    std::cout << "Input number to delete: ";
    std::cin >> x;
    std::cout << "Input numbers: ";

    for(int i = 0, count = 0, temp = 0; i < n; ++i, ++count)
    {
        //можно ли записать число в вектор через push_back без дополнительной переменной?
        std::cin >> temp;
        vec.push_back(temp);
        if(vec[count] == x)
        {
            vec.pop_back(); // pop_back() не удаляет элемент из памяти. Она всего лишь сокращает размер size вектора
            --count; //и из-за того, что размер сокращен, необходимо уменьшать индекс
        }
    }

    std::cout << "Result: ";
    for(int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }

    return 0;
}
