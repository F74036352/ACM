/*
課程講解範例之例題
範例code:http://codepad.org/xxEQk0f9
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;
char s1[110][110]={'\0'};
char s2[110][110]={'\0'};
int LCS[110][110]={0};
int pre[110][110]={0};
int count=0;
int count1=0;
int count2=0;

void Find_LCS()
{
	int i=0;
	int j=0;
	LCS[0][0]=0;
	for (i=1;i<count1;++i)
	{
		LCS[i][0]=0;
	}
	for (j=1;j<count2;++j)
	{
		LCS[0][j]=0;
	}
	for (i=1;i<count1;++i)
	{
		for (j=1;j<count2;++j)
		{
			if (strcmp(s1[i],s2[j])==0)
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
				else
				{
					LCS[i][j]=LCS[i][j-1];
					pre[i][j]=2;
				}
			}
		}
	}

}
int main()
{

	char answer[110]={'\0'};
	int tmp1=0;
	int tmp2=0;
	while (1)
	{
				
		for (count1=1;;++count1)
		{
			if (scanf("%s",s1[count1])==EOF)
			{
				return 0;
			}
			else if (strcmp(s1[count1],"#")==0)
			{
				break;
			}

		}
		for (count2=1;;++count2)
		{
			if (scanf("%s",s2[count2])==EOF)
			{
				return 0;
			}
			else if (strcmp(s2[count2],"#")==0)
			{
				break;
			}

		}
		/*LCS*/
		Find_LCS();
		tmp1=count1-1;
		tmp2=count2-1;		
		while (tmp1!=0 && tmp2!=0)
		{
			if (pre[tmp1][tmp2]==0)
			{
				answer[count++]=tmp1;
				--tmp1;
				--tmp2;
			}
			else if (pre[tmp1][tmp2]==1)
			{
				--tmp1;
			}
			else if (pre[tmp1][tmp2]==2)
			{
				--tmp2;
			}
		}
		/*To print*/		
		//printf("%d\n",count );
		if (count!=0)
		{
			printf("%s",s1[answer[count-1]]);
			for (int i=count-2;i>=0;--i)
			{
				printf(" %s",s1[answer[i]]);
			}
			printf("\n");
		}
		/*To initialize*/
		for (int i=0;i<110;++i)
		{
			answer[i]='\0';
			
		}
		for (int i=0;i<110;++i)
		{
			for (int j=0;j<110;++j)
			{
				LCS[i][j]=0;
				pre[i][j]=0;
				s1[i][j]='\0';
				s2[i][j]='\0';

			}
		}
		count=0;
		count1=0;
		count2=0;
		tmp1=0;
		tmp2=0;		

	}

	//return 0;
}