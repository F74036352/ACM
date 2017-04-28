#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int n=0;
int nk=0;
int Ti[10]={0};//only 5 elevator
int w[100][100]={0};
int f[100]={0};
int dis[100]={0};
int use[100]={0};
//int tmp[100]={0};
int index=0;
int stop=0;
int count=0;
char s1[1001]={'\0'};


int main()
{    
    while (scanf("%d %d",&n,&nk)!=EOF)
    {
    	for (int i=0;i<100;++i)
        {           
            for (int j=0;j<100;++j)
            {
                w[i][j]=1000000;
            }
        }  
        for (int i=0;i<n;++i)
        {
            scanf("%d",&Ti[i]);
        }
            
        while (getchar()!='\n');

        for (int i=0;i<n;++i)
        {
            gets(s1);
            stop=0;        
            index=0;
            int tmp[100]={0};
            for (int j=0;s1[j];)
            {
                while (s1[j]==' ')
                {
                    ++j;
                }
                sscanf(s1+j,"%d", &stop);
                while (s1[j]!=' ' && s1[j])
                {
                    ++j;
                }
                tmp[index++]=stop;
             }             
            for (int j=0;j<index;++j)
            {
                for (int k=j+1;k<index;++k)
                {
                    w[tmp[j]][tmp[k]]=min(abs(tmp[j]-tmp[k])*Ti[i],w[tmp[j]][tmp[k]]);
                    w[tmp[k]][tmp[j]]=w[tmp[j]][tmp[k]];
                }
            }            
        }
        for (int i=0;i<100;++i)
        {
            dis[i]=1000000;
            use[i]=0;
        }
        dis[0]=0;
        for (int i=0;i<100;++i)
        {
        	int ma_n=1000000;
        	int t_n=0;
        	for (int j=0;j<100;++j)
        	{
        		if (use[j]==0 && dis[j]<ma_n)
        		{
        			ma_n=dis[j];
        			t_n=j;
        		}
        	}
        	if (ma_n==1000000 || t_n==nk)
        	{
        		break;
        	}
       		use[t_n]=1;
       		for (int j=0;j<100;++j)
       		{
       			if (w[t_n][j] && dis[j]>dis[t_n]+w[t_n][j]+60)
       			{
       				dis[j]=dis[t_n]+w[t_n][j]+60;
       			}
       		}
       	}
       		if (dis[nk]==1000000)
       		{
       			printf("IMPOSSIBLE\n");
       		}
       		else if (dis[nk]==0)
       		{
       			printf("0\n");
       		}
       		else
       		{
       			printf("%d\n",dis[nk]-60);
       		}        
        
    
    }





    return 0;
}
