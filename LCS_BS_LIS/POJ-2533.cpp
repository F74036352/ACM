#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int q[1001]={0};
int lis[1001]={0};
int n=0;

void Find_LIS()
{
	int i=0;
	int j=0;
	for (i=1;i<=n;++i)
	{
		lis[i]=1;
		for (j=1;j<i;++j)
		{
			if (q[j]<q[i] && lis[j]+1>lis[i])
			{
				lis[i]=lis[j]+1;
			}
		}
	}
		sort(lis,lis+n+1);
		reverse(lis,lis+n+1);
		// for(int i=0;i<=n;++i)
		// printf("%d\n",lis[i]);

		printf("%d\n",lis[0]);
}

int main()
{
	
	int count=0;
	while (scanf("%d",&n)!=EOF)
	{
		count=1;
		while (count<=n)
		{
			scanf("%d",&q[count]);
			++count;
		}
		Find_LIS();
		
		for (int i=0;i<1001;++i)
		{
			q[i]=0;
			lis[i]=0;
		}
	}



	return 0;
}