#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int p=0;
int q=0;
int r=0;
int s=0;
int t=0;
int u=0;

double fun(double x)
{
	double fx=0;
	fx=p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
	return fx; 

}

int main()
{
	
	double tmp=0;
	double answer=0;	
	double min=0;
	double max=1;
	double mid=0;
	int count=0;
	while (scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF)
	{
		min=0;
		max=1;
		count=100;
		while (count!=0)
		{
			--count;
			mid=(max+min)/2;
			if (fun(mid)>0)
			{
				min=mid;
			}
			else
			{
				max=mid;
			}
		}
			if (fabs(fun(mid))>0.0000000001)//1e-10
			{
				printf("No solution\n");
			}
			else
			{
				printf("%.4f\n",mid);
			}
		
	}




	return 0;
}