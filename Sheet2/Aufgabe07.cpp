#include<iostream>
#include<string>



void pattern(int width){
  int space=(width+1)/2;
    for (int i=0; i<=(width+1)/2; i++){
        for (int n=1; n<=space; n++){
            std::cout<<" ";
        }
        space--;
        for (int n=1; n<=i*2-1; n++){
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
    space=1;
    for (int i=1; i<=(width-1)/2; i++){
        for (int n=1; n<=space; n++){
            std::cout<<" ";
        }
        space++;
        for (int n=1; n<=(width-2*i); n++){
            std::cout<<"*";
        }
    std::cout<<"\n";
    }

}


int main(){
    std::cout<<
        "Please provide a width for the diamond pattern (must be odd and positive): "<<std::flush;
    int width;
    std::cin>>width;
    if (width<0 || width%2==0){
        std::cout<<"Try again, it's not that hard :)"<<std::endl;
        main();
    }
    std::cout<<"\n\n"<<std::endl;
    pattern(width);
}