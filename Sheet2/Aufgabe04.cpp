#include<iostream>


int pow(int base, int expo){
    int sum=base;
    for (int i=1; i<expo; i++)
        sum*=base;
    if (expo==0)
        sum=1;
    return sum;
}

int main(){
    int a,b;
    std::cout<<"Gib base und einen expo: "<<std::endl;
    std::cin>>a;
    std::cin>>b;

    std::cout<<pow(a,b)<<std::endl;
}