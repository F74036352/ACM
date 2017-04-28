#include <cstdio>
#include <cstdlib>
#include <iostream>

#define INF 99999999

using namespace std;

int dis[1001]={0};
int w[1001][1001]={0};
int t=0;
int n=0;
struct Edge{
    int x;
    int y;
    int len;
}E[2001];

// bool relax(int i,int j)
// {
//     int test=0;
//     if (dis[i]+w[i][j]<dis[j])
//     {
//         dis[j]=dis[i]+w[i][j];
//         test=1;
//     }
//     if (dis[j]+w[i][j]<dis[i])
//     {
//         dis[i]=dis[j]+w[i][j];
//         test=1;
//     }
//     return test;
// }
bool relax(int i)
{
    int test=0;
    if (dis[E[i].x]+E[i].len<dis[E[i].y])
    {
        dis[E[i].y]=dis[E[i].x]+E[i].len;
        test=1;
    }
    if (dis[E[i].y]+E[i].len<dis[E[i].x])
    {
        dis[E[i].x]=dis[E[i].y]+E[i].len;
        test=1;
    }
    return test;
}
void bellmanford()
{
    int test=0;
    dis[n]=0;
    for (int i=1;i<n;++i)
    {
        dis[i]=INF;
    }
    for (int k=0;k<n-1;++k)//做n-1次
    {
    	test=0;
        // for (int i=0;i<=n;++i)
        // {
        //     for (int j=0;j<=n;++j)
        //     {
        //         if(w[i][j]!=0)//路存在
        //         {
        //             if (relax(i,j)==1)
        //             {
        //                 test=1;
        //             }
        //         }
        //     }
        // }
        for (int i=0;i<t;++i)
        {
        	if (relax(i)==1)
        	{
        		test=1;
        	}

        }
        if (test==0)
        {
            return;
        }
    }
}
int main()
{
    int t1=0;
    int count=0;
    int x=0;
    int y=0;
    int num=0;
    scanf("%d %d",&t,&n);
    t1=t;
    while (t1>0)
    {
        --t1;
        // scanf("%d %d %d",&x,&y,&num);
        // w[x][y]=num;
        // w[y][x]=num;
        scanf("%d %d %d",&E[count].x,&E[count].y,&E[count].len);
       	++count;  
    }
    bellmanford();
    printf("%d\n",dis[1]);


    return 0;
}
