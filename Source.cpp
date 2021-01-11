// Lab_09_1.cpp 
// < �������� ������ > 
// ����������� ������ � 9.1 
// ������ 1

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
    cout << "����i�� N: "; cin >> N;

    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);
    LineSearch(p, N);
    PSearch(p, N);


    proc = PSearch(p, N);
    cout << "������� �������i�, � ���� ������i� ��� �i����� �� 4,5:" << endl; cout << proc << "%" << endl;

    return 0;
}

void Create(Student* p, const int N)
{
    int spec1;
    for (int i = 0; i < N; i++)
    {
        cout << "������� � " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << " ��i�����: "; cin >> p[i].prizv;
        cout << " �i� ����������: "; cin >> p[i].rikNar;
        cout << " ����: "; cin >> p[i].kurs;
        cout << " ����i����i���(0 - ���������� �� ������i��, 1 - ������� ��������, 2 - �i���� �� i����������, 3 - I����������, 4 - ���������i �����): ";
        cin >> spec1;
        p[i].spec = (Spec)spec1;
        cout << " ��i��� � �i����: "; cin >> p[i].physics;
        cout << " ��i��� � ����������: "; cin >> p[i].math;

        switch (p[i].spec)
        {
        case ME:
            cout << " ��i��� � I���������� : "; cin >> p[i].ped;
            break;

        case MF:
            cout << " ��i��� � I���������� : "; cin >> p[i].ped;
            break;

        case FI:
            cout << " ��i��� � I���������� : "; cin >> p[i].ped;
            break;

        case KN:
            cout << " ��i��� � I���������� : "; cin >> p[i].ped;
            break;

        case INF:
            cout << " ��i��� � I���������� : "; cin >> p[i].ped;
            break;
        }
        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "==================================================================================="
        << endl;
    cout << "| � | ��i����� | �i� ���������� | ���� | ����i����i��� | �i���� | ���������� | I���������� |"
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
    cout << "��i����� �������i� ��i ������� �� �i��i��� : " << endl;

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
    cout << "��i����� �������i� ��� ������i� ���>=4,5:" << endl;
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