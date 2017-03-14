#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	char tmp[251]={'\0'};
	char number1[251]={'\0'};
	char number2[251]={'\0'};
	int answer[501]={0};
	int num1=0;
	int num2=0;	
	while(scanf("%s",tmp)!=EOF)
	{
		num1=0;
		num2=0;
		for(int i=0;i<250;++i)
		{
			if(tmp[i]!='\0')
			{
				++num1;
			}
		}
		int k=0;
		for(int i=num1-1;i>=0;--i)
		{
			number1[k]=tmp[i];
			++k;
		}
		for(int i=0;i<250;++i)
		{
			tmp[i]='\0';
		}

		scanf("%s",tmp);	
		for(int i=0;i<250;++i)
		{
			if(tmp[i]!='\0')
			{
				++num2;
			}
		}
		k=0;
		for(int i=num2-1;i>=0;--i)
		{
			number2[k]=tmp[i];
			++k;
		}
		for(int i=num1;i<250;++i)
		{
			number1[i]='0';
		}	
		for(int i=num2;i<250;++i)
		{
			number2[i]='0';
		}

		//test
		// for(int i=0;i<num1;++i)
		// {
		// 	printf("%c",number1[i]);
		// }
		// printf("\n");
		// for(int i=0;i<num2;++i)
		// {
		// 	printf("%c",number2[i]);
		// }
		// printf("\n");
		//upon test
		int a=0,b=0;
		for(int i=0;i<num1;++i)//number1
		{
			for(int j=0;j<num2;++j)//number2
			{
				a=number1[i]-'0';
				b=number2[j]-'0';
				answer[j+i]=answer[j+i]+a*b;
			}
		}
		for(int i=0;i<501;++i)
		{
			if(answer[i]>=10)
			{
				answer[i+1]=answer[i+1]+answer[i]/10;
				answer[i]=answer[i]%10;
			}
		}
		int all=num1+num2-1;
		int test=0;
		for(int i=0;i<501;++i)
		{
			if(answer[i]==0)
			{
				++test;
			}
		}	
		if(answer[all]==0)
		{
			--all;
		}
		if(test==501)
		{
			all=0;
		}
		for(int i=all;i>=0;--i)
		{
			printf("%d",answer[i]);
		}
		printf("\n");
		//init
		for(int i=0;i<251;++i)
		{
			tmp[i]='\0';
			number1[i]='\0';
			number2[i]='\0';
		}
		for(int i=0;i<501;++i)
		{
			answer[i]=0;
		}

		/*upon to init*/
	}






}