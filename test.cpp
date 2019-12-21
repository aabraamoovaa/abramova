#include <iostream>
#include "list.h"

int main()
{
	List list, list1;
    list.push_back(1);
    list.push_back(2);

    list.push_back(10);
    std :: cout << list[0] << "\n"; //1
    std :: cout << list[2] << "\n"; // 10
    std :: cout << list.len() << "\n"; // размер 3

    list.push_front(8);
    list.push_front(16);
    std :: cout << list[0] << "\n"; // 16

    list.pop_front();
    std :: cout << list[0] << "\n"; //8

	list.pop_back();
    std :: cout << list[2] << "\n"; //2

	list.print();

    list.clear();
    std :: cout << list.len() << "\n";    //размер 0

    int arr[] = {2, 2, 10, 3, 2, 1, 7, 7};
    for(int i = 0; i < 8; i ++)
    {
    	list.push_back(arr[i]);
    }
    std :: cout << list.len() << "\n"; // размер 8
    list.print();
}
