#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	char s1[1100]={'\0'};
	char s2[1100]={'\0'};
	int LCS[1100][1100]={0};
	int pre[1100][1100]={0};
	int count=1;
	int num1=0;
	int num2=0;
	int test1=0;//1->same word 0-> next word
	int test2=0;//1->same word 0-> next word

	while (gets(s1))
	{
		//printf("a\n");
		gets(s2);
		//printf("b\n");
		if (s1[0]=='\0' || s2[0]=='\0')
		{
			printf("%2d. Blank!\n",count++);
			continue;
		}
		string str1[1100];
		string str2[1100];
		for (int i=0;i<strlen(s1);++i)
		{
			if ((s1[i]>='0' && s1[i]<='9') || (s1[i]>='a' && s1[i]<='z') || (s1[i]>='A' && s1[i]<='Z'))
			{
				if(test1==0)
				{
					str1[++num1]+=s1[i];
					test1=1;
				}
				else 
				{
					str1[num1]+=s1[i];
				}
			}
			else
			{
				test1=0;
			}
			
		}
		for (int i=0;i<strlen(s2);++i)
		{
			if ((s2[i]>='0' && s2[i]<='9') || (s2[i]>='a' && s2[i]<='z') || (s2[i]>='A' && s2[i]<='Z'))
			{
				if(test2==0)
				{
					str2[++num2]+=s2[i];
					test2=1;
				}
				else 
				{
					str2[num2]+=s2[i];
				}
			}
			else
			{
				test2=0;
			}
			
		}
		/*LCS*/
		for (int i=1;i<=num1;++i)
		{
			for (int j=1;j<=num2;++j)
			{
				if (str1[i]==str2[j])
				{
					LCS[i][j]=LCS[i-1][j-1]+1;
					pre[i][j]=0;
				}
				else 
				{
					if (LCS[i-1][j]>=LCS[i][j-1])
					{
						LCS[i][j]=LCS[i-1][j];
						pre[i][j]=1;
					}
					else if (LCS[i][j-1]>LCS[i-1][j])
					{
						LCS[i][j]=LCS[i][j-1];
						pre[i][j]=2;
					}

				}
				

			}
		}
		printf("%2d. Length of longest match: %d\n",count,LCS[num1][num2]);
		count++;
		for (int i=0;i<1100;++i)
		{
			s1[i]='\0';
			s2[i]='\0';			
		}
		for (int i=0;i<1100;++i)
		{
			for (int j=0;j<1100;++j)
			{
				LCS[i][j]=0;
				pre[i][j]=0;
			}
		}
		num1=0;
		num2=0;
		test1=0;
		test2=0;

	}   




    return 0;
}
