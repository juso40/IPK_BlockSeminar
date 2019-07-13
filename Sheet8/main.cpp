#include "List.h"
#include <iostream>

int main(){

    List list(1);

    list.add(3);
    list.add(3);
    list.add(3);
    list.add(3);

    list.print();

    list.erase(3);
    list.print();
   
}