#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	int cent[7490];	
	for(int i=0;i<7490;++i)
	{
		cent[i]=1;
	}

	int type[5]={1,5,10,25,50};
	int n=0;
	
		for (int j=1;j<5;++j)//把所有情形都算出來儲存
		{			
			for (int i=1;i<7490;++i)//不用管一塊，初始有了
			{
				if(i>=type[j])
				{
					cent[i]+=cent[i-type[j]];

				}
			}					
		}
	while (scanf("%d",&n)!=EOF)
	{	
		// for(int i=0;i<=n;++i)
		// {
		// 	printf("%d ",cent[i]);
		// }		
		// printf("\n");
		printf("%d\n",cent[n]);		
	}
	return 0;
}