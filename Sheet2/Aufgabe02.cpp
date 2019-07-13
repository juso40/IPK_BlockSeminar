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


int main(){
    int zahl;
    std::cout<<"Gib Zahl: "<<std::flush;
    std::cin>>zahl;
    if (zahl<0)
        zahl*=-1;

    if (is_prime(zahl)==true){
        std::cout<<"Ist prim :)"<<std::endl;
    }else
    {
        std::cout<<"Nicht prim :´("<<std::endl;
    }
    
}