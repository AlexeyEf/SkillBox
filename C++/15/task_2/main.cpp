#include <iostream>
#include <vector>
#include <algorithm>

//algorithm for nlog(n)
int main()
{
    int num = 0, result = 0;
    std::vector<int> arr;//{-2,1,-3,4,-1,2,1,-5,4};
    std::cout << "Input result number: ";
    std::cin >> result;
    std::cout << "Input array: ";
    while(std::cin >> num)
        arr.push_back(num);
    //sorting
    std::sort(arr.begin(), arr.end());
    int leftIndex = 0, rightIndex = arr.size() - 1;
    //searching value
    while(leftIndex != rightIndex)
    {
        if(arr[leftIndex] + arr[rightIndex] == result)
        {
            break;
        }
        else if(arr[leftIndex] + arr[rightIndex] < result)
        {
            ++leftIndex;
        }
        else if(arr[leftIndex] + arr[rightIndex] > result)
        {
            ++rightIndex;
        }
    }

    std::cout << "leftIndex = " << leftIndex << ", rightIndex = " << rightIndex << std::endl;
    return 0;
}
