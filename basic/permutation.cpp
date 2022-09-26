#include <iostream>
#include <utility>
#include <iterator>
#include <string>
#include <algorithm>

//find all permutations of string str[start]~str[end]
void permutation(std::string str, int start, int end)
{
    if(start == end)
    {
        std::cout << str << std::endl;
        return;
    }

    for(int i = start; i <= end; ++i)
    {
        std::swap(str[start], str[i]);
        permutation(str, start + 1, end);
        std::swap(str[start], str[i]);
    }
}

//print all permutation using
void permutation_std(std::string str)
{

    do {
        std::cout << str << std::endl;
    }while(std::next_permutation(str.begin(), str.end()));
}


int main()
{
    std::string test = "lbc";
    permutation(test, 0, test.length() - 1);
    std::cout << std::endl;
    std::sort(test.begin(), test.end());
    permutation_std(test);
    return 0;
}
