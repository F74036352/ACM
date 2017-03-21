#include <cstdio>
#include <cstdlib>
#include <iostream>
//#include <algotithm>

using namespace std;
int number[100]={0};
int answer[6]={0};
void backtracking(int d,int n)
{
	if (d==6)
	{
		for (int i=0;i<6;++i)
		{
			if(i!=5)
			{
				printf("%d ",answer[i]);
			}
			else
			{
				printf("%d",answer[5]);
			}
		}
		printf("\n");
		return;
	}
	for (int i=0;i<n;++i)
	{
		if (answer[d-1]<number[i])
		{
			answer[d]=number[i];
			backtracking(d+1,n);
		}
	}
}
int main()
{
	int n=0;
	int once=0;	
	while (scanf("%d",&n)!=EOF && n!=0)
	{
		if (once!=0)
		{
			printf("\n");
		}
		once=1;
		for (int i=0;i<n;++i)
		{
			scanf("%d",&number[i]);
		}
		//sort(number,number+n);
		backtracking(0,n);
		
		for (int i=0;i<6;++i)
		{
			answer[i]=0;
		}
		for (int i=0;i<100;++i)
		{
			number[i]=0;
		}

	}




	return 0;
}