#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> arr;
    std::cout << "Input array: ";
    for(int i = 0, temp = 0; std::cin >> temp; ++i)
    {
        if(temp == -1)
        {
            if(i < 4)
            {
                std::cout << "Count of numbers < 5, please add more numbers" << std::endl;
                continue;
            }
            else
            {
                std::sort(arr.begin(), arr.end());
                std::cout << arr[4] << " ";
            }
        }
        else if(temp == -2)
        {
            break;
        }
        arr.push_back(temp);
    }
    return 0;
}
