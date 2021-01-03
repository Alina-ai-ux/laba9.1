#include <iostream>
#include <string>
#include <iomanip>
//#include<Windows.h>
using namespace std;
enum Fax { Kov_nayk, Informatuka, Mat_Ek, Fiz_Inf, Tr_nav };
string fax_str[] = { "Kov_nayk", "Informatuka","Mat_Ek", "Fiz_Inf","Tr_nav" };
struct Student {
    string prizv;
    int kurs;
    Fax fax;
    int f;
    int m;
    union
    {
        int prog;
        int ch_m;
        int ped;
    };
};
void Create(Student* S, const int N);
void Print(Student* S, const int N);
int K_5(Student* S, const int N);
double  F_5(Student* S, const int N);
// --------------------------------------------  
// Функція для вводу даних
void Create(Student* S, const int N)
{
    int fax;
    for (int i = 0; i < N; i++)
    {
        cout << "Student N" << i + 1 << ":" << endl;
        cin.sync();//
        cout << "          prizv:";
        // getline(cin,S[i].prizv); 
        cin >> S[i].prizv;
        cout << "          kurs: "; cin >> S[i].kurs;
        cout << "          fax (0-KN, 1- INFOR, 2-M_E, 3-F_I, 4-T_N: ";
        cin >> fax;  S[i].fax = (Fax)fax;
        cout << "          f: "; cin >> S[i].f;
        cout << "          m: "; cin >> S[i].m;

        switch (S[i].fax)
        {
        case Kov_nayk:cout << "          prog: "; cin >> S[i].prog;  break;
        case Informatuka:cout << "          ch_m: "; cin >> S[i].ch_m;  break;
        case Mat_Ek:
        case Fiz_Inf:
        case Tr_nav:  cout << "         ped: "; cin >> S[i].ped;    break;
        }
        cout << endl;
    }

}
// --------------------------------------------  
// Вивід на екран
void Print(Student* S, const int N)
{
    cout << "===================================================================================="
        << endl;
    cout << "|  N  |    prizv     |   kurs  |     fax     |  f  |  m  |  prog  |  ch_m  |  ped  |"
        << endl;
    cout << "____________________________________________________________________________________"
        << endl;
    for (int i = 0; i < N; i++)
    {

        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(13) << left << S[i].prizv
            << "|" << setw(1) << right << S[i].kurs << "        "
            << "| " << setw(12) << left << fax_str[S[i].fax]
            << "| " << setw(4) << right << S[i].f << ""
            << "| " << setw(4) << right << S[i].m << "";
        switch (S[i].fax)
        {
        case Kov_nayk:
            cout << "| " << setw(6) << setprecision(2) << fixed << right
                << S[i].prog << " |"
                << setw(10) << right << "| "
                << setw(7) << "|"
                << endl;
            break;
        case Informatuka:
            cout << "| " << setw(9) << setprecision(2) << fixed << right
                << " | " << setw(7) << right
                << S[i].ch_m << "| " << setw(7) << "|"
                //   setw(1) << right << "| "  
                << endl;
            break;
        case Mat_Ek:
        case Fiz_Inf:
        case Tr_nav:
            cout << "| " << setw(8) << setprecision(2) << fixed << right
                << "|" << setw(8) << right
                << setw(9) << right << "|" << setw(7) << right
                << S[i].ped << "| "
                //   <<   setw(8) << right  
                << endl;
            break;
        }
    }
    cout << "===================================================================================="
        << endl;
    cout << endl;
}
// --------------------------------------------  
// Пошук відмінників, кількість студентів, що вчаться на відмінно
int  K_5(Student* S, const int N)
{
    int k5 = 0;
    for (int i = 0; i < N; i++)
    {
        switch (S[i].fax)
        {
        case Kov_nayk: if (S[i].f == 5 && S[i].m == 5 && S[i].prog == 5) k5++; break;
        case Informatuka:if (S[i].f == 5 && S[i].m == 5 && S[i].ch_m == 5) k5++;  break;
        case Mat_Ek:
        case Fiz_Inf:
        case Tr_nav:  if (S[i].f == 5 && S[i].m == 5 && S[i].ped == 5) k5++;   break;
        }
    }

    return k5;
}
// --------------------------------------------  
// Відсоток студентів, що мають з фізики відмінно
double F_5(Student* S, const int N)
{
    double procent;
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i].f == 5) k++;
    }
    procent = k * 100.0 / N;

    return procent;
}
// Основна функція
int main()
{
    int N;
    int k5;
    double proc;
    cout << "Enter N:     "; cin >> N;  cout << N << "\n";
    Student* S = new  Student[N];
    Create(S, N);
    Print(S, N);
    k5 = K_5(S, N);
    cout << "k5=" << k5 << endl;
    proc = F_5(S, N);
    cout << "proc=" << proc << endl;
    return 0;
}
// --------------------------------------------
