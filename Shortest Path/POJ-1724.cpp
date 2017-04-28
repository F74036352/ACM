#include <cstdio>
#include <cstdlib>
#include <queue>
#include <iostream>
#define INF 9999999

using namespace std;

int k=0;
int r=0;
int n=0;
int dis[101][10010]={0};//點i花j元的最短距離

struct spot{
	vector<int> y;
	vector<int> len;
	vector<int> toll;
}x[101];//所有的點

void SPFA()
{
	queue<int> Q;
	Q.push(1);	
	int inqueue[101]={0};
	inqueue[1]=1;
	int now=0;
	int next=0;
	int l=0;
	int t=0;
	/*initialize*/
	for (int i=1;i<=n;++i)
	{
		for (int j=0;j<=k;++j)
		{
			dis[i][j]=INF;
		}
	}
	for (int i=0;i<=k;++i)
	{
		dis[1][i]=0;
	}
	/*SPFA*/
	while (Q.empty()==0)
	{
		now=Q.front();
		Q.pop();
		inqueue[now]=0;
		
		for (int i=0;i<x[now].y.size();++i)
		{
			next=x[now].y[i];
			l=x[now].len[i];
			t=x[now].toll[i];
			for (int j=0;j+t<=k;++j)//條件是否付得起
			{
				if (dis[now][j]+l<dis[next][j+t])//shotest path
				{
					dis[next][j+t]=dis[now][j]+l;				
					if (inqueue[next]==0)
					{
						Q.push(next);
						inqueue[next]=1;
					}
				}
			}
		}
	}
	
}
int main()
{
	int s=0;
	int d=0;
	int l=0;
	int t=0;
	scanf("%d",&k);
	scanf("%d",&n);
	scanf("%d",&r);
	for (int i=0;i<r;++i)
	{
		scanf("%d %d %d %d",&s,&d,&l,&t);
		x[s].y.push_back(d);
		x[s].len.push_back(l);
		x[s].toll.push_back(t);

	}
	SPFA();
	int answer=INF;
	for (int i=0;i<=k;++i)
	{
		if (dis[n][i]<answer)
		{
			answer=dis[n][i];
		}
	}
	if (answer==INF)
	{
		printf("-1\n");		
	}
	else
	{
		printf("%d\n",answer);
	}
	
	return 0;
}