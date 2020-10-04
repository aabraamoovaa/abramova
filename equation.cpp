#include <iostream>
#include <cmath>
#include <assert.h>

int discriminant(double a, double b, double c, double* D)
{
    *D = pow(b, 2) - 4*a*c;
    return *D;
}

int number_of_roots(double a, double b, double c, double* D, double* x1, double* x2)
{
	assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    if (a != 0)
    {
        if (*D > 0)
        {
            return 2;
        }
        else if (*D == 0) 
        {
            return 1;
        } 
        else 
        {
            return 0;
        }
    } 
    else 
    {
        if (b != 0)
        {
            return 1;
        } 
    }
}

void roots(double a, double b, double c, double* D, double* x1, double* x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    if (a != 0)
    {
        if (*D > 0)
        {
            *x1 = (-b + sqrt(*D)) / (2*a);
            *x2 = (-b - sqrt(*D)) / (2*a);
        }
        else if (*D == 0) 
        {
            *x1 = -b / (2*a);
            *x2 = *x1;
        } 
    } 
    else 
    {
        if (b != 0)
        {
            *x1 = -c / b;
        } 
    }
}

void answer(double a, double b, double c, double& D, double& x1, double& x2)
{
    int number = 0;
    number = number_of_roots(a, b, c, &D, &x1, &x2);
    roots(a, b, c, &D, &x1, &x2);
    switch(number)
    {
        case 0:
            std::cout << "Нет действительных корней" << std::endl;
        break;
        case 1:
            std::cout << "x = " << x1;
        break;
        case 2:
            std::cout << "x1 = " << x1 << std::endl;
            std::cout << "x2 = " << x2 << std::endl;
        break;
    }
}

int main()
{
	double a;
	double b;
	double c;
    double D;
	double x1;
	double x2;

    std::cout << "Введите a: ";
    std::cin >> a;
    std::cout << "Введите b: ";
    std::cin >> b;
    std::cout << "Введите c: ";
    std::cin >> c;
    D = discriminant(a, b, c, &D);
    answer(a, b, c, D, x1, x2);
    return 0;
}
