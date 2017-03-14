#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	char mes1[100]={'\0'};
	char mes2[100]={'\0'};
	int num1[26]={0};
	int num2[26]={0};
	int number=0;
	int test=0;
	while (gets(mes1) && gets(mes2))
	{
		for (int i=0;i<100;++i)
		{
			if(mes1[i]>='A' && mes1[i]<='Z')
			{
				num1[mes1[i]-'A']++;
			}		
		}
		for (int i=0;i<100;++i)
		{
			if(mes2[i]>='A' && mes2[i]<='Z')
			{
				num2[mes2[i]-'A']++;
			}		
		}		
		sort(num1,num1+26);
		sort(num2,num2+26);
		for (int i=0;i<26;++i)
		{
			if (num1[i]==num2[i])
			{
				++test;
			}

		}	
		if (test==26)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
		for (int i=0;i<26;++i)
		{
			num1[i]=0;
			num2[i]=0;
		}
		for (int i=0;i<100;++i)
		{
			mes1[i]='\0';
			mes2[i]='\0';
		}
		test=0;

		
	}

	return 0;
}