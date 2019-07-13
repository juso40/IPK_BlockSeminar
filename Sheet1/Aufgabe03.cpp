#include<iostream>
#include<string>


int getNum1(std::string calc){
    int number = 0;
    char zero = '0';

    for (int i=0; i<calc.size(); i++){
        if (calc[i]=='+' || calc[i]=='-' || calc[i]=='*' || calc[i]=='/')
            break;
        if (calc[i]<='9' && calc[i]>='0'){
            number=number*10+calc[i]-zero;
        }
    }
    return number;
}

int getNum2(std::string calc){
    int number = 0;
    char zero = '0';

    for (int i=0; i<calc.size(); i++){
        if (calc[i]=='+' || calc[i]=='-' || calc[i]=='*' || calc[i]=='/'){
            for (int n=i+1 ;n<calc.size(); n++){
             if (calc[n]<='9' && calc[n]>='0'){
                 number=number*10+calc[n]-zero;
                }
            }
        }
    }
    return number;
}

char getOp(std::string calc){
    char op;

    for (int i=0;i<calc.size(); i++){
        if (calc[i]=='+' || calc[i]=='-' || calc[i]=='*' || calc[i]=='/'){
            op= calc[i];
            break;
        }
    }
    return op;
}




int main(){
    std::string simple_calc;

    std::cout<<"Bitte geben Sie eine Rechnung ein: "<<std::endl;
    std::getline(std::cin, simple_calc);

    int number1 = getNum1(simple_calc);
    int number2 = getNum2(simple_calc);
    char op = getOp(simple_calc);

   // std::cout<<number1<<std::endl;
   // std::cout<<number2<<std::endl;
   // std::cout<<op<<std::endl;

    if (op=='+')
        std::cout<<number1+number2<<std::endl;

    if (op=='-')
        std::cout<<number1-number2<<std::endl;

    if (op=='*')
        std::cout<<number1*number2<<std::endl;

    if (op=='/'){
        if (number2==0){
            std::cout<<"Divide by 0 error!"<<std::endl;
        }
        std::cout<<number1/number2<<std::endl;
    }


}