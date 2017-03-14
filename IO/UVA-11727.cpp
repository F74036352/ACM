#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t=0;
	int num[3]={0};
	int i=1;
	int answer=0;
	while (scanf("%d",&t)!=EOF)
	{	
		while (i<=t)
		{
			
			scanf("%d %d %d",&num[0],&num[1],&num[2]);
			sort(num,num+3);
			printf("Case %d: %d\n",i,num[1]);			
			//answer=max(min(max(num[0],num[1]),num[2]),min(num[0],max(num[1],num[2])));
			//printf("Case %d: %d\n",i,answer);
			++i;

		}
		i=1;
		t=0;
		answer=0;
	}






	return 0;
}