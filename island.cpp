#include <vector>  
#include <iostream>
#include <fstream>

int main()
{
	std::fstream f("1.txt");
    int count = 0;// число чисел в файле
	int temp;
	while (!f.eof())
	{
		f >> temp;
		count++;
	}
	f.seekg(0, std::ios::beg);
	int count_space = 0;
	char symbol;
	while (!f.eof())
	{
		f.get(symbol);
		if (symbol == ' ')
			count_space++;
		if (symbol == '\n')
			break;
	}
	f.seekg(0, std::ios::beg);
	int n = count / count_space;//число столбцов
	int m = count_space;//число строк

	int countland = 0; //число островов
 	std::vector < std::vector <int> > vec(n, std::vector <int> (m));
	for (int i = 0; i < m; i++)
	{	
		std::cout<<"\n";
		{
			for (int j = 0; j < n; j++)
			{
				f >> vec[i][j];
			    std::cout << vec[i][j] << ' ';
			    if ((vec[i][j] == 1))
			    {
			    	countland++;
			    
			    if ((vec[i][j-1]==1)||((vec[i][j+1]==1))||(vec[i-1][j]==1)||(vec[i+1][j]==1))
			    {
			        countland = countland-1;
			    };
			    }
	        }
	    }
	}
    std::cout<<"\n"<<"Количество островов: "<<countland<< std::endl;
    return 0;
}
