#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int box[31][11]={0};
int n=0;
int k=0;
int maxl=0;
void answer(int from[],int l,int len)
{
	if (l<0)
	{
		return;
	}
	answer(from,from[l],maxl-1);
	printf("%d",(l+1));
	if (len==maxl)
	{
		printf("\n");
	}
	else
	{
		printf(" ");
	}
}
int compare(int i,int j)
{
	if (box[i][0]<box[j][0])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{    
    int LIS[31]={0};
    int from[31]={0};
    int s[31]={0};
    int l=0;
    int test=0;
    while (scanf("%d %d",&k,&n)!=EOF)
    {
        for (int i=0;i<k;++i)
        {
        	s[i]=i;
        	LIS[i]=1;
        	from[i]=-1;        	       
        	for (int j=0;j<n;++j)
        	{
        		scanf("%d",&box[i][j]);
        	}
        	/*將每個box的各邊先排序*/
        	sort(box[i],box[i]+n);
        }

        /*將所有box依照最小邊[0]排列*/
        sort(s,s+k,compare);//依照copare()來sort        
        
        for (int i=1;i<k;++i)
        {        
        	for (int j=0;j<i;++j)
        	{
        		test=1;
        		for(int m=0;m<n;++m)
        		{
        			if (box[s[i]][m]<=box[s[j]][m])
        			{
        				test=0;
        				break;
        			}
        		}
        		/*LIS*/
        		if (test==1 && LIS[i]<LIS[j]+1)
        		{        			
        			LIS[i]=LIS[j]+1;
        			from[s[i]]=s[j];
        		}        
        		if (LIS[i]>maxl)
        		{
        			maxl=LIS[i];
        			l=s[i];
        		}
        	}
        }

        printf("%d\n",maxl); 
        answer(from,l,maxl);  
        /*To initialize*/     
        for (int i=0;i<k;++i)
        {
        	s[i]=0;
        	LIS[i]=0;
        	from[i]=0; 
        	for (int j=0;j<n;++j)
        	{
        		box[i][j]=0;

        	}
        }
        maxl=1;
        l=0;
        test=1;
    }
    return 0;    
}
