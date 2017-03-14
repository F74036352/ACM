#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	int m=0;
	int tmp=1;
	int num1=0;
	int num2=0;	
	float answer=0;
	while (scanf("%d",&m)!=EOF)
	{
		while (tmp<=m)
		{
			
			scanf("%d %d",&num1,&num2);
			if (num1%2==1 && num2%2==1)
			{
				answer=num1*num2-1+1.414;
			}
			else
			{
				answer=num1*num2;
			}
			printf("Scenario #%d:\n%.2f\n\n",tmp,answer);
			++tmp;
		}
		tmp=1;
		answer=0;
		m=0;
		num1=0;
		num2=0;
	}





	return 0;
}