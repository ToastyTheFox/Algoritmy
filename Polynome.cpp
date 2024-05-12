#include <vector>
#include <iostream>
#include <cmath>
using std::vector, std::cout, std::endl;
#include "Polynome.hpp"

#define AFTER_QUADRA 2
#define LINEAR 1
#define CONSTANT 0

Polynome::Polynome(vector<double> A)
{
    this->order = 0;
    vector<double> temp = {};
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (!order and A[i])
            order = i;
        if (order)
            temp.push_back(A[i]);
    }
    this->coefficients = temp;
}

void Polynome::PrintEq()
{
    cout << "The highest order of x in the polynome is x^" << this->order << "." << endl;
    cout << "Polynome: ";
    if (this->coefficients.empty())
    {
        cout << "0" << endl;
        return;
    }
    for (int i = 0; i <= this->order - AFTER_QUADRA; i++)
    {
        if (i == 0)
        {
            if (this->coefficients[i] > 0)
            {
                if (coefficients[i] == 1)
                    cout << "x^" << order - i << " ";
                else
                    cout << this->coefficients[i] << "x^" << order - i << " ";
            }
            else if (this->coefficients[i] < 0)
                cout << abs(this->coefficients[i]) << "x^" << order - i << " ";
        }
        else
        {
            if (this->coefficients[i] > 0)
            {
                if (coefficients[i] == 1)
                    cout << "+ x^" << order - i << " ";
                else
                    cout << "+ " << this->coefficients[i] << "x^" << order - i << " ";
            }

            else if (this->coefficients[i] < 0)
            {
                if (abs(coefficients[i]) == 1)
                    cout << "- x^" << order - i << " ";
                else
                    cout << "- " << abs(this->coefficients[i]) << "x^" << order - i << " ";
            }
        }
    }
    if (order >= LINEAR)
    {
        int index = order - LINEAR;
        if (index == 0)
        {
            if (this->coefficients[index] == 1)
                cout << "x ";
            else
                cout << this->coefficients[index] << "x ";
        }
        else if (this->coefficients[index] > 0)
        {
            if (this->coefficients[index] == 1)
                cout << "+ x ";
            else
                cout << "+ " << this->coefficients[index] << "x ";
        }
        else if (this->coefficients[index] < 0)
        {
            if (abs(this->coefficients[index]) == 1)
                cout << "- x ";
            else
                cout << "- " << abs(this->coefficients[index]) << "x ";
        }
    }
    int index = order - CONSTANT;
    if (this->coefficients[index] > 0)
        cout << "+ " << this->coefficients[index] << endl;
    else if (this->coefficients[index] < 0)
        cout << "- " << abs(this->coefficients[index]) << endl;
    else
        cout << endl;
}

Polynome Polynome::AddEq(Polynome eq2)
{
    int ord = std::max(this->order, eq2.GetOrder());
    vector<double> result(ord + 1, 0);

    for (int i = 0; i <= ord; ++i)
    {
        if (i <= this->order)
        {
            result[i] += this->coefficients[i];
        }
        if (i <= eq2.GetOrder())
        {
            result[i] += eq2.GetCoef(i);
        }
    }

    return Polynome(result);
}

Polynome Polynome::SubstractEq(Polynome eq2)
{
    Polynome eq1 = *this;
    int ord = std::max(eq1.GetOrder(), eq2.GetOrder());
    vector<double> result;
    for (int i = 0; i < ord; i++)
        result.push_back(eq1.coefficients[i] - eq2.coefficients[i]);
    return result;
}

double Polynome::CalculateEq(double n)
{
    int result = 0;
    for (int i = this->order; i >= 0; i--)
        result += this->coefficients[i] * pow(n, i);
    return result;
}

Polynome Polynome::DeriveEq()
{
    vector<double> result(this->order, 0);
    for (int i = 1; i <= this->order; ++i)
    {
        result[i - 1] = this->coefficients[i] * i;
    }
    return Polynome(result);
}

Polynome Polynome::IntegrateEq()
{
    vector<double> result(this->order + 2, 0);
    for (int i = 0; i <= this->order; ++i)
    {
        result[i + 1] = this->coefficients[i] / (i + 1);
    }
    return Polynome(result);
}
