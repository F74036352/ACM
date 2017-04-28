#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;
int answer=0;
int fail(char *B)
{
    int len=strlen(B);
    int cur_pos=-1;
    int pi[90]={0};
    pi[0]=-1;
    for (int i=1;i<len;++i)
    {
        while (~cur_pos && B[i]!=B[cur_pos+1])
        {
            cur_pos=pi[cur_pos];
        }
        if (B[i]==B[cur_pos+1])
        {
            ++cur_pos;
        }
        pi[i]=cur_pos;    
    }
    return cur_pos;
}
void match(char *A,char *B,int *pi)
{
    int lenA=strlen(A);
    int lenB=strlen(B);    
    for (int i=1,cur_pos=-1;i<lenA;++i)
    {
        while (~cur_pos && A[i]!=B[cur_pos+1])
        {
            cur_pos=pi[cur_pos];
        }
        if (A[i]==B[cur_pos+1])
        {
            ++cur_pos;
        }
        if (cur_pos+1==lenB)
        {
            /*Match*/    
            cur_pos=pi[cur_pos];
        }    
    }   
}
int main()
{
    int n=0;
    char tmp[1]={'\0'};
    char s1[81]={'\0'};
    //char s2[81]={'\0'};
    int lenS=0;
    int count=0;
    scanf("%d",&n);    
        for (int i=0;i<n;++i)
        {
            scanf("%s",s1);
            //scanf("%c",tmp);
            //gets(s1);
            lenS=strlen(s1);
            count=fail(s1);
            //printf("%d\n",count);
            if (lenS%(lenS-count-1)!=0 && i!=(n-1))
            {
                printf("%d\n\n",lenS);
            }
            else if (lenS%(lenS-count-1)==0 && i!=(n-1))
            {
                printf("%d\n\n",(lenS-count-1));
            }
            if (lenS%(lenS-count-1)!=0 && i==(n-1))
            {
                printf("%d\n",lenS);
            }
            else if (lenS%(lenS-count-1)==0 && i==(n-1))
            {
                printf("%d\n",(lenS-count-1));
            }
            /*
            for (int j=0;j<=count;++j)
            {
                s2[j]=s1[j];
            }
            */
            //answer=0;
            //match(s1,s2);
            //printf("cc\n");
            //printf("%d\n",match(s1,s2));
            for (int k=0;k<81;++k)
            {
                s1[k]='\0';
              //  s2[k]='\0';
            }
            
        }
        



    return 0;
}
