#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

template<typename T> std::string to_string(T x) {
    std::ostringstream s;
    s<<x;
    return s.str();
}

enum class Smjer {Nalijevo, Nadesno};

enum class Pravci {Sjever, Istok, Jug, Zapad};

enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};

enum class Komande {Aktiviraj, Deaktiviraj, Nalijevo, Nadesno, Idi, Kraj};

void AktivirajRobota(){
}

void DeaktivirajRobota(){
    
}

void Rotiraj(Pravci &orijentacija, Smjer na_koju_stranu) {
    
}

void Idi(int &x, int &y, Pravci orijentacija, int korak) {
    
}

void IspisiPoziciju(int x, int y, Pravci orijentacija) {
    
}

void PrijaviGresku(KodoviGresaka kod_greske) {
    const char *tekstovi[] ={"Nerazumljiva komanda!","Komanda trazi parametar koji nije naveden!","Zadan je suvisan parametar nakon komande!",
    "Parametar komande nije ispravan!"};
    std::cout << tekstovi[int(kod_greske)] << std::endl;
}

int PreskociRazmake() {
    while(std::cin.peek()==' ') std::cin.get();
    return std::cin.peek();
}

bool ProcesirajGresku(KodoviGresaka &gdje, KodoviGresaka kod_greske) {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    gdje=kod_greske;
    return false;
}

bool UnosKomande(Komande &komanda, int &parametar, KodoviGresaka &kod_greske) { //Parametar je broj koraka koji ce robot napraviti
    bool ima_greska(false);
    char znak;
    std::cin >> znak;
    
    if(znak=='A') {
        char znak2(std::cin.get());
        if(znak2=='+') komanda=Komande::Aktiviraj;
        else if(znak2=='-') komanda=Komande::Deaktiviraj;
        else ima_greska=true;
    } else if(znak=='L') komanda=Komande::Nalijevo;
      else if(znak=='D') komanda=Komande::Nadesno;
      else if(znak=='I') komanda=Komande::Idi;
      else if(znak=='K') komanda=Komande::Kraj;
      else ima_greska=true;
      
      
      if(ima_greska) return ProcesirajGresku(kod_greske, KodoviGresaka::PogresnaKomanda);
      if(komanda==Komande::Idi) {
          if(PreskociRazmake()=='\n') return ProcesirajGresku(kod_greske, KodoviGresaka::NedostajeParametar);
          
          std::string par, legalne[]{"NL","ND"};
          std::cin>>par;
          int gdje_je(-1);
          
          for(int i=0; i<8; i++) 
          if(legalne[i]==par) gdje_je=i;
          if(gdje_je=-1)
          return ProcesirajGresku(kod_greske,KodoviGresaka::NeispravanParametar);
          //smjer=Smjer(gdje_je);
      }
      
      if(komanda==Komande::Idi || komanda == Komande::Aktiviraj || komanda==Komande::Deaktiviraj) {
          if(PreskociRazmake()=='\n')
          return ProcesirajGresku(kod_greske, KodoviGresaka::NedostajeParametar);
          int x;
          std::cin >> x;
          if(!std::cin || x<0)
          return ProcesirajGresku(kod_greske, KodoviGresaka::NeispravanParametar);
          if(PreskociRazmake()=='\n')
          return ProcesirajGresku(kod_greske,KodoviGresaka::NedostajeParametar);
          int y;
          std::cin >> y;
          if(!std::cin || (std::cin.peek()!=' ' && std::cin.peek()!='\n'))
          return ProcesirajGresku(kod_greske, KodoviGresaka::NeispravanParametar);
      }
      
      if(PreskociRazmake()!='\n')
      return ProcesirajGresku(kod_greske, KodoviGresaka::SuvisanParametar);
      return true;
}
void IzvrsiKomandu(Komande komanda, int parametar, int &x, int &y, Pravci &orijentacija) {
   /* Status rezultat(Status::NijeKraj);
    try {
        if(komanda==Komande::Aktiviraj)
        else if(komanda==Komande::Deaktiviraj) 
        else if(komanda==Komande::Nalijevo)
        else if(komanda==Komande::Nadesno)
        else if(komanda==Komande::Idi)
        else if(komanda==Komande::Kraj)
    }*/
}
int main ()
{
    std::cout << "Dobrodosli!";
    try {
        for(;;) {
            Pravci pravac;
            Komande komanda;
            int parametar;
            int x,y;
            KodoviGresaka greska;
            std::cout << "Unesite komandu: ";
            if(UnosKomande(komanda, parametar, greska))
              IzvrsiKomandu(komanda,parametar, x, y, pravac);
            else PrijaviGresku(greska);
        }
    } catch(...) {
        std::cout << "Dovidjenja!" << std::endl;
    }
	return 0;
}
