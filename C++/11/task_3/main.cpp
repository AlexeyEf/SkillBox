#include <iostream>
#include <vector>
#include <cmath>

bool checkIpAddress(std::string ipAddress);
bool checkIpAddressDots(std::string ipAddress);
std::vector<std::string> getIpOctets(std::string ipAddress);
int  getDigitFromString(std::string str);
bool checkIpOctets(std::vector<std::string> ipOctets);


int main()
{
    std::string ipAddress;
    std::cout << "Input ip-address (IPv4): ";
    std::cin >> ipAddress;

    if(checkIpAddress(ipAddress))
    {
        std::cout << "Valid" << std::endl;
    }
    else
    {
        std::cout << "Invalid" << std::endl;
    }
    return 0;
}

bool checkIpAddress(std::string ipAddress)
{

    //правильно ли использовать ниже такую конструкцию?
    return (checkIpAddressDots(ipAddress) &&
            checkIpOctets(getIpOctets(ipAddress)));
}

bool checkIpOctets(std::vector<std::string> ipOctets)
{
    //нужна ли эта проверка?
    if(ipOctets.size() != 4)
    {
        return false;
    }

    std::string octetStr;

    for(int i = 0, octNumb = 0; i < ipOctets.size(); ++i)
    {
        octetStr = ipOctets[i];

        //может ниже вынести в отдельную функцию?
        if(octetStr.length() > 1)
        {
            if(octetStr[0] == '0')
            {
                return false;
            }
        }

        for(int j = 0; j < octetStr.length(); ++j)
        {
            if((octetStr[j] < '0') || (octetStr[j] > '9'))
            {
                return false;
            }
        }

        octNumb = getDigitFromString(octetStr);

        if((octNumb < 0) || (octNumb > 255))
        {
            return false;
        }
    }

    return true;
}

// проверка формата IP-адреса
bool checkIpAddressDots(std::string ipAddress)
{
    if(ipAddress.empty())
    {
        return false;
    }

    for(int i = 0, count = 0; i < ipAddress.length(); ++i)
    {
        if(ipAddress[i] == '.')
        {
            if((i == 0)                    ||
               (i+1 == ipAddress.length()) ||
               (ipAddress[i-1] == '.')     ||
               (ipAddress[i+1] == '.'))
            {
                return false;
            }
            ++count;
        }
        if(count > 3)
        {
            return false;
        }
    }
    return true;
}

std::vector<std::string> getIpOctets(std::string ipAddress)
{
    std::vector<std::string> result;
    std::string octet;

    for(int i = 0; i < ipAddress.length(); ++i)
    {
        if(ipAddress[i] == '.')
        {
            result.push_back(octet);
            octet.clear();
        }
        else
        {
            octet += ipAddress[i];
        }
        if(i+1 == ipAddress.length())
        {
            result.push_back(octet);
        }
    }
    return result;
}

int getDigitFromString(std::string str)
{
    if(str.empty())
    {
        return (-1);
    }

    int result = 0;

    for(unsigned j = 0, digit = 0; j < str.length(); ++j)
    {
        digit = str[j] - '0';
        result += digit * std::pow(10, str.length() - (j + 1));
    }

    return result;
}
