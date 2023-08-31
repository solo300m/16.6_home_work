#include <iostream>
#include <stdio.h>
using namespace std;
void inputDelta(double &ptr_spd)
{
    cout << "Ввести знечение скорости: ";
    cin >> ptr_spd;
}
void calcSpeed(double &ptr_spd, double &ptr_spv)
{
    ptr_spv = (ptr_spv + ptr_spd) > 0.001 ? ptr_spv + ptr_spd : 0.0;
}
void displySpeed(double &ptr_spv, string &ptr_sstr)
{
    char buffer[10];
    double tmp = ptr_spv;
    sprintf(buffer, "%.1f", tmp);
    ptr_sstr = buffer;
    cout << "Скорость " << ptr_sstr << endl;
}

int main()
{
    double speed_delta = 0.0;
    double &ptr_spd = speed_delta;
    double speed_value = 0.0;
    double &ptr_spv = speed_value;
    string speed_str;
    string &ptr_sstr = speed_str;
    while (true)
    {
        inputDelta(ptr_spd);
        calcSpeed(ptr_spd, ptr_spv);
        displySpeed(ptr_spv, ptr_sstr);
        if (ptr_spv == 0.0)
            break;
    }
    cout << "Автомобиль остановился. Скорость равна " << ptr_spv << endl;
    cout << "Программа завершена!" << endl;
}