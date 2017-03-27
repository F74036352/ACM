#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	int m=0;
	int n=0;
	int dp[10200]={0};
	int price[100]={0};
	int value[100]={0};
	int location=0;
	int tmp=0;
	int refund=0;
	int answer=0;

	while (scanf("%d %d",&m,&n)!=EOF)
	{
		for (int i=0;i<n;++i)
		{
			scanf("%d %d",&price[i],&value[i]);
		}
		/*credit card >2000 -> +200*/	
		
		refund=m;

		if (refund>1800)
		{
			refund=refund+200;
		}
		/*DP*/
		for (int i=0;i<n;++i)
		{
			for (int j=refund;j>=price[i];--j)
			{
				if (j-price[i]==0 || dp[j-price[i]]>0)
				{
					if (dp[j-price[i]]+value[i]>dp[j])
					{
						dp[j]=dp[j-price[i]]+value[i];
					}					
					//printf("11\n");
				}				
			}
		} 		
		// tmp=dp[m];	
		// printf("m:%d\n",m );	
		// printf("dp[m]:%d\n",dp[m] );
		// printf("dp[2051]:%d\n",dp[2051] );		

		/*最麻煩的信用卡refund*/
		if (m >= 1801 && m <= 2000)
        {  
        	tmp=0;
	        for (int i=0;i<=m;++i)
			{
				if (tmp<=dp[i])
				{
					tmp=dp[i];
				}
			}          
            for (int i=2001;i<=refund;++i)
            {
                if (tmp<=dp[i])
                {
                	tmp=dp[i];
                }
            }
            answer=tmp;
            printf("%d\n",answer);
        }
        else
        {
        	tmp=0;
        	for (int i=0;i<10200;++i)
			{
				if (tmp<=dp[i])
				{
					tmp=dp[i];
				}
			} 
            answer=tmp;
            printf("%d\n",answer);
        }

        

		/*To initialize*/
		for (int i=0;i<10200;++i)
		{
			dp[i]=0;
		}
		for (int i=0;i<100;++i)
		{
			price[i]=0;
			value[i]=0;
		}		
		m=0;
		n=0;
		location=0;
		tmp=0;
		answer=0;
		tmp=0;

	}


	return 0;
}