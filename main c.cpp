#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <math.h>
#include <ctime>
#include <ctype.h>
#include <windows.h>
#include <limits>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;
struct Studentas
{
    int studK;
    string vardas;
    string pavarde;
    int n=0;
    int* nd;
    int egz;
    int sum=0;
    double vid;
    double finalGr;
    char isNd;

    void Validation (int &input, string text, int from, int to)
    {
        while (cin.fail() || (input < from || input > to))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout <<text;
            cin >>input;
        }
    }
    void StudentoInfo ()
    {
        cout <<"Iveskite studento varda : ";
        cin >>vardas;
        cout <<"Iveskite studento pavarde : ";
        cin >>pavarde;
    }
    void isPazymiuKiekis()
    {
        cout <<"Ar norite ivesti pazymius? (t - taip, n - ne, r - random) : ";
        cin >>isNd;
        while (isNd != 't' && isNd != 'n' && isNd!= 'r')
        {
            cin.clear();
            cin.ignore();
            cout <<"Klaida. Iveskite t, n arba raide!\n";
            cin >>isNd;
        }
    }
    void inPazymiuKiekis ()
    {
        if (isNd == 't')
        {
            cout <<"Iveskite pazymiu kieki : ";
            cin >>n;
            string text1 = "Klaida. Veskite pazymiu kieki nenaudodami raidziu arba neigiamu skaiciu.\nIveskite studento pazymiu kieki : \n";
            Validation(n, text1, 1, INT_MAX);
        }
        else if (isNd == 'n')
        {
            cout <<"Pazymiai bus ivedami tol, kol vartotojas lieps sustoti.\n"<<endl;
        }
        if (isNd == 'r')
        {
            cout <<"Pazymiai bus generuojami atsitiktinai."<<endl;
            cout <<"Kiek pazymiu sugeneruoti? : ";
            cin >>n;
        }
    }

    void PazymiuIvedimas()
    {
        nd = new int[n];
        if (isNd == 't')
        {
            cout <<"Iveskite siuos "<<n<<" pazymius : "<<endl;
            for (int i = 0; i < n; i++)
            {
                cout << i + 1 << " namu darbo rezultatas:" << endl;
                cin >> nd[i];
                string textnd = "Klaida: rezultatas turi buti nurodytas skaiciumi nuo 1 iki 10\n";
                Validation(nd[i], textnd, 1, 10);
                sum+=nd[i];
            }
        }
        if (isNd == 'r')
        {
            srand(time(NULL));
            cout <<"Studento pazymiai sugeneruoti. Pazymiai : ";
            for (int i = 0; i < n; i++)
            {
                nd[i] = rand() % 10 + 1;
                cout <<nd[i]<<" ";
                sum+=nd[i];
            }
            cout <<endl;
        }
        if (isNd=='n')
        {
            while (true)
            {
                char inputBuffer[20];
                cout << "Iveskite pazymi ( rasykite stop norint sustabdyti, neigiami skaiciai i suma neskaiciuojami): ";
                cin >> inputBuffer;

                if (isint(inputBuffer))
                {
                    nd[n] = atoi(inputBuffer);
                    string textndn = "Klaida: rezultatas turi buti nurodytas skaiciumi nuo 1 iki 10\n";
                    Validation(nd[n], textndn, 1, 10);
                    sum+=nd[n];
                    n++;
                }
                else if (hasStopChar(inputBuffer, 'stop'))
                {
                    break;
                }
            }
        }
    }
    void EgzaminoIvedimas()
    {
        if (isNd == 't' || isNd== 'n')
        {
            cout <<"Iveskite egzamino pazymi : "<<endl;
                cin >> egz;
                string textnde = "Klaida: rezultatas turi buti nurodytas skaiciumi nuo 1 iki 10\n";
                Validation(egz, textnde, 1, 10);
        }
        if (isNd == 'r')
        {
            srand(time(NULL));
            cout <<"Studento egzamino ivertis sugeneruotas. Pazymys : ";
                egz = rand() % 10 + 1;
                cout <<egz<<" ";
            cout <<endl;
        }
    }
    bool isint(const char* str)
    {
        for (const char* ptr = str; *ptr; ++ptr)
        {
            if (!isdigit(*ptr))
                return false;
        }
        return true;
    }
    bool hasStopChar(const char* str, char stopChr)
    {
        for (const char* ptr = str; *ptr; ++ptr)
        {
            if (*ptr == stopChr)
                return true;
        }
        return false;
    }
    double finalGrade ()
    {
        vid=sum/(double)n;
        return (0.4*vid)+(0.6*egz);
    }

    double finalMedian()
    {
        sort(nd, nd + n);
        if (n % 2 == 0)
            return (double)(nd[n / 2 - 1] + nd[n / 2]) / 2;
        else
            return (double)nd[n / 2];
    }
};
void Validation (int &input, string text, int from, int to)
    {
        while (cin.fail() || (input < from || input > to))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout <<text;
            cin >>input;
        }
    }
int main ()
{
    int studK;
    cout << "Iveskite studentu kieki : " ;
        cin >> studK;
        string text = "Klaida. Veskite studentu kieki didesni nei 0. Nenaudokite raidziu.\nIveskite studentu kieki : ";
        Validation(studK, text, 0, INT_MAX);
    Studentas V1[studK];
    for (int i = 0; i < studK; i++)
    {
    V1[i].StudentoInfo();
    V1[i].isPazymiuKiekis();
    V1[i].inPazymiuKiekis();
    V1[i].PazymiuIvedimas();
    V1[i].EgzaminoIvedimas();
    }
    cout << left << setw(25) << "Pavarde"<< setw(25) << "Vardas" <<setw(25)<< "Galutinis (Vid.)"<<setw(25)<<"Galutinis (Med.)"<< endl;
    cout << "--------------------------------------------------------------------------------------------"<<endl;
    for (int i = 0; i < studK; i++)
    {
        cout << left << setw(25) << V1[i].pavarde<< setw(25) << V1[i].vardas << fixed<< setprecision(1) << V1[i].finalGrade() <<fixed<<setprecision(1)<<right<<setw(25)<<V1[i].finalMedian()<<endl;
    }
    cout << "--------------------------------------------------------------------------------------------"<<endl;
}
