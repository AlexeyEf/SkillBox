#include <iostream>
#include <vector>

int main()
{
    std::vector<int> db(20);
    int number = 0;
    int writeIndex = 0;

    while(number != -2)
    {
        std::cout << "Input number: ";
        std::cin >> number;
        if(number == -1)
        {
            std::cout << "Output: ";
            for(int i = 0; i < db.size(); ++i)
            {
                std::cout << db[i] << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            db.at(writeIndex) = number;
            (writeIndex + 1) < db.size() ? ++writeIndex : writeIndex = 0;
        }
    }
    return 0;
}