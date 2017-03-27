#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int m=0;
	long int num=0;
	long int number[1000]={0};
	int tmp=0;
	int low=0;	
	for (int i=0;i<32;++i)
	{
		for (int j=0;j<32;++j)
		{
			num=pow(2,i)*pow(3,j);
			if (num>pow(2,31))
			{
				break;
			}
			else
			{
				number[tmp++]=num;
			}
		}
	}
	sort(number,number+tmp);

	while (scanf("%d",&m)!=EOF && m!=0)
	{
		low=lower_bound(number,number+tmp,m)-number;//STL的binary search 好用
		printf("%ld\n",number[low]);
	}





}