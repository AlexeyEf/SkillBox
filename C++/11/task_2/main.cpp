#include <iostream>

//общие вопросы
// Насколько правильно и грамотно я разбил функциональность программы на функции?
bool checkEMail(std::string eMail);
int separateEMailString(std::string eMail);
bool checkFirstEMailPart(std::string str);
bool checkLastEMailPart(std::string str);
bool checkCharacter(char c, char part); //насколько правильно и грамотно что использовал столько аргументов

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
    int idx = separateEMailString(eMail);

    if(idx == (-1))
    {
        return false;
    }

    return (checkFirstEMailPart(eMail.substr(0, idx)) &&
            checkLastEMailPart(eMail.substr(idx + 1, eMail.length() - (idx + 1))));
}

int separateEMailString(std::string eMail)
{
    int idx = 0; // index of @ in the address string
    for(int i = 0, count = 0; i < eMail.length(); ++i)
    {
        if(eMail[i] == '@')
        {
            if (count > 0)
            {
                return (-1);
            }
            count++;
            idx = i;
        }
    }
    return idx;
}

bool checkFirstEMailPart(std::string str)
{
    if ((str.length() < 1) ||
        (str.length() > 64))
    {
        return false;
    }

    for(int i = 0; i < str.length(); ++i)
    {
        if(!checkCharacter(str[i], 1))
        {
            return false;
        }
    }
    return true;
}

bool checkLastEMailPart(std::string str)
{
    if ((str.length() < 1) ||
        (str.length() > 63))
    {
        return false;
    }

    for(int i = 0; i < str.length(); ++i)
    {
        if( !checkCharacter(str[i], 2) )
        {
            return false;
        }
    }
}

bool checkCharacter(char ch, /*int idx, bool lastIndex,*/ char firstPart)
{
    std::cout << ch << " ";
    //проверка точки
    if(((ch >= '0') && (ch <= '9')) ||
       ((ch >= 'A') && (ch <= 'Z')) ||
       ((ch >= 'a') && (ch <= 'z')) ||
        (ch == '-') || (ch == '.'))
        return true;

    if(firstPart == 1)
    {
        if((ch == '!' ) || (ch == '?' ) ||
           (ch <= '\'') && (ch >= '#' ) ||
           (ch == '*' ) || (ch == '+' ) ||
           (ch == '/')  || (ch == '=' ) ||
           ((ch >= '^') && (ch <= '`')) ||
           ((ch >= '{') && (ch <= '~')))
             return true;
    }
    return false;
}