//Justin Sostmann
#include <iostream>

class A
{
    public:
    void g();
};

void f(const A &a){
    std::cout << &a << std::endl;
}

void A::g()
{
    f(this); //this ist ein Zeiger und in der fuktion f wird eine Referenz erwartet,
    //Der pointer Referenziert bereits ein Objet, jedoch benötigt die funktion f ein Objekt, nicht die Referen darauf!
    //Die lösung ist "this" zu dereferenzieren mit einem * davor
    //also anstelle von f(this) f(*this)
}
 
int main() {
    A a;
    a.g();
    return 0;
}
