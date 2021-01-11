// Lab_09_1.cpp 
// < Базарник Максим > 
// Лабораторна робота № 9.1 
// Варіант 1

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum Spec { ME, MF, FI, INF, KN };

struct Student
{
    string prizv;
    unsigned rikNar;
    int kurs;
    Spec spec;
    int physics;
    int math;

    union
    {
        int prog;
        int cMethod;
        int ped;
    };
};

void Print(Student* p, const int N);
void Create(Student* p, const int N);
void LineSearch(Student* p, const int N);
double PSearch(Student* p, const int N);

int main()
{
    setlocale(LC_ALL, "Russian");
 

    double proc;
    int N;
    cout << "Введiть N: "; cin >> N;

    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);
    LineSearch(p, N);
    PSearch(p, N);


    proc = PSearch(p, N);
    cout << "Процент студентiв, у яких середнiй бал бiльший за 4,5:" << endl; cout << proc << "%" << endl;

    return 0;
}

void Create(Student* p, const int N)
{
    int spec1;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << " прiзвище: "; cin >> p[i].prizv;
        cout << " рiк народження: "; cin >> p[i].rikNar;
        cout << " курс: "; cin >> p[i].kurs;
        cout << " спецiальнiсть(0 - Математика та економiка, 1 - Трудове навчання, 2 - Фiзика та iнформатика, 3 - Iнформатика, 4 - Комп’ютернi науки): ";
        cin >> spec1;
        p[i].spec = (Spec)spec1;
        cout << " оцiнка з фiзики: "; cin >> p[i].physics;
        cout << " оцiнка з математики: "; cin >> p[i].math;

        switch (p[i].spec)
        {
        case ME:
            cout << " оцiнка з Iнформатики : "; cin >> p[i].ped;
            break;

        case MF:
            cout << " оцiнка з Iнформатики : "; cin >> p[i].ped;
            break;

        case FI:
            cout << " оцiнка з Iнформатики : "; cin >> p[i].ped;
            break;

        case KN:
            cout << " оцiнка з Iнформатики : "; cin >> p[i].ped;
            break;

        case INF:
            cout << " оцiнка з Iнформатики : "; cin >> p[i].ped;
            break;
        }
        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "==================================================================================="
        << endl;
    cout << "| № | Прiзвище | Рiк народження | Курс | Спецiальнiсть | Фiзика | Математика | Iнформатика |"
        << endl;
    cout << "-----------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(13) << left << p[i].prizv
            << "| " << setw(4) << right << p[i].rikNar << " "
            << "| " << setw(11) << left << p[i].kurs
            << "| " << setw(11) << left << p[i].spec
            << "| " << setw(11) << left << p[i].physics
            << "| " << setw(11) << left << p[i].math;
        switch (p[i].spec)
        {
        case ME:
            cout << "| " << setw(9) << setprecision(2) << fixed << left
                << p[i].ped << " |" << endl;
            break;
        case MF:
            cout << "| " << setw(9) << setprecision(2) << fixed << left
                << p[i].ped << " |" << endl;
            break;
        case FI:
            cout << "| " << setw(9) << setprecision(2) << fixed << left
                << p[i].ped << " |" << endl;
            break;
        case INF:
            cout << "| " << setw(9) << setprecision(2) << fixed << left
                << p[i].ped << " |" << endl;
            break;
        case KN:
            cout << "| " << setw(9) << setprecision(2) << fixed << left
                << p[i].ped << " |" << endl;
            break;
        }
    }
    cout << "==================================================================================="
        << endl;
    cout << endl;
}


void LineSearch(Student* p, const int N)
{
    cout << "Прiзвища студентiв якi вчаться на вiдмiнно : " << endl;

    for (int i = 0; i < N; i++)
    {
        if (p[i].physics == 5)
        {
            if (p[i].math == 5)
            {
                if (p[i].ped == 5)
                {
                    cout << setw(3) << right
                        << p[i].prizv << endl;
                }
            }
        }
    }
}


double PSearch(Student* p, const int N)
{
    cout << "Прiзвища студентiв чий середнiй бал>=4,5:" << endl;
    int k = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i].spec == ME || p[i].spec == MF || p[i].spec == FI || p[i].spec == INF && p[i].spec == KN)
        {
            n++;
            if ((p[i].math + p[i].physics + p[i].ped) / 3 >= 4.5)
            {
                k++;
                cout << setw(3) << right << k
                    << " " << p[i].prizv << endl;
            }
        }
    }
    return 100.0 * k / n;
}