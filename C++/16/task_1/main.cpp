#include <iostream>
#include <iomanip>


int main()
{
    float speed = 0.0f, speedDelta = 0.0f;
    std::cout << std::fixed << std::setprecision(1);

    do
    {
        speed += speedDelta;
        if(speed > 150)
        {
            std::cout << "Speed is too high. Max speed is 150 km/h" << std::endl;
            speed = 150;
        }
        std::cout << "speed: " << speed << std::endl;
        std::cout << "speed delta: ";
    }
    while((std::cin >> speedDelta) && (speed + speedDelta > 0.01));

    return 0;
}
