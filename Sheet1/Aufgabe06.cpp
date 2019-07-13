#include<iostream>
#include<cmath>

int main(){
    int a, b, c;

    std::cout<<"ax^2 + bx + c = 0"<<std::endl;
    std::cout<<"Koeffizient a: "<<std::flush;
    std::cin>>a;
    std::cout<<"Koeffizient b: "<<std::flush;
    std::cin>>b;
    std::cout<<"Koeffizient c: "<<std::flush;
    std::cin>>c;

    double solution1;
    double solution2;

    solution1= (-b+sqrt((b*b-4*a*c)))/(2*a);
    solution2= (-b-sqrt((b*b-4*a*c)))/(2*a);

    std::cout<<"Lösung1: "<<solution1<<"\nLösung2: "<<solution2<<std::endl;
}
