#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	char number[1000]={'\0'};
	char symbol[1]={'\0'};
	int answer[1000]={0};	
	long long int m=0;	
	long long int remain=0;
	int count=0;
	int count1=0;
	int test=0;
	while (scanf("%s %s %lld",number,symbol,&m)!=EOF)
	{
		for (int i=0;number[i];++i)//大數除法求商數及餘數
		{
			remain=remain*10+(number[i]-'0');
			answer[count1++]=remain / m;
			remain=remain % m;
		}
		for (count=0;count<count1;++count)//計算從哪位開始不為0
		{
			if (test==0 && answer[count]!=0)
			{
				test=1;
				break;
			}
		}
		if (symbol[0]=='/')
		{
			if (count==count1)//全為0
			{
				printf("0\n");
			}
			else 
			{
				for (int i=count;i<count1;++i)
				{
					printf("%d",answer[i]);
				}
				printf("\n");
			}
		}		
		else if (symbol[0]=='%')
		{
			printf("%lld\n",remain);	
		}

		for (int i=0;i<1000;++i)
		{
			number[i]='0';
			answer[i]=0;
		}
		symbol[0]='\0';
	  	remain=0;
		count=0;
		count1=0;
		test=0;


	}
	return 0;
}