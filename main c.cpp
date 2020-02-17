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
    vector <int> b;
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
            int aa;
            cout <<"Iveskite siuos "<<n<<" pazymius : "<<endl;
            for (int i = 0; i < n; i++)
            {
                cout << i + 1 << " namu darbo rezultatas:" << endl;
                cin >> aa;
                b.push_back(aa);
                string textnd = "Klaida: rezultatas turi buti nurodytas skaiciumi nuo 1 iki 10\n";
                Validation(b.at(i), textnd, 1, 10);
                sum+=b.at(i);
            }
        }
        if (isNd == 'r')
        {
            srand(time(NULL));
            cout <<"Studento pazymiai sugeneruoti. Pazymiai : ";
            for (int i = 0; i < n; i++)
            {
                b.push_back(rand() % 10 + 1);
                cout <<b.at(i)<<" ";
                sum+=b.at(i);
            }
            cout <<endl;
        }
        if (isNd=='n')
        {
            b = read_numbers_till();
        }
    }
    std::vector<int> read_numbers_till( char end_with = 's' )
    {
        std::vector<int> result ;
        std::cout << "Iveskite pazymi ( rasykite 's' norint sustabdyti, neigiami skaiciai i suma neskaiciuojami): \n" ;
        int a;
        while( std::cout << "Pazymys? " )
        {
            if( std::cin >> a )
            {
                result.push_back(a) ;
                string textnda = "Klaida: rezultatas turi buti nurodytas skaiciumi nuo 1 iki 10\n";
                Validation(result.at(n), textnda, 1, 10);
                n++;
                sum+=a;
            }
            else
            {
                std::cin.clear() ;
                if( std::cin.get() == end_with )
                    break ;
                std::cout << "Klaida. Veskite skaiciaus formatu pazymi. \n" ;
                std::cin.ignore( 1000, '\n' ) ;
            }
        }
        return result ;
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
        sort(b.begin(), b.end());
        if (n % 2 == 0)
            return (double)(b.at(n / 2 - 1) + b.at(n / 2)) / 2;
        else
            return (double)b.at(n / 2);
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
