#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <iostream>
#define INF 9999999

using namespace std;
int n=0;
int m=0;
int s=0;
double v=0;
double rrate[101][101]={0};
double crate[101][101]={0};
double dis[101]={0};
//int change[101]={0};
vector<int> change[101];//貨幣會換成甚麼貨幣

void SPFA()
{
	queue<int> Q;
	int inqueue[101]={0};
	int now=0;
	int next=0;
	Q.push(s);
	inqueue[s]=1;
	dis[s]=v;

	while (Q.empty()==0)
	{
		now=Q.front();
		Q.pop();
		inqueue[now]=0;
		for (int i=0;i<change[now].size();++i)
		{
			next=change[now][i];
			if (dis[next]<(dis[now]-crate[now][next])*rrate[now][next])
			{
				dis[next]=(dis[now]-crate[now][next])*rrate[now][next];
				if (inqueue[next]==0)
				{
					Q.push(next);
					inqueue[next]=1;
				}				
			}
		}
	}

}

int main()
{
	int a=0;
	int b=0;
	double rab=0;
	double rba=0;
	double cab=0;
	double cba=0;

	scanf("%d %d %d %lf",&n,&m,&s,&v);
	for (int i=0;i<m;++i)
	{
		scanf("%d %d %lf %lf %lf %lf",&a,&b,&rab,&cab,&rba,&cba);
		rrate[a][b]=rab;
		rrate[b][a]=rba;
		crate[a][b]=cab;
		crate[b][a]=cba;
		change[a].push_back(b);
		change[b].push_back(a);
	}
	SPFA();

	if (dis[s]>v)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	//printf("%lf\n",dis[s] );
	return 0;
}