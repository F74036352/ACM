#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	int m=0;
	float c=0;
	float d=0;
	float n=0;
	float answer=0;
	int i=1;
	while (scanf("%d",&m)!=EOF)
	{
		while (i<=m)
		{
			scanf("%f %f",&c,&d);
			n=(9*c)/5+32+d;
			answer=(n-32)*5/9;
			printf("Case %d: %.2f\n",i,answer);
			++i;
		}
		i=1;
		m=0;
		c=0;
		d=0;
		n=0;
		answer=0;
	}
	return 0;
}