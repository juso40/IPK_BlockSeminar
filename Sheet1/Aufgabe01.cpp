#include <iostream>
#include <string>

int main(){
    std::string name;
    std::string beruf;
    int alter;
    float netto;

    std::cout<<"Name bitte:"<<std::flush;
    std::getline(std::cin, name);

    std::cout<<"Beruf: "<<std::flush;
    std::getline(std::cin, beruf);

    
    std::cout<<"Alter: "<<std::flush;
    std::cin>>alter;

    std::cout<<"Nettoverdienst: "<<std::flush;
    std::cin>>netto;

    std::cout<<"Ihre Angaben:\nName: "<<name<<"\nBeruf: "<<beruf
        <<"\nAlter: "<<alter<<"\nNettoverdienst: "<<netto<<std::endl;

}