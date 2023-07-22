#include <iostream>

//algorithm O(n) of Jay Kadane(1984)

int main()
{
    int length = 0;
    std::cout << "Input length of array: ";
    std::cin >> length;
    int arr[length];//{-2,1,-3,4,-1,2,1,-5,4};
    std::cout << "Input array of length " << length << ": ";
    for(int i = 0; i < length; ++i)
    {
        std::cin >> arr[i];
    }
    int sum = 0,
        ans = arr[0],
        l = 0,
        r = 0,
        minus_pos = -1;
    for(int i = 0; i < length; ++i)
    {
        sum += arr[i];
        if (sum > ans)
        {
            ans = sum;
            l = minus_pos + 1;
            r = i;
        }
        if (sum < 0)
        {
            sum = 0;
            minus_pos = i;
        }
    }
    std::cout << "Maximum summa from index l = "<< l << " to index r = " << r << std::endl;
    return 0;
}
