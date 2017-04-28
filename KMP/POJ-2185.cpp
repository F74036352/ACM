#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;
int r=0;
int c=0;
char s1[10010][80]={'\0'};
char s2[80][10010]={'\0'};
int row[100010]={0};
int col[100010]={0};

void KMPR()
{
	row[0]=-1;
	int pos=-1;
	int i=0;
	while (i<r)
	{
		if (pos==-1 || strcmp(s1[i],s1[pos])==0)
		{
			++i;
			++pos;
			row[i]=pos;
		}
		else
		{
			pos=row[pos];
		}
	}
}
void KMPC()
{
	col[0]=-1;
	int pos=-1;
	int i=0;
	while (i<c)
	{
		if (pos==-1 || strcmp(s2[i],s2[pos])==0)
		{
			++i;
			++pos;
			col[i]=pos;
		}
		else
		{
			pos=col[pos];
		}
	}

}
int main()
{
	int answer=0;
	while (scanf("%d %d",&r,&c)!=EOF)
	{
		//printf("12\n");
		for (int i=0;i<r;++i)
		{		
			/*for (int j=0;j<c;++j)
			{
				scanf("%c",&s1[i][j]);
			}*/
			scanf("%s",s1[i]);
		}
		//printf("11\n");
		KMPR();
		for (int i=0;i<r;++i)//reverse
		{
			for (int j=0;j<c;++j)
			{
				s2[j][i]=s1[i][j];
			}
		}
		KMPC();
		answer=(r-row[r])*(c-col[c]);
		printf("%d\n", answer);
	}

	


    return 0;
}
