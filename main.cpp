#include <vector>
#include <iostream>
#include "Polynome.hpp"
using std::vector, std::cout, std::endl;

int main()
{
    vector<double> test1 = {4, 3, 2, 1};
    vector<double> test2 = {1, 2, 3};
    cout << endl;
    Polynome *eq1 = new Polynome(test1);
    Polynome *eq2 = new Polynome(test2);

    eq1->PrintEq();
    cout << endl;

    Polynome i = (*eq1).AddEq(*eq2);
    i.PrintEq();

    int n = 2;
    cout << endl << "First equation solved for x = " << n << ": " << eq1->CalculateEq(n) << endl;

    Polynome result = eq1->IntegrateEq();
    cout << endl;
    result.PrintEq();
    cout << endl;

    delete eq1;
    delete eq2;
    return 0;
}