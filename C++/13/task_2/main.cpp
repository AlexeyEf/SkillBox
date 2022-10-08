#include <iostream>
#include <vector>

int main()
{
    std::vector<float> prices = {15.75, 17.2, 5.8, 9.2, 10.7};
    std::vector<int> items = {2, 4, 0, 1, 3};
    int sum = 0;

    for(int i = 0; i < prices.size(); ++i)
    {
       sum += prices[items[i]];
    }

    std::cout << "Cost of purchases = " << sum << std::endl;

    return 0;
}
