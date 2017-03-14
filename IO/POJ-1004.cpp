#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	float money[12]={0};
	int m=0;
	float total=0;	
		for (m=11;m>=0;--m)
		{
			scanf("%f",&money[m]);
		}
		for (int i=0;i<12;++i)
		{
			total+=money[i];
		}
		total/=12;
		printf("$%.2f\n",total);	

	return 0;
}