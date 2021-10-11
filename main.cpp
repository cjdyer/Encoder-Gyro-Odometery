#include <iostream>
#include "Odometery.h"

Odometery odo(0);

int main()
{
    std::cout << "Object ID : " << (int)odo.GetID() << std::endl;
    return 0;
}
