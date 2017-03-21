#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

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
		
	int n=0;
	int tmp=0;
	int board[8][8]={0};
	int big[92]={0};
	backtracking(0);

	while (scanf("%d",&n)!=EOF && n!=0)
	{
		tmp=0;		
		while (tmp<n)
		{
			++tmp;
			for (int i=0;i<8;++i)
			{
				for (int j=0;j<8;++j)
				{
					scanf("%d",&board[i][j]);
				}
			}
			for (int i=0;i<92;++i)
			{
				for (int j=0;j<8;++j)
				{
					big[i]+=board[sol[i][j]][j];
					//printf("2 ");
				}
				//printf("1 ");
			}		
			sort(big,big+92);
			// for (int i=0;i<92;++i)
			// {
			// 	printf("%d\n",big[i]);
			// }
			printf("%5d\n",big[91]);	
			for (int i=0;i<92;++i)
			{
				big[i]=0;
			}
		}
			
		
	}


	return 0;
}