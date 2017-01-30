// Test Assignment Page:
// http://www.cprogramming.com/challenges/array_sum.html

#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

int main(void) 
{
	std::list<int> data = {1, 2, -5, 4, -3, 2};
	int finalSum = 0;
	
	auto LS(data.begin()), LE(data.end());
	while (LS != LE) {
		finalSum = *LS;
		LS++;
	}
	
	cout<<"\n\r The final sum is: "<< finalSum << std::endl;
	return 0;
}
