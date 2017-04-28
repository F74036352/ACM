#include <cstdio>
#include <cstdlib>
#include <iostream>

#define INF 99999999

using namespace std;

int dis[1001]={0};
int n=0;    
int m=0;    
int w=0;

struct Edge{
    int x;
    int y;
    int len;
}E[3001];

bool relax(int i,int pos)
{
    int test=0;
    if (dis[E[i].x]+E[i].len<dis[E[i].y])
    {
        dis[E[i].y]=dis[E[i].x]+E[i].len;
        test=1;
    }
    if (pos==1 && dis[E[i].y]+E[i].len<dis[E[i].x])
    {
        dis[E[i].x]=dis[E[i].y]+E[i].len;
        test=1;
    }
    return test;
}
int bellmanford()
{
    int test=0;
    dis[n]=0;
    for (int i=1;i<n;++i)
    {
        dis[i]=INF;
    }
    for (int k=0;k<n;++k)//做n次?
    {
    	test=0;        
        for (int i=0;i<m+w;++i)
        {
        	if (i<m)//positive
        	{
        		if (relax(i,1)==1)
        		{
        			test=1;
        		}
        	}
        	else//negative
        	{
        		if (relax(i,0)==1)
        		{
        			test=1;
        		}
        	}        
        }
        if (test==0)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int F=0;
    scanf("%d",&F);
    while (F>0)
    {
    	--F;
    	scanf("%d %d %d",&n,&m,&w);
    	for (int i=0;i<m;++i)
    	{
    		scanf("%d %d %d",&E[i].x,&E[i].y,&E[i].len);
    	}
    	for (int i=m;i<m+w;++i)
    	{
    		scanf("%d %d %d",&E[i].x,&E[i].y,&E[i].len);
    		E[i].len=0-E[i].len;
    		//E[i].len*=-1;
    	}
    	if(bellmanford()==1)
    	{
    		printf("NO\n");
    	}
    	else
    	{
    		printf("YES\n");
    	}
    }




    return 0;
}
