#include<iostream>


int main(){
    int fahrenheit;
    std::cout<<"Wie viel Grade Fahrenheit ist es?"<<std::endl;
    std::cin>>fahrenheit;

    int celsius= ((fahrenheit-32)*5)/9;
    std::cout<<"In Celsius: "<<celsius<<std::endl;


}