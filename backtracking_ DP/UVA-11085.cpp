#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

bool row[8]={false};
bool dia1[15]={false};/* / */
bool dia2[15]={false};/* \ */
int answer[8]={0};
int sol[92][8]={0};
int num=0;

void backtracking(int d)//d->col
{
	if (d==8)
	{
		for (int i=0;i<8;++i)
		{
			sol[num][i]=answer[i];
		}
		++num;
		return;
	}
	int di1=0;
	int di2=0;
	for (int i=0;i<8;++i)//row
	{
		di1=(d+i)%15;/* / no0->d+i=0 no1->d+i=1......*/
		di2=(d-i+8)%15;/* \ no0->d-i=7 no1->d-i=6......*/
		if (row[i]!=true && dia1[di1]!=true && dia2[di2]!=true)
		{
			row[i]=true;
			dia1[di1]=true;
			dia2[di2]=true;
			answer[d]=i;//第d個col的第i個row有queen
			backtracking(d+1);
			row[i]=false;
			dia1[di1]=false;
			dia2[di2]=false;
		}

	}

}
int main()
{
	backtracking(0);
	int position[8]={0};
	int test=0;
	int min=8;
	int count=0;
	int tmp=1;	
	for (int i=0;i<num;++i)
	{		
		for (int j=0;j<8;++j)
		{
			sol[i][j]+=1;
		}
				
	}
	while (scanf("%d",&position[0])!=EOF)
	{
		++count;
		tmp=1;
		while (tmp<8)
		{
			scanf("%d",&position[tmp]);
			++tmp;
		}
		min=8;
		for (int i=0;i<92;++i)
		{
			test=0;
			for (int j=0;j<8;++j)
			{
				if (sol[i][j]!=position[j])
				{
					++test;
				}
			}
			if (test<min)
			{
				min=test;
			}
		}
		printf("Case %d: %d\n",count,min);
	}

	return 0;
}