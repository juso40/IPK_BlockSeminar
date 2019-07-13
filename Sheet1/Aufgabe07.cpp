#include<iostream>

int main(){
    int fib=0;
    std::cout<<"Fib bis: "<<std::flush;
    std::cin>>fib;
    int sum=0;
     int a =1;
     int b=1;
    for (int i=0; i<fib; i++){
        std::cout<<sum<<std::endl;
        a=b;
        b=sum;
        sum=a+b;
    }
//kommt zum int overflow
}