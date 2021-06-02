#include <iostream>
#include <deque>
#include <vector>


template <typename NekiTip1, typename NekiTip2, typename NekiTip3>
NekiTip3 SimetricnaRazlikaBlokova(NekiTip1 p1, NekiTip1 p2, NekiTip2 p3, NekiTip2 p4, NekiTip3 p5)
{

    NekiTip1 p1_pom=p1;
    NekiTip2 p3_pom=p3;
    NekiTip3 p5_poc=p5;

    //Doodaje one elemente iz prvog bloka
    while(p1_pom!=p2) {

        bool ima=false;
        NekiTip2 p3_pom=p3;

        while(p3_pom!=p4) {
            if(*p1_pom==*p3_pom) {
                ima=true;
            }

            p3_pom++;
        }

        if(ima==false) {
            bool ima_u_novom=false;
            NekiTip3 p5_pom=p5_poc;

            while(p5_pom!=p5) {
                if(*p5_pom==*p1_pom) {
                    ima_u_novom=true;
                    break;
                }

                p5_pom++;
            }

            if(ima_u_novom==false) {
                *p5=*p1_pom;
                p5++;
            }
        }

        p1_pom++;
    }

    //Dodajemo sad drugi blok
    while(p3_pom!=p4) {
        bool ima=false;
        NekiTip1 p1_pom=p1;

        while(p1_pom!=p2) {
            if(*p3_pom==*p1_pom) {
                ima=true;
            }

            p1_pom++;
        }

        if(ima==false) {
            bool ima_u_novom=false;
            NekiTip3 p5_pom=p5_poc;
            while(p5_pom!=p5) {
                if(*p5_pom==*p3_pom) {
                    ima_u_novom=true;
                    break;

                }

                p5_pom++;
            }

            if(ima_u_novom==false) {
                *p5=*p3_pom;
                p5++;
            }
        }

        p3_pom++;
    }

    return p5;
}


int main ()
{


    int n(0);
    std::cout << "Unesite broj elemenata niza";
    std::cin >> n;

    int niz[1000];
    std::cout << "\nUnesite elemente niza";
    for(int i=0; i<n; i++) {
        std::cin >> niz[i];
    }

    int m(0);
    std::cout << "\nUnesite broj elemenata deka";
    std::cin >> m;



    std::deque<int>dek;
    std::cout << "\nUnesite elemente deka";
    for(int i=0; i<m; i++) {
        int el;
        std::cin >> el;
        dek.push_back(el);
    }

  

    int novi[1000];
    auto p5=SimetricnaRazlikaBlokova(niz, niz+n, std::begin(dek), std::end(dek), std::begin(novi));
    auto *pocetakNovog=novi;
    
    if(pocetakNovog==p5) {
        std::cout << "\nBlokovi nemaju simetricnu razliku";
        return 0;
    }

    std::cout << "\nSimetricna razlika blokova je: ";
    while(pocetakNovog!=p5) {
        std::cout << *pocetakNovog++ << " ";
    }


    return 0;
}
