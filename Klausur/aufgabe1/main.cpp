//Justin Sostmann
#include <iostream>
#include <string>

        //checkt auf nicht ziffern
bool keine_zahl(std::string& alter){
    for (int i=0; i<alter.size(); i++){
        if (alter[i]<'0' || alter[i]>'9'){
            return true;
            break;
        }
    }
    return false;
}


int main(){
    std::string name;
    std::string alter;

    std::cout<< "Bitte geben sie Ihren name an: "<<std::flush;
    std::getline(std::cin, name);

    std::cout<<"Wie alt sind Sie?"<<std::endl;
    std::getline(std::cin, alter);

    if (keine_zahl(alter)==true){
        std::cout<<"Dein Alter enthält Zeichen, die keine Ziffern sind!"<<std::endl;
    } else {
    
    
        std::cout<<"Hallo "<<name<<", du bist "<<alter<<" Jahre alt!"<<std::endl;

        //berechnet die Quersumme
        int quersumme;
        for (int i=0; i<alter.size(); i++){
            quersumme= quersumme + alter[i] - '0';
        }

        std::cout << "Die Quersumme deines Alters ist: "<< quersumme<<std::endl;
    }

}