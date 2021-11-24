#include <iostream>
#include "BigDecimalInt.h"
    using string = std::string;

int main()
{
    string n, n1;
    int k;


    std::cout << "1- Perform Addition \n";
    std::cout << "2- Perform Subtraction \n";
    std::cout << "3- Exit\n";
    std::cin >> k;
    if(k==1)
    {
        std::cout << "enter two number \n";
        cin >> n >> n1;
        BigDecimalInt obj(n), obj2(n1), obj3;
        if (n1.at(0) == '-')
        {
            obj3 = obj + obj2;
            obj3 = obj3 - obj2;
            obj3 = obj3 - obj2;

        }
        else if (n.at(0) == '-')
        {

            obj3 = obj + obj2;
            obj3 = obj3 - obj;
            obj3 = obj3 - obj;
        }
        else
            obj3 = obj +obj2;
        cout << obj3;
    }
    if (k == 2)
    {
        std::cout << "enter two number \n";
        cin >> n >> n1;
        BigDecimalInt obj(n), obj2(n1), obj3;

        obj3 = obj - obj2;
        std::cout << obj3;
    }

    if (k == 3)
        return 0;


}