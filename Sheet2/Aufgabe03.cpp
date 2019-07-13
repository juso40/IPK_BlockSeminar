#include<iostream>

bool is_prime(int zahl){
    bool primed=true;
    for (int i=2; i<zahl; i++){
        if ((zahl%i) == 0 ){
            primed=false;
            break;
        }
    }
    return primed;
}

void print_primes(int upto){
    for (int i=0; i<upto; i++){
        if (is_prime(i)==true){
            std::cout<<i<<std::endl;
        }
    }

}

int main(){
    int zahl;
    std::cout<<"Gib Zahl: "<<std::flush;
    std::cin>>zahl;
    if (zahl<0)
        zahl*=-1;

    print_primes(zahl);
    
}