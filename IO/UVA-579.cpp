#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	float hour=0;
	float min=0;
	float rd=0;	
	int test=0;
	while (scanf("%f:%f",&hour,&min)!=EOF)
	{
		test=0;
		//printf("%f : %f\n",hour,min);
		if(hour==0 && min==0)
		{
			break;			
		}
		if(hour==0)
		{
			hour=12;
		}
		rd=30*hour+min*30/60-6*min;
		
		

		if(rd<0)
		{
			rd=-rd;
		}
		if(rd==360)
		{
			rd=0;
		}
		if(rd>180)
		{
			rd=360-rd;
		}
			printf("%.3f\n",rd);
		

	}








}