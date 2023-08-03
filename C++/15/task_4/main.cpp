#include <iostream>
#include <vector>
#include <algorithm>

bool compare(int a, int b)
{
    return (abs(a) < abs(b));
}

int main()
{
    int num = 0;
    std::vector<int> arr;// = {-100, -50, -5, 1, 10, 15};
    std::cout << "Input array: ";
    while(std::cin >> num)
        arr.push_back(num);

    std::sort(arr.begin(), arr.end(), compare);

    for(int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
