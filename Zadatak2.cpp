#include <iostream>
#include <cmath>
#include <vector>
#include <exception>



std::vector<int> RastaviNaProsteFaktore(int n)
{
    std::vector<int> v;

    if(n==1) {
        v.push_back(1);
    } else {
        int c=n%2;
        while(c==0) {
            int b=n/2;
            v.push_back(2);
            n=b;
            c=n%2;
        }
        for(int j=3; j<=n; j+=2) {
            int c=n%j;
            while(c==0) {
                int b=n/j;
                v.push_back(j);
                n=b;
                c=n%j;
            }
        }
    }

    return v;

}

std::vector<int> PrebrojiCifre(std::vector <int > &v)
{
    std::vector<bool> ima(v.size(),false);
    std::vector<int> v1;

    for(int i=0; i<v.size(); i++) {
        if(ima.at(i)==true) continue;
        int brojac(1);
        for(int j=i+1; j<v.size(); j++) {
            if(v.at(i)==v.at(j)) {
                ima.at(j)=true;
                brojac++;
            }
        }
        v1.push_back(brojac);
    }

    return v1;
}


std::vector<int> UkloniDuplikate(std::vector<int> &v)
{

    std::vector<int>v1;


    for(int i=0; i<v.size(); i++) {
        bool dodatiUvektor=true;
        for(int j=i+1; j<v.size(); j++) {
            if(v.at(i)==v.at(j)) {
                dodatiUvektor=false;
                break;
            }
        }

        if(dodatiUvektor==true) v1.push_back(v.at(i));
    }

    return v1;
}



void RastavaBroja(int n, int &p, int &q)
{

    if(n<=0 || n-int(n)>0.001) throw std::domain_error("Broj koji se rastavlja mora biti prirodan");

    std::vector <int> v;
    v=RastaviNaProsteFaktore(n);

    std::vector<int> ponavljanja;
    ponavljanja=PrebrojiCifre(v);

    std::vector<int> bezDuplih;
    bezDuplih=UkloniDuplikate(v);

    p=1;
    for(int i=0; i<bezDuplih.size(); i++) {
        for(int j=0; j<ponavljanja.size(); j++) {
            if(i==j && ponavljanja.at(j)%2!=0) {
                p=p*bezDuplih.at(i);
            }
        }
    }

    q=1;
    for(int i=0; i<bezDuplih.size(); i++) {
        for(int j=0; j<ponavljanja.size(); j++) {
            if(i==j) {
                int baza=bezDuplih.at(i);
                int eksponent=ponavljanja.at(j)/2;
                int broj=pow(baza,eksponent);
                q=q*broj;
            }
        }
    }
}

int main ()
{
    try {
        int n(0);
        std::cout << "Unesite prirodan broj"<<std::endl;
        std::cin  >> n;

        int p(1),q(1);

        RastavaBroja(n,p,q);
        std::cout << p << " " << q << std::endl;


    } catch(std::domain_error izuzetak) {
        std::cout << "Izuzetak: Broj koji se rastavlja mora biti prirodan!" ;
    }
    return 0;
}
