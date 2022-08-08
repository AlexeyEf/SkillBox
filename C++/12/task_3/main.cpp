#include <iostream>
#include <cassert>

float travelTime(float distance, float speed);

int main()
{
    float distance = 0;
    float speed = 0;

    std::cout << "----------Calculating travel time------------" << std::endl;

    std::cout << "Input distance: " ;
    std::cin >> distance;
    std:: cout << "and speed: ";
    std:: cin >> speed;

    if(distance <= 0)
    {
        std::cout << "Invalid input: distance";
    }
    else
    {
        std::cout << "Travel time = " << travelTime(distance, speed) << " h";
    }
    return 0;
}

float travelTime(float distance, float speed)
{
    assert(speed > 0 && "Invalid input: speed");

    return (distance/speed);
}
