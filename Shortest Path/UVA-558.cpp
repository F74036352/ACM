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

bool relax(int i)
{
    int test=0;
    if (dis[E[i].x]+E[i].len<dis[E[i].y])
    {
        dis[E[i].y]=dis[E[i].x]+E[i].len;
        test=1;
    }
    /*if (dis[E[i].y]+E[i].len<dis[E[i].x])
    {
        dis[E[i].x]=dis[E[i].y]+E[i].len;
        test=1;
    }
    */
    return test;
}
int bellmanford()
{
    int test=0;
    dis[n]=0;
    dis[0]=0;
    for (int i=1;i<n;++i)
    {
        dis[i]=INF;
    }
    for (int k=0;k<n-1;++k)//做n跟n-1都行
    {    	      
        for (int i=0;i<m;++i)
        {        
        	relax(i);
        }
        
    }
    for (int i=0;i<m;++i)
    {
    	if (dis[E[i].y]>dis[E[i].x]+E[i].len)
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
    //printf("11\n");
    while (F>0)
    {
    	--F;
    	scanf("%d %d",&n,&m);
    	//printf("12\n");
    	for (int i=0;i<m;++i)
    	{
    		scanf("%d %d %d",&E[i].x,&E[i].y,&E[i].len);
    		//printf("13\n");
    	}    	
    	if(bellmanford()==1)
    	{
    		printf("possible\n");
    	}
    	else
    	{
    		printf("not possible\n");
    	}
    }




    return 0;
}