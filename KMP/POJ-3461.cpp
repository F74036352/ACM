#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int pi[10100]={0};
char s1[10010]={'\0'};
char s2[1000010]={'\0'};
void fail()
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
}
int match()
{
	int answer=0;
	int cur=-1;
	int len1=strlen(s1);
	int len2=strlen(s2);
	for (int i=0;i<len2;++i)
	{
		while (~cur && s2[i]!=s1[cur+1])
		{
			cur=pi[cur];			
		}
		if (s1[cur+1]==s2[i])
		{
			++cur;			
		}
		if (cur+1==len1)
		{
			++answer;
			cur=pi[cur];
		}
	}
	return answer;
}

int main()
{
	int n=0;
	scanf("%d",&n);
	for (int i=0;i<n;++i)
	{
		scanf("%s",s1);
		scanf("%s",s2);
		fail();
		printf("%d\n",match());
		for (int j=0;j<10010;++j)
		{
			s1[j]='\0';
		}
		for (int j=0;j<1000010;++j)
		{
			s2[j]='\0';
		}
	}




	return 0;
}