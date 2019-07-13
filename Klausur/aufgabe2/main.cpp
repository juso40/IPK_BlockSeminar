//Justin Sostmann
#include <iostream>
#include <cmath>

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
//habe die Formel nicht ganz verstanden :(
double myExp(double expo){
    double solution=1+expo;


    for (int i=2 ; i<=50; i++){
        solution= solution + (pow(expo, (double)i))/((double)factorial(i));
    }

    return solution;
}

int main(){
 //berechnet von -1 bis 1 alle angenährten zahlen von myExp
    double x=-1;
        for (int i=0; i<=20; i++){
            std::cout<<"x="<<x<<std::endl;
            std::cout<<"y="<< myExp(x) <<std::endl;
            x=x+0.1;
        }

}