#include <iostream>
#include <sstream>
using namespace std;

bool verifyDouble(string str)
{
    int countPoint = 0;
    if (str[0] == '-')
    {
        for (int i = 1; i < str.length(); i++)
        {
            if (!isdigit(str[i]) && str[i] != '.')
            {
                return false;
            }
            else if (!isdigit(str[i]) && str[i] == '.')
            {
                if (countPoint > 1)
                {
                    return false;
                }
                else
                {
                    countPoint++;
                }
            }
        }
        return true;
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (!isdigit(str[i]) && str[i] != '.')
            {
                return false;
            }
            else if (!isdigit(str[i]) && str[i] == '.')
            {
                if (countPoint > 1)
                {
                    return false;
                }
                else
                {
                    countPoint++;
                }
            }
        }
        return true;
    }
    return false;
}
bool verifyAction(char action)
{
    switch (action)
    {
    case '+':
        return true;
    case '-':
        return true;
    case '/':
        return true;
    case '*':
        return true;
    default:
        return false;
    }
}
bool inputCalcAction(double &ptrA, double &ptrB, char &ptrAct)
{
    string first = "";
    string second = "";
    string tmp = "";
    char operand = ' ';
    cout << "Введите строку в формате число действие число через пробел:" << endl;
    string buffer = "";
    getline(cin, buffer);
    stringstream strIo;
    strIo << buffer;
    strIo >> first >> tmp >> second;
    operand = tmp[0];
    if (!verifyDouble(first) || (!verifyDouble(second) || !verifyAction(operand)))
    {
        return false;
    }
    else
    {
        ptrA = stof(first);
        ptrB = stof(second);
        ptrAct = operand;
    }
    return true;
}
void add(double &ptrA, double &ptrB, double &ptrRez)
{
    ptrRez = ptrA + ptrB;
}
void subtraction(double &ptrA, double &ptrB, double &ptrRez)
{
    ptrRez = ptrA - ptrB;
}
void multiplication(double &ptrA, double &ptrB, double &ptrRez)
{
    ptrRez = ptrA * ptrB;
}
bool division(double &ptrA, double &ptrB, double &ptrRez)
{
    if (ptrB != 0.0)
    {
        ptrRez = ptrA / ptrB;
        return true;
    }
    else
    {
        ptrRez = 0.0;
        return false;
    }
}

void calc(double &ptrA, double &ptrB, char &ptrAct, double &ptrRez)
{
    switch (ptrAct)
    {
    case '+':
        add(ptrA, ptrB, ptrRez);
        cout << ptrA << " " << ptrAct << " " << ptrB << " = " << ptrRez << endl;
        break;
    case '-':
        subtraction(ptrA, ptrB, ptrRez);
        cout << ptrA << " " << ptrAct << " " << ptrB << " = " << ptrRez << endl;
        break;
    case '*':
        multiplication(ptrA, ptrB, ptrRez);
        cout << ptrA << " " << ptrAct << " " << ptrB << " = " << ptrRez << endl;
        break;
    case '/':

        if (division(ptrA, ptrB, ptrRez))
        {
            cout << ptrA << " " << ptrAct << " " << ptrB << " = " << ptrRez << endl;
        }
        else
        {
            cout << "Результат деления на ноль на множестве действительных чисел не определен!";
        }
        break;

    default:
        cout << "Данное действие не определено!";
        break;
    }
}

int main()
{
    double a = 0.0;
    double b = 0.0;
    double rez = 0.0;
    double &ptrRez = rez;
    double &ptrA = a;
    double &ptrB = b;
    char action = ' ';
    char &ptrAct = action;
    if (inputCalcAction(ptrA, ptrB, ptrAct))
    {
        // cout << ptrA << ptrAct << ptrB << endl;
        calc(ptrA, ptrB, ptrAct, ptrRez);
    }
    else
    {
        cout << "Ошибка ввода!";
    }
}