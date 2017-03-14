#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
	char tmp[11]={'\0'};
	char number1[11]={'\0'};
	char number2[11]={'\0'};
	int answer[11]={0};
	int num1=0;
	int num2=0;	
	int t1=0;
	int t2=0;
	int count=0;//計算有幾次進位
	int a=0,b=0;
	int j=0;
	while(scanf("%s",tmp)!=EOF)
	{
		num1=0;
		num2=0;
		t1=0;
		t2=0;
		count=0;
		a=0;
		b=0;		
		for(int i=0;i<11;++i)
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
		for(int i=0;i<11;++i)
		{
			tmp[i]='\0';
		}

		scanf("%s",tmp);	
		for(int i=0;i<11;++i)
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
		for(int i=num1;i<11;++i)
		{
			number1[i]='0';
		}	
		for(int i=num2;i<11;++i)
		{
			number2[i]='0';
		}
		for (int i=0;i<11;++i)
		{
			if (number1[i]=='0')
			{
				++t1;
			}

			if (number2[i]=='0')
			{
				++t2;
			}			
		}
		if(t1==11 && t2==11)//當兩個輸入都是0時 number1和number2裡面會各有11個'0'
		{
			return 0;
		}
		
		
		if (num1>=num2)//加法 位數較多的會有些沒加到->直接給answer
		{	
			for (j=0;j<num2;++j)//number2
			{
				a=number1[j]-'0';
				b=number2[j]-'0';
				answer[j]=a+b;
			}
			for(int i=j;i<num1;++i)
			{
				a=number1[i]-'0';
				answer[i]=a;
			}
		}
		else 
		{
			for (j=0;j<num1;++j)//number2
			{
				a=number1[j]-'0';
				b=number2[j]-'0';
				answer[j]=a+b;
			}
			for(int i=j;i<num2;++i)
			{
				a=number2[i]-'0';
				answer[i]=a;
			}
		}

		for(int i=0;i<11;++i)
		{
			if(answer[i]>=10)
			{
				++count;
				answer[i+1]=answer[i+1]+answer[i]/10;
				answer[i]=answer[i]%10;
			}
		}

		if(count==0)
		{
			printf("No carry operation.\n");
		}
		else if(count==1)
		{
			printf("1 carry operation.\n");
		}
		else
		{
			printf("%d carry operations.\n",count);
		}
		//init
		for(int i=0;i<11;++i)
		{
			tmp[i]='\0';
			number1[i]='\0';
			number2[i]='\0';
			answer[i]=0;
		}
		

		/*upon to init*/
	}






}