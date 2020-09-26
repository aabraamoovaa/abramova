#include <iostream>
#include <cmath>
#include <assert.h>
using namespace std;

int number_of_roots(double a, double b, double c, double* x1, double* x2)
{
	assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    double D = pow(b, 2) - 4*a*c;
    if(a != 0)
    {
        if(D > 0)
        {
            *x1 = (-b + sqrt(D)) / (2*a);
            *x2 = (-b - sqrt(D)) / (2*a);
            return 2;
        }
        else if (D == 0) 
        {
            *x1 = -b / (2*a);
            *x2 = *x1;
            return 1;
        } 
        else 
        {
            return 0;
        }
    } 
    else 
    {
        if(b != 0)
        {
            *x1 = -c / b;
            return 1;
        } 
    }
}
int main()
{
	double a;
	double b;
	double c;
	double x1;
	double x2;
	int number = 0;

    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите c: ";
    cin >> c;
    number = number_of_roots(a, b, c, &x1, &x2);
    switch(number)
    {
    	case 0:
        	std::cout << "Нет действительных корней" << endl;
        break;
    	case 1:
        	std::cout << "x = " << x1;
        break;
    	case 2:
        	cout << "x1 = " << x1 << endl;
        	cout << "x2 = " << x2 << endl;
        break;
    }
    return 0;
}
