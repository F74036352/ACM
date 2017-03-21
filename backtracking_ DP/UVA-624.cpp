#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

/*
題目放在backtracking，
但我用backtracking找不出錯在哪
改用DP，視為0/1背包問題
而且好像比較快 嗎
*/
int main()
{
	int n=0;
	int m=0;
	int count=0;
	int number[21]={0};
	int answer[21]={0};	
	int dp[20000]={0};
	int from[20000]={0};
	int location=0;
	int total=0;
	dp[0]=1;
	from[0]=0;

	while (scanf("%d %d",&n,&m)!=EOF)
	{
		for (int i=0;i<m;++i)
		{
			scanf("%d",&number[i]);
		}		
		/*dp*/
		for (int i=0;i<m;++i)
		{
			for (int j=n-number[i];j>=0;--j)
			{
				if (dp[j+number[i]]==0 && dp[j]==1)
				{
					dp[j+number[i]]=1;
					from[j+number[i]]=number[i];
				}
			}
		}
		/*find the nearest number to n*/
		//location=n;		
		for (location=n;location>=0;)
		{
			if (dp[location]==0)
			{
				--location;
			}
			else 
			{
				break;
			}
		}

		while (location!=0 && dp[location]!=0)
		{
			answer[count]=from[location];
			++count;
			location=location-from[location];
		}
		/*To print the answer*/
		for (int i=0;i<count;++i)
		{
			printf("%d ",answer[i]);
			total+=answer[i];
		}
		printf("sum:%d\n", total);
		/*To initialize*/
		for (int i=0;i<21;++i)
		{
			answer[i]=0;
			number[i]=0;
		}
		for (int i=0;i<2000;++i)
		{
			dp[i]=0;
			from[i]=0;
		}
		dp[0]=1;
		from[0]=0;
		location=0;
		total=0;
		count=0;


	}

}