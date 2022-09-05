//============================================
// Problem: 151 - power crisis
// Author : Hao-Yu Hung
// Date   : 2022/08/22
//============================================

#include <iostream>
#include <vector>

const int CRITICAL_REGION = 13;

int josephus(int n, int m)
{
	int last = 0;
    // i : number of node in cycle
	for (int i = 2; i <= n; i++)
		last = (last + m) % i;
	return last;
}

int josephus_recursion(int n, int m) {
   return n > 1 ? (josephus_recursion(n - 1, m) + m) % n : 0;
}

int findMinSpan(int numOfRegions, int criticalRegion)
{
    int span = 1;
    while(span)
    {
        int last = josephus(numOfRegions-1, span) + 1;
        if(last == criticalRegion-1)
            return span;
        ++span;
    }
    return -1;
}

int main(int argc, char** argv)
{
    int numOfRegions;
    std::vector<int> all;
    while(std::cin >> numOfRegions && numOfRegions)
    {
        if(numOfRegions == 0)
            break;
        all.push_back(numOfRegions);
    }
    for(auto it = all.begin(); it != all.end(); ++it)
    {
        std::cout << findMinSpan(*it, CRITICAL_REGION) << "\n";
    }
    return 0;
}


