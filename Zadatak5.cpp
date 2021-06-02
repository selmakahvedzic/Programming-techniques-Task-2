#include <iostream>
#include <string>
#include <algorithm>

bool PretraziBinarno(std::string *s, int duzina, char *rijec) {
    
    return binary_search(s,s+duzina, rijec);
    
}

void KriterijSortiranja(std::string *s, int duzina) {
    for(int i=1; i<duzina; i++) {
        std::string pomocna=*(s+i);
        
        int j=i-1;
        while(j>=0 && pomocna.length())  {//< *(s+j+duzina)) {
            *(s+j+1)=*(s+j);
            j--;
        }
        
        *(s+j+1)=pomocna;
    }
}

template <typename TipElemenata>
TipElemenata *SortirajPoDuzini(std::string *s, int duzina) {
    //dinamicka alokacija stringa
    
    TipElemenata *p=nullptr;
    try {
        p=new TipElemenata[duzina];
    } catch(std::bad_alloc izuzetak) {
        delete[] p;
        throw std::runtime_error("Alokacija nije uspjela");
    }
    
   p=KriterijSortiranja(s,duzina);
   
   return p;
}

int main ()
{
    
    try {
    
    int n(0);
    std::cout << "Unesite broj rijeci: ";
    std::cin >> n;
    
    /*try {
        p=SortirajPoDuzini<int>(n);
        for(int i=0; i<n; i++) {
            std::cout << p.at(i) << " ";
        }
    }*/
   /* try {
    int n(0);
    std::cout << "Unesite n: ";
    std::cin >> n;
    
    std::vector<std::string> v(n);
    std::cout << "Unesite elemente: ";
    
    for(int i=0; i<n; i++) {
        std::getline(std::cin, v.at(i));
    }
    
    auto Novi(SortirajPoDuzini(std::begin(v),std::end(v)));
    std::cout << "Kreirani niz:";
    auto pomocna(Novi);
    
    while(pomocna!=Novi+n) {
        std::cout << *pomocna << " ";
        pomocna++;
    }
    
    delete[] Novi;*/
  
    std::string *niz(new std::string[n]);
    std::cout << "Unesite rijeci: ";
    
    for(int i=0; i<n; i++) {
        std::getline(std::cin, niz[i]);
        
    }
    
  // std::string *novi=KriterijSortiranja(niz,niz+n);
    
    std::cout << "Sortirane rijeci: " ;
    for(int i=0; i<n; i++) {
        std::cout << niz[i]<<" ";
    }
    
    delete[] niz;
    
    std::string rijec;
    std::cout << "\nUnesite rijec za pretragu: ";
    std::getline(std::cin, rijec);
    
    if(rijec.length()==0) std::cout << "Rijec '"<< rijec << "' se ne nalazi u nizu.";
    else {
        std::cout << "Rijec '" << rijec << "' se nalazi u nizu.";
    }
    
   // std::cout << PretraziBinarno(novi,novi+n,rijec);
    
} catch(std::bad_alloc) {
    std::cout << "Nedovoljno memorije!\n" ;
}


	return 0;
}
