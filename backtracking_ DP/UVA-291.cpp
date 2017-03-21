#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int house[6][6]={0};
int answer[9]={0};
int num=0;
void backtracking(int d)
{
	answer[num]=d;
	++num;
	if (num==9)
	{
		for (int i=0;i<9;++i)
		{
			printf("%d",answer[i]);
		}
		printf("\n");				
		--num;
		return;
	}
	for (int i=1;i<6;++i)
	{
		if (house[d][i]==1)
		{
			house[d][i]=0;
			house[i][d]=0;			
			backtracking(i);			
			house[d][i]=1;
			house[i][d]=1;
		}
	}
	--num;//****
}
int main()
{
	for (int i=1;i<6;++i)
	{
		for (int j=1;j<6;++j)
		{
			if(i!=j)
			{
				house[i][j]=1;
			}
		}
	}	
	house[1][4]=0;
	house[2][4]=0;
	house[4][1]=0;
	house[4][2]=0;
	// for (int i=0;i<6;++i)
	// {
	// 	for (int j=0;j<6;++j)
	// 	{
	// 		printf("%2d ",house[i][j]);
	// 	}	
	// 	printf("\n");
	// }
	backtracking(1);



	return 0;
}