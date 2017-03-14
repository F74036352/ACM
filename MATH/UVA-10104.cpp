#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int exgcd(int a,int b,int &X,int &Y)
{
	if (b==0)
	{
		X=1;
		Y=0;
		return a;
	}
	else
	{
		int gcd=exgcd(b, a%b, X, Y);
		int tmp=X;
		X=Y;
		Y=tmp-(a/b)*Y;
		return gcd;
	}
}
int main()
{
	int A=0;
	int B=0;
	int X=0;
	int Y=0;
	int answer=0;
	while (scanf("%d %d",&A,&B)==2)
	{

		answer=exgcd(A,B,X,Y);		
		printf("%d %d %d\n",X,Y,answer);
		
		answer=0;
		A=0;
		B=0;
		X=0;
		Y=0;
	}
	return 0;
}