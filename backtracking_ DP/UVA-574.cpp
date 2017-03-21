#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int number[12]={0};
int answer[12]={0};
int all[10000][12]={0};
int n=0;
int t=0;
int j=0;
int k=0;
int test=0;
void backtracking(int d,int num)
{
		
	if (num==t)
	{
		
		for (int i=0;i<j;++i)
		{
			all[k][i]=answer[i];
		}
		test=0;
		if(k!=0)
		{
			for (int i=0;i<12;++i)
			{
				if (all[k-1][i]==all[k][i])
				{
					++test;
				}
			}
			if (test==12)
			{
				for (int i=0;i<12;++i)
				{
					all[k][i]=0;					
				}
			}
			else
			{
				++k;	
			}
		}	
		else
		{
			++k;
		}		
		//++k;
		return;
	}

	for (int i=d;i<n;++i)
	{
		if (num+number[i]<=t)
		{
			num+=number[i];
			answer[j++]=number[i];
			backtracking(i+1,num);
			num-=number[i];
			answer[--j]=0;
		}
	}

}

int main()
{
	int tmp=0;
	//int test=0;
	while (scanf("%d %d",&t,&n)!=EOF && n!=0)
	{
		tmp=0;
		while (tmp<n)
		{
			scanf("%d",&number[tmp]);
			++tmp;
		}
		/*Big->small*/
		sort(number,number+n);
		reverse(number,number+n);				
		printf("Sums of %d:\n",t);
		
		backtracking(0,0);	
		/*To delete repeat answer*/
		for (int i=1;i<k;++i)
		{
			for (int l=i-1;l>=0;--l)
			{
				test=0;
				for (int m=0;m<12;++m)
				{
					if (all[i][m]==all[l][m])
					{
						++test;
					}
				}
				if (test==12)
				{
					for (int m=0;m<12;++m)
					{
						all[i][m]=0;
					}
					break;				
				}
			}
		}
		/*To print the answer*/	
		if (all[0][0]==0)
		{
			printf("NONE\n");
		}
		else 
		{
			//printf("%d\n", all[0][0]);
			//printf("K:%d\n",k);
			for (int i=0;i<k;++i)
			{
				if (all[i][0]!=0)
				{
					for (int l=0;l<12;++l)
					{
						if(all[i][l]!=0 && l==0)
						{
							printf("%d",all[i][l]);
						}
						else if(all[i][l]!=0 && l>0)
						{
							printf("+%d",all[i][l]);
						}
						else
						{
							break;
						}
					}				
					printf("\n");
				}
			}
		}		
		/*To initialize*/
		for (int i=0;i<10000;++i)
		{
			for (int l=0;l<12;++l)
			{
				all[i][l]=0;
			}
		}
		for (int i=0;i<12;++i)
		{
			number[i]=0;
			answer[i]=0;
		}
		n=0;
		t=0;
		j=0;
		k=0;
	}
	

	return 0;
}