#include <iostream>
#include <new>

//Fragmentirana alokacija
long long int  **StirlingoviBrojeviV1(int n) {
    if(n<=0) throw std::domain_error("Parametar ne smije biti negativan");
    //Alokacija grbave matrice
    long long int **Niz(nullptr);
    
    try {
        Niz=new long long int *[n];
        
        for(int i=0; i<n; i++) {
            Niz[i]=new long long int [2*i+1];
            Niz[i][i]=1;
            int pocetak(0), br=i+1,kraj=2*i;
            while(pocetak<i) {
                Niz[i][pocetak]=br;
                Niz[i][kraj]=br;
                pocetak++;
                kraj--;
                br--;
            }
        }
    } catch(std::range_error izuzetak) {
        for(int i=0; i<n; i++) {
            delete[] Niz[i];
        }
        delete[] Niz;
        throw std::range_error("Parametar prevelik za raspoloživu memoriju");
    }
    
    return Niz;
}

//Kontinualna alokacija
long long int **StirlingoviBrojeviV2(int n) {
    if(n<=0) throw std::domain_error("Parametar ne smije biti negativan");
    
    long long int **Niz=new long long int *[n]{};
    
    try {
        Niz[0]=new long long int[n*n];
  
    } catch(std::range_error) {
        delete[] Niz;
        throw std::range_error("Parametar prevelik za raspolozivu memoriju");
    }
    
    for(int i=1; i<n; i++) {
        Niz[i]=Niz[i-1]+2*(i-1)+1;
    }
    
    for(int i=0; i<n; i++) {
        int br=i+1;
        for(int j=0; j<2*i+1; j++) {
            Niz[i][j]=br;
            
            if(j<i) {
                br--;
            } else br++;
        }
    }
    
    return Niz;
}


int main ()
{
    try {
        //std::cout << "Koliko zelite redova:";
        int n; 
        std::cin >> n;
        
        long long int **p1(StirlingoviBrojeviV1(n));
        long long int **p2(StirlingoviBrojeviV2(n));
        
        
        std::cout << std::endl;
        for(int i=0; i<n; i++) {
            for(int j=0;j<2*i+1; j++) {
                std::cout << p1[i][j] << " ";
            }
            std::cout << std::endl;
        }
        
    for(int i=0; i<n; i++) {
        delete[] p1[i];
    }
    
    delete[] p1;
     
     
    /* for(int i=0; i<n; i++) {
         for(int j=0; j<2*i+1; j++) {
             std::cout << p2[i][j];
         }
         std::cout << std::endl;
     }  */
     
     delete[] p2[0];
     delete[] p2;
        
    } catch(std::domain_error e) {
        std::cout << "Izuzetak: " << e.what();
    } catch(std::range_error izuzetak) {
        std::cout << "Izuzetak: Parametar prevelik za raspoloživu memoriju";
    }
	return 0;
}
