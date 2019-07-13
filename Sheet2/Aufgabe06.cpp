#include<iostream>
#include<string>


int convert_number(std::string number, int base){
    int zahl = 0;
    char zero = '0';

    for (int i=0; i<number.size(); i++){
        if (number[i]<='9' && number[i]>='0'){
            zahl=zahl*10+number[i]-zero;
        }
    }
    return zahl;
}


int main(){
    int base;
    std::string zahl;
    std::cout<<"Gib Zahl pls: "<<std::flush;
    std::getline(std::cin,zahl);
    std::cout<<"Gib base pls: "<<std::flush;
    std::cin>>base;

    std::cout<<"als int mit deiner base: "<<convert_number(zahl, base)<<std::endl;

}