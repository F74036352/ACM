#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

char s1[1000100]={'\0'};
int pi[1000100]={0};
int  fail()
{
	int len=strlen(s1);
	int cur=-1;
	pi[0]=-1;
	for (int i=1;i<len;++i)
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
	}
	return cur;
}
int main()
{
	int answer=0;
	int len1=0;
	while (scanf("%s",s1)!=EOF && s1[0]!='.')
	{
		len1=strlen(s1);
		answer=fail();
		if (len1%(len1-answer-1)!=0)
		{
			printf("1\n");
		}
		else
		{
			printf("%d\n",len1/(len1-answer-1) );
		}
		for (int i=0;i<1000100;++i)
		{
			s1[i]='\0';
			pi[i]=0;
		}
	}



	return 0;
}