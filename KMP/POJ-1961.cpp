#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
char s1[1000100]={'\0'};
int pi[1000100]={0};
int n=0;

void fail()
{
	int cur=-1;
	pi[0]=-1;
	for (int i=1;i<n;++i)
	{
		while (~cur && s1[i]!=s1[cur+1])
		{
			cur=pi[cur];
		}
		if (s1[i]==s1[cur+1])
		{
			++cur;
		}
		pi[i]=cur;
		if (~cur && (i+1)%(i-cur)==0)
		{
			printf("%d %d\n",(i+1),(i+1)/(i-cur));
		}
	}
	printf("\n");
}
int main()
{
    
    int test=0;
    while (scanf("%d",&n)!=EOF && n!=0)
    {
    	scanf("%s",s1);
    	printf("Test case #%d\n",++test);
    	fail();
    	for (int i=0;i<1000100;++i)
    	{
    		s1[i]='\0';
    		pi[i]=0;
    	}
    }

    return 0;
}
