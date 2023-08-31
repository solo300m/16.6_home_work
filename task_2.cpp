#include <iostream>
using namespace std;

bool inputStrToDouble(string &whole, string &fraction)
{
    cout << "Ввести целую и дробную часть числа через пробел: ";
    cin >> whole >> fraction;
    for (int i = 0; i < whole.length(); i++)
    {
        if (!isdigit(whole[i]))
            return false;
    }
    for (int i = 0; i < fraction.length(); i++)
    {
        if (!isdigit(fraction[i]))
            return false;
    }
    return true;
}
void parseStrToDouble(string &whole, string &fraction, double &rez)
{
    string tmp = whole + "." + fraction;
    rez = stod(tmp);
}

int main()
{
    string strWhole = "";
    string strFraction = "";
    string &whole = strWhole;
    string &fraction = strFraction;
    double rez = 0.0;
    double &ptrRez = rez;
    if (inputStrToDouble(whole, fraction))
    {
        parseStrToDouble(whole, fraction, ptrRez);
        cout << "Введенное число типа double: " << rez << endl;
    }
    else
    {
        cout << "Введенные данные не являются числами!";
    }
}