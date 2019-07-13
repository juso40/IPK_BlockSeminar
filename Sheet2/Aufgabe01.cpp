#include<iostream>

void A(){
    int roof;
    int sum=0;
    std::cout<<"Summe aller Ungeraden bis n: "<<std::flush;
    std::cin>>roof;

    for (int i=0; i<roof; i++){
        if (i%2==1){
            sum+=i;
        }
    }

    std::cout<<sum<<std::endl;
}

void B(){
    int sum;
    for (int i=0; i<=20; i++){
        if (i%2==0){
            std::cout<<i<<" -> "<<i*i<<std::endl;
        }
    }

}

void C(){
    int number;
    std::cout<<"Multiplikationstabelle für die Nummer: "<<std::flush;
    std::cin>>number;

    for (int i=1; i<=number; i++){
        for (int n=1; n<=number; n++){
            std::cout<<i*n<<"\t";
        }
        std::cout<<"\n\n\n";
    }

}

int main(){
    std::cout<<"a, b oder c?"<<std::endl;
    char a;
    std::cin>>a;
    if (a=='a')
        A();
        else if (a=='b')
        B();
        else if (a=='c')
        C();
        else main();
}