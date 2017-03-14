#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if(a==0)
	{
		return b;
	}
	else
	{
		return gcd(b%a,a);
	}


}

int main()
{
	int step=0;
	int mod=0;
	int answer=0;
	while (scanf("%d %d",&step,&mod)==2)
	{
		answer=gcd(step,mod);
		if(answer==1)
		{
			printf("%10d%10d    Good Choice\n\n",step,mod);
		}
		else 
		{
			printf("%10d%10d    Bad Choice\n\n",step,mod);
		}

		step=0;
		mod=0;
		answer=0;
	}




}