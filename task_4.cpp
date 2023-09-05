#include <iostream>
#include <vector>
using namespace std;
enum Notes
{
    DO = 1,
    RE = 2,
    MI = 3,
    FA = 4,
    SOL = 5,
    LA = 6,
    SI = 7
};
void inputMusic(vector<int> &ptr)
{
    int count = 0;
    cout << "Введите массив звуков используя целые значения с 1 по 7" << endl;
    while (true)
    {
        count++;
        int tmp = 0;
        cout << "элемент " << count << " -> ";
        cin >> tmp;
        if (tmp < 1 || tmp > 7)
        {
            break;
        }
        else
        {
            ptr.push_back(tmp);
        }
    }
}

void displyMusic(vector<vector<int>> &ptr)
{
    for (int i = 0; i < ptr.size(); i++)
    {
        for (int j = 0; j < ptr[i].size(); j++)
        {
            if (ptr[i][j] == Notes::DO)
            {
                // cout << (ptr[i][j] & Notes::DO) << "\t";
                cout << "DO"
                     << "\t";
            }
            if (ptr[i][j] == Notes::RE)
            {
                cout << "RE"
                     << "\t";
            }
            if (ptr[i][j] == Notes::MI)
            {
                // cout << (ptr[i][j] & Notes::MI) << "\t";
                cout << "MI"
                     << "\t";
            }
            if (ptr[i][j] == Notes::FA)
            {
                cout << "FA"
                     << "\t";
            }
            if (ptr[i][j] == Notes::SOL)
            {
                cout << "SOL"
                     << "\t";
            }
            if (ptr[i][j] == Notes::LA)
            {
                cout << "LA"
                     << "\t";
            }
            if (ptr[i][j] == Notes::SI)
            {
                cout << "SI"
                     << "\t";
            }
        }
        cout << endl;
    }
}

int main()
{
    cout << "Введите последовательно 12 комбинаций нот с помощью целых чисел от 1 до 7" << endl;
    vector<vector<int>> musicArr;
    vector<vector<int>> &ptrMArr = musicArr;
    for (int i = 0; i < 12; i++)
    {
        vector<int> music;
        vector<int> &ptrM = music;
        inputMusic(ptrM);
        musicArr.push_back(music);
    }
    displyMusic(ptrMArr);
}