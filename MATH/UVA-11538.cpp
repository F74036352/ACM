#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	long long int n=0;
	long long int m=0;
	long long int row=0;//big
	long long int col=0;//small
	long long int count=0;		
	while (scanf("%lld %lld",&n,&m)!=EOF && (n!=0 && m!=0))
	{
		if (n<=m)
		{
			row=m;
			col=n;			
		}
		else 
		{
			row=n;
			col=m;
		}		
		count=count+(col*(col-1)/2*2)*row;
		count=count+(row*(row-1)/2*2)*col;	
		count=count+(col*(col-1)/2*2)*(row-col+1)*2;//大對角線		
			 for (long long int i=2;i<=col-1;++i)
			 {
			 	count=count+(i*(i-1)/2)*2*2*2;
			 }
		//count=count+(col*(col-1)*(col-2)/6*2)*2*2;
		printf("%lld\n",count);
		n=0;
		m=0;
		row=0;
		col=0;
		count=0;
	}	
	return 0;
}