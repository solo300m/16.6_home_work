#include <iostream>
using namespace std;
bool allPowerOnF(int &timeHour)
{
    return false;
}
void heatWaterOnF(double &temperatureOut, bool &heatWaterFlag)
{
    if (temperatureOut < 0)
    {
        heatWaterFlag = true;
    }
    else if (temperatureOut > 5 && heatWaterFlag)
    {
        heatWaterFlag = false;
    }
    else if (temperatureOut >= 0 && temperatureOut <= 5 && heatWaterFlag)
    {
        heatWaterFlag = true;
    }
}
void lightOutOnF(bool &move, int &timeHour, bool &lightOutOn)
{
    if (timeHour > 16 || timeHour < 5)
    {
        if (move)
        {
            lightOutOn = true;
        }
        else
        {
            lightOutOn = false;
        }
    }
    else
    {
        lightOutOn = false;
    }
}
void lightInOnF(bool &move, int &timeHour, bool &lightInOn)
{
    if (timeHour > 16 || timeHour < 5)
    {
        if (move)
        {
            lightInOn = true;
        }
        else
        {
            lightInOn = false;
        }
    }
    else
    {
        lightInOn = false;
    }
}
void heatInOnF(double &temperatureIn, bool &heatInOn)
{
    if (temperatureIn < 22)
    {
        heatInOn = true;
    }
    else if (temperatureIn > 25)
    {
        heatInOn = false;
    }
    else if ((temperatureIn >= 22 && temperatureIn <= 25) && heatInOn)
    {
        heatInOn = true;
    }
}
void coolerInOnF(double &temperatureIn, bool &coolerInOn)
{
    if (temperatureIn >= 30)
    {
        coolerInOn = true;
    }
    else if (temperatureIn <= 25)
    {
        coolerInOn = false;
    }
}
void lightRangeF(int &timeHour, bool &lightInOn, int &lightRangeRez)
{
    if ((timeHour >= 16 && timeHour < 17) && lightInOn)
    {
        lightRangeRez = 5000000;
    }
    else if ((timeHour >= 17 && timeHour < 18) && lightInOn)
    {
        lightRangeRez = 4000000;
    }
    else if ((timeHour >= 18 && timeHour < 19) && lightInOn)
    {
        lightRangeRez = 3000000;
    }
    else if ((timeHour >= 19 && timeHour < 20) && lightInOn)
    {
        lightRangeRez = 2800000;
    }
    else if (timeHour >= 20 && lightInOn)
    {
        lightRangeRez = 2700000;
    }
}
void inputData(int &timeHour, double &temperatureOut, double &tempetatureIn, bool &move)
{
    while (true)
    {
        string moveStr = "";
        double tempOut = 0.0;
        double tempIn = 0.0;

        cout << "Текущее время: " << timeHour << ":"
             << "00"
             << " часов" << endl;
        cout << "Введите через пробел значения наружной температуры, температуры в помещении и наличия людей (yes/no)" << endl;
        cin >> tempOut >> tempIn >> moveStr;
        if (tempOut >= -50 && tempOut <= 50)
        {
            temperatureOut = tempOut;
        }
        else
        {
            cout << "Введенная внешнаяя температура не соответствует предельному интервалу -50 +50" << endl;
            cout << "Повторите ввод.";
            continue;
        }
        if (tempIn >= -10 && tempIn <= 40)
        {
            tempetatureIn = tempIn;
        }
        else
        {
            cout << "Введенная внутренняя температура не соответствует предельному интервалу -10 +40" << endl;
            cout << "Повторите ввод.";
            continue;
        }
        string tmp = "";
        for (int i = 0; i < moveStr.length(); i++)
        {
            tmp += tolower(moveStr[i]);
        }
        moveStr = tmp;
        if (moveStr == "yes")
            move = true;
        else if (moveStr == "no")
            move = false;
        else
        {
            cout << "Введенная фраза не совпадает со словом yes или no" << endl;
            cout << "Повторите ввод.";
            continue;
        }
        break;
    }
}

void displyOutSystem(double &ptrTOut, int &ptrTHour, bool &ptrLOutOn)
{
    string powerOn = "Вкл.";
    string powerOff = "Выкл.";
    if (ptrLOutOn)
        cout << "Система внешнего освещения " << powerOn << endl;
    else
        cout << "Система внешнего освещения " << powerOff << endl;
}

void displyInSystem(int &ptrTHour, double &ptrTIn, bool &ptrHWFlag, bool &ptrM, bool &ptrLInOn, bool &ptrHInOn, bool &ptrCInOn, int &ptrLRR)
{
    string powerOn = "Вкл.";
    string powerOff = "Выкл.";
    if (ptrLInOn)
        cout << "Система внутреннего освещения " << powerOn << endl;
    else
        cout << "Система внутреннего освещения " << powerOff << endl;
    if (ptrHWFlag)
        cout << "Система подогрева вода " << powerOn << endl;
    else
        cout << "Система подогрева вода " << powerOff << endl;
    if (ptrHInOn)
        cout << "Система обогрева дома " << powerOn << endl;
    else
        cout << "Система обогрева дома " << powerOff << endl;
    if (ptrCInOn)
        cout << "Система кондиционирования дома " << powerOn << endl;
    else
        cout << "Система кондиционирования дома " << powerOff << endl;
    cout << "Тепловая карта освещения " << ptrLRR / 1000 << "K" << endl;
}

int main()
{
    int timeHour = 0;
    double temperatureOut = 0.0;
    bool heatWaterFlag = false;
    bool move = false;
    bool lightOutOn = false;
    bool lightInOn = false;
    double temperatureIn = 0.0;
    bool heatInOn = false;
    bool collerInOn = false;
    int lightRangeRez = 5000000;

    int &ptrTHour = timeHour;
    double &ptrTOut = temperatureOut;
    bool &ptrHWFlag = heatWaterFlag;
    bool &ptrM = move;
    bool &ptrLOutOn = lightOutOn;
    bool &ptrLInOn = lightInOn;
    double &ptrTIn = temperatureIn;
    bool &ptrHInOn = heatInOn;
    bool &ptrCInOn = collerInOn;
    int &ptrLRR = lightRangeRez;

    while (ptrTHour <= 24)
    {
        inputData(ptrTHour, ptrTOut, ptrTIn, ptrM);
        lightOutOnF(ptrM, ptrTHour, ptrLOutOn);
        lightInOnF(ptrM, ptrTHour, ptrLInOn);
        heatWaterOnF(ptrTOut, ptrHWFlag);
        heatInOnF(ptrTIn, ptrHInOn);
        coolerInOnF(ptrTIn, ptrCInOn);
        lightRangeF(ptrTHour, ptrLInOn, ptrLRR);
        ptrTHour++;
        displyOutSystem(ptrTOut, ptrTHour, ptrLOutOn);
        displyInSystem(ptrTHour, ptrTIn, ptrHWFlag, ptrM, ptrLInOn, ptrHInOn, ptrCInOn, ptrLRR);
    }
}