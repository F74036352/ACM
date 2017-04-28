#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

#define BIG 999999999
//g++ -std=c++11 -o UVA-10986 UVA-10986.cpp
/*SPFA*/
struct weight{
    int p;
    int w;

};
int n=0;
int m=0;
int s=0;
int t=0;
int Case=1;
int N=0;
//int in=0;//in negative cycle->false
vector<weight> toN[20010];

void SPFA()
{
	queue<int> Q;
	int dis[20010]={0};
	int inQ[20010]={0};
	int count[20010]={0};
	int in=0;

	    for (int i=0;i<n;++i)
        {
            dis[i]=BIG;                
        }
        dis[s]=0;
        inQ[s]=1;
        Q.push(s);

        while (!Q.empty() && in==0)
        {
            int now=0;
            now=Q.front();
            inQ[now]=0;
            Q.pop();
            for (auto &nx : toN[now])// c++ 11
            {
                if (dis[now]+nx.w<dis[nx.p])
                {
                	dis[nx.p]=dis[now]+nx.w;
                	if (!inQ[nx.p])
                	{
                		Q.push(nx.p);
                		inQ[nx.p]=1;
                		++count[nx.p];
                		if (count[nx.p]>=n)
                		{
                			in=1;
                		}
                	}
                }
            }                    
        }    
        printf("Case #%d: ",Case);
		++Case;
		if (dis[t]==BIG)
		{
			printf("unreachable\n");
		}
		else
		{
			printf("%d\n",dis[t]);
		}    
}
int main()
{
    
    scanf("%d",&N);
    while (N>0)
    {
        --N;
        scanf("%d %d %d %d",&n,&m,&s,&t);        
        int x=0;
        int y=0;
        int l=0;
        for (int i=0;i<m;++i)
        {
            scanf("%d %d %d", &x, &y, &l);
            toN[x].push_back({y,l});
            toN[y].push_back({x,l});
        }

      	SPFA();
        for (int i=0;i<n;++i)/*QQ*/
        {
            toN[i].clear();
        }
      	
    }



    return 0;
}
