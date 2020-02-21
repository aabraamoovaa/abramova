#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
 
void vec()
{
	int arr[5] = {-7, -2, 3, 5, 13};     
    std::vector<int> v(arr, arr + 5);                    
    for (int i = 0; i < v.size(); i++)
    {
    	while (v[i] < 0)
    	{
    		v[i] = - v[i];
    	}
        std::sort(v.begin(), v.end());
        std::cout << ((v[i])*(v[i])) << " " << '\n';  
    }
}

int main() 
{
	vec();
}

