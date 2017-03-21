#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int  main()
{
	typedef struct
	{
		int weight;
		int value;
		int use;
	}ray;
	ray array[4000];
	for (int i=0;i<4000;++i)
	{
		array[i].weight=0;
		array[i].value=0;
		array[i].use=0;
	}

	int cost[15000]={0};
	int n=0;
	int m=0;
	int tmp=0;
	while (scanf("%d %d",&n,&m)!=EOF && n!=0)
	{
		tmp=0;
		while (tmp<n)
		{
			scanf("%d %d",&array[tmp].weight,&array[tmp].value);
			// if (cost[array[tmp].weight]<array[tmp].value)
			// {
			// 	cost[array[tmp].weight]=array[tmp].value;
			// }
			++tmp;			
		}
		
		for (int i=0;i<n;++i)
		{
			for (int j=m;j>=1;--j)
			{
				if (j-array[i].weight>=0 && cost[j-array[i].weight]+array[i].value > cost[j] )
				{
					cost[j]=cost[j-array[i].weight]+array[i].value;
				}
			}				
		}
		printf("%d\n",cost[m]);	
		for (int i=0;i<4000;++i)
		{
			array[i].weight=0;
			array[i].value=0;
			array[i].use=0;
		}
		for (int i=0;i<=m;++i)
		{
			cost[i]=0;
		}
	}



	return 0;
}
