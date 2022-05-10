#include <iostream>

int main()
{
    std::string surnames[10];

    for(int i = 0; i < 10; ++i)
    {
        std::cout << "Input surname of the tenant of " << i+1 << " apartment:";
        std::cin >> surnames[i];
    }

    for(int i = 0, numb = 0; i < 3; ++i)
    {
        std::cout << "Input apartment number from 1 to 10:";
        std::cin >> numb;

        if((numb < 1) || (numb > 10))
        {
            std::cout << "Incorrect apartment number";
        }
        else if(surnames[numb-1].empty())
        {
            std::cout << "Unavailable surname array element";
        }
        else
        {
            std::cout << "Surname of the " << numb << " apartment tenant: " << surnames[numb-1] << std::endl;
        }
    }

    return 0;
}
