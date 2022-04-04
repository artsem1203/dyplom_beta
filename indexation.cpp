#include <iostream>
#include "indexationLib/Data.h"

int main()

{
    Data<int, 2> a(2, 3);
    a.init({ 1,2,3,4,5,6 });
    a.show();

    const Data<int, 2>& ra = a;
    Const_Handler<int, 1> ch = ra.get_const_handler<int, 1>(ra.get_element(0, 1), 3);
    const Handler<int, 1> handl;

    handl = *ra.get_const_handler<int, 1>(ra.get_element(1), 3);
    ch.show();

    std::cout << "----" << std::endl;
    Handler<int, 1> h(ch->derived());
    std::cout << *ra.get_element(1, 0) << std::endl;
    std::cout << *ch.get_element(2) << std::endl;
    std::cout << ++*h.get_element(2) << std::endl;
    std::cout << *handl.get_element(2) << std::endl;
    std::cout << "Hello World!\n";
}