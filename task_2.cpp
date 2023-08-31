#include <iostream>
using namespace std;

void inputStrToDouble(string &whole, string &fraction)
{
    cout << "Ввести целую и дробную часть числа через пробел: ";
    cin >> whole >> fraction;
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
    inputStrToDouble(whole, fraction);
    parseStrToDouble(whole, fraction, ptrRez);
    cout << "Введенное число типа double: " << rez << endl;
}