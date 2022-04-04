#include <iostream>


bool checkEMail(std::string eMail);
int  getSeparateEMailIdx(std::string eMail);
std::string getFirstEMailPart(std::string eMail);
std::string getLastEMailPart(std::string eMail);
bool checkFirstEMailPart(std::string str);
bool checkLastEMailPart(std::string str);

int main()
{
    std::string eMail;
    std::cout << "Input e-mail for verification: " ;
    std::cin >> eMail;

    if(checkEMail(eMail))
    {
        std::cout << "Yes";
    }
    else
    {
        std::cout << "No";
    }

    return 0;
}

bool checkEMail(std::string eMail)
{
    return (checkFirstEMailPart(getFirstEMailPart(eMail)) &&
            checkLastEMailPart(getLastEMailPart(eMail)));
}

int getSeparateEMailIdx(std::string eMail)
{
    int idx = 0, count = 0;
    for(int i = 0; i < eMail.length(); ++i)
    {
        if(eMail[i] == '@')
        {
            if (++count > 1)
            {
                break;
            }
            idx = i;
        }
    }
    return (count == 1) ? idx : (-1);
}

std::string getFirstEMailPart(std::string eMail)
{
    int idx = getSeparateEMailIdx(eMail);

    return (idx == (-1)) ? "-1" : eMail.substr(0, idx);
}

std::string getLastEMailPart(std::string eMail)
{
    int idx = getSeparateEMailIdx(eMail);

    return ((idx == (-1)) ? "-1" : eMail.substr(idx + 1, eMail.length() - (idx + 1)));
}

bool checkFirstEMailPart(std::string str)
{
    if ((str == "-1") ||
        (str.length() < 1) ||
        (str.length() > 64))
    {
        return false;
    }

    for(int i = 0; i < str.length(); ++i)
    {
        if (!(((str[i] >= '0') && (str[i] <= '9')) ||
              ((str[i] >= 'A') && (str[i] <= 'Z')) ||
              ((str[i] >= 'a') && (str[i] <= 'z')) ||
             ((str[i] <= '\'') && (str[i] >= '#')) ||
              ((str[i] >= '^') && (str[i] <= '`')) ||
              ((str[i] >= '{') && (str[i] <= '~')) ||
               (str[i] == '!') || (str[i] == '?')  ||
               (str[i] == '*') || (str[i] == '+')  ||
               (str[i] == '/') || (str[i] == '=')  || (str[i] == '-') ||
               ((str[i] == '.') && (i > 0) && ((i + 1) < str.length()) &&
                (str[i-1] != str[i]) && (str[i] != str[i+1]))))
            return false;
    }
    return true;
}

bool checkLastEMailPart(std::string str)
{
    if ((str == "-1") ||
        (str.length() < 1) ||
        (str.length() > 63))
    {
        return false;
    }

    for(int i = 0; i < str.length(); ++i)
    {
        if (!(((str[i] >= '0') && (str[i] <= '9')) ||
              ((str[i] >= 'A') && (str[i] <= 'Z')) ||
              ((str[i] >= 'a') && (str[i] <= 'z')) || (str[i] == '-') ||
              ((str[i] == '.') && (i > 0) && ((i + 1) < str.length()) &&
               ((str[i-1] != str[i]) || (str[i] != str[i+1])))))
            return false;
    }
    return true;
}