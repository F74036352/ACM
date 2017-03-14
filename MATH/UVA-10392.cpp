#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#define MAX 1000000
using namespace std;
vector<long long int> prime;
vector<long long int> answer;
bool isPrime(int n)
{
	for(int i=0; prime[i]*prime[i]<=n;++i)
	{
		if(n % prime[i]==0)
		{
			return false;
		}
	}
	return true;

}
// void MakePrime()
// {
// 	prime.push_back(2);
// 	prime.push_back(3);
// 	for(int i=5,gap=2;i<MAX;i+=gap,gap=6-gap)
// 		if(isPrime(i)) prime.push_back(i);

// }
int main()
{
	long long int number;
	long long int tmp=number;
	while(scanf("%lld",&number)==1)
	{
		if(number>1)
		{
		prime.push_back(2);
		prime.push_back(3);
		
		for(int i=5,gap=2;i<MAX;i+=gap,gap=6-gap)
		{	

			if(isPrime(i))
			{				
				prime.push_back(i);				
			}
		}	
		for(int i=0;i<prime.size();++i)
		{
			if(number%prime[i]==0)
			{
				number=number/prime[i];
				answer.push_back(prime[i]);
				i=-1;
			}
			
		}	
		if(number!=1)
		{
			answer.push_back(number);
		}
		for(int i=0;i<answer.size();++i)
		{		
			printf("    %lld\n",answer[i]);
		}
		printf("\n");
		prime.clear();
		answer.clear();
		}
		else
		{
			return 0;
		}


	} 






}