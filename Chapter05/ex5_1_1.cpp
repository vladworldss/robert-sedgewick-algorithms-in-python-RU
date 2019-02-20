#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <iostream>

typedef std::pair<unsigned long long, unsigned long long> PolyPair;

#ifdef __cplusplus
extern "C" {
#endif
unsigned long long factFactorial(unsigned N)
{
	bool* sieve = new bool[N+1];
	std::vector<PolyPair> pairs;
	
	for (unsigned i = 2; i <=N; ++i)
	{
		if (!sieve[i])
		{
			unsigned degr = N/i;
			unsigned acc = 0;
			
			while ( degr > 0)
			{
				acc += degr;
				degr /= i;
			}
			
			pairs.push_back(std::move(PolyPair{i, acc}));
			
			unsigned j = 2;
			while (i*j <= N)
			{
				sieve[i*j] = true;
				++j;
			}
		}
	}
	
	unsigned long long res = 1;
	for(auto p : pairs)
	{
		res *= pow(p.first, p.second);
	}
	std::cout << res << std::endl;
	delete[] sieve;
	return res;	
}
#ifdef __cplusplus
}
#endif

int main()
{
	
	std::cout << factFactorial(20) << std::endl;
	return 0;
}