// Test Assignment Page:
// http://www.cprogramming.com/challenges/array_sum.html

#include <iostream>
#include <list>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main1(void) 
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

struct ListData {
	ListData(int ind, int end,  int sum) : m_StartIndex(0), m_EndIndex(0), m_Sum(0) {
		m_StartIndex = ind;
		m_EndIndex = end;
		m_Sum = sum;
	}
	ListData(const ListData& ref) {
		m_StartIndex = ref.m_StartIndex;
		m_EndIndex = ref.m_StartIndex;
		m_Sum = ref.m_Sum;
	}

	int m_StartIndex;
	int m_EndIndex;
	int m_Sum;
};

struct {
	bool operator()(ListData &a, ListData &b)
	{   
		return a.m_Sum < b.m_Sum;
	}   
} customLess;



int main(void)
{
	std::vector<int> data = {1, 2, -5, 4, -3, 2};
    int finalSum = 0;
    
    auto LS(data.begin()), LE(data.end());
    std::list<ListData> MaxForEachIteration;
    for (int mainLoop=0; mainLoop< data.size()  && LS != LE; mainLoop++) {
        std::list<ListData> localList;
        for (int i=0; i< data.size(); i++) {
            int sumSoFar = 0;
            for (int k=0;k<=mainLoop;k++) {
                sumSoFar += data[k];
            }
            localList.push_back(ListData(mainLoop, i, sumSoFar));
        }

        // Find maximum.
        std::sort(localList.begin(), localList.end(), customLess);
        auto LocLS(localList.begin()), LocLE(localList.end());
        for ( ;  LocLS != LocLE; LocLS++) {
            printf("\n\r =================== %d %d %d", LocLS->m_StartIndex, LocLS->m_EndIndex, LocLS->m_Sum);
        }

        MaxForEachIteration.push_back(*localList.rbegin());
        LS++;
    }
    
    cout<<"\n\r The final sum is: "<< finalSum << std::endl;
}
