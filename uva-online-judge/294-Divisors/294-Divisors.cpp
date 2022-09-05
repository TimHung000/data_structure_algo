#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

const long MAX = 1000000000;
const long SQRT_MAX = 33334;
bool isPrime[SQRT_MAX];
long prime[SQRT_MAX];
int primeSize = 0;

void buildPrimeTable()
{
    std::fill_n(isPrime, SQRT_MAX, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i <= SQRT_MAX; ++i)
    {
        if(!isPrime[i]) continue;
        for(int j = i * 2; j <= SQRT_MAX; j += i)
           isPrime[j] = false;
    }

    for(int i = 2; i <= SQRT_MAX; ++i)
    {
        if(isPrime[i])
            prime[primeSize++] = i;
    }
}

int getDivisorCount(int n)
{
    if( n == 1) return 1;
    if( n < SQRT_MAX && isPrime[n]) return 2;

    int count = 1;

    for(int i = 0; i < primeSize && prime[i] * prime[i] <= n; ++i)
    {
        int exp = 1;
        while(n % prime[i] == 0)
        {
            n /= prime[i];
            ++exp;
        }
        count *= exp;
    }

    if(n != 1) count = count * 2;

    return count;
}

int main(int argc, char** argv)
{
    buildPrimeTable();
    int line;
    std::cin >> line;
    while(line--)
    {
        long lower, upper;
        std::cin >> lower >> upper;
        long maxNumber = 0;
        long maxDivisorCount = 0;
        for(int i = lower; i <= upper; ++i)
        {
            int currentCount = getDivisorCount(i);
            if( currentCount > maxDivisorCount)
            {
                maxNumber = i;
                maxDivisorCount = currentCount;
            }
        }
        std::cout << "Between " << lower << " and " << upper << ", " << maxNumber << " has a maximum of " << maxDivisorCount << " divisors.\n";
    }
    return 0;
}
