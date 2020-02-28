#include <vector>  
#include <iostream>
#include <fstream>
using namespace std;  


int main()
{
	fstream f("1.txt");
    int count = 0;// число чисел в файле
	int temp;//Временная переменная

	while (!f.eof())// пробегаем пока не встретим конец файла eof
	{
		f >> temp;//в пустоту считываем из файла числа
		count++;// увеличиваем счетчик числа чисел
	}
 
		//Число чисел посчитано, теперь нам нужно понять сколько
		//чисел в одной строке
		//Для этого посчитаем число пробелов до знака перевода на новую строку 
 
	//Вначале переведем каретку в потоке в начало файла
	f.seekg(0, ios::beg);
	f.clear();
 
	//Число пробелов в первой строчке вначале равно 0
	int count_space = 0;
	char symbol;
	while (!f.eof())//на всякий случай цикл ограничиваем концом файла
	{
		//теперь нам нужно считывать не числа, а посимвольно считывать данные
		f.get(symbol);//считали текущий символ
		if (symbol == ' ') count_space++;//Если это пробел, то число пробелов увеличиваем
		if (symbol == '\n') break;//Если дошли до конца строки, то выходим из цикла
	}
	//cout << count_space << endl;
 
	//Опять переходим в потоке в начало файла
	f.seekg(0, ios::beg);
	f.clear();
 
	//Теперь мы знаем сколько чисел в файле и сколько пробелов в первой строке.
	//Теперь можем считать матрицу.
    int countland = 0;
	int n = count / (count_space + 1);//число строк
	int m = count_space + 1;//число столбцов на единицу больше числа пробелов
	double **x;
	x = new double*[n];
	for (int i = 0; i<n; i++) x[i] = new double[m];
 	
 				    vector < vector <int> > vec(n, vector <int> (m));
	//Считаем матрицу из файла
	for (int i = 0; i < 1000; i++)
	{	
		cout<<"\n";
		{
			for (int j = 0; j < 1000; j++)
			{
				f >> x[i][j];

			    cout << x[i][j] << ' '; // Вывод элементов i строки вектора

			    if ((x[i][j] == 1))
			    {
			    	countland++;
               		    }

	        }
	    }
	}
    cout<<"\n"<<"Kol-vo land: "<<countland<<endl;

    return 0;
}
