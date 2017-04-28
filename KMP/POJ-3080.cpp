#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

char s1[100][100]={'\0'};
char s2[100]={'\0'};
char last[100]={'\0'};
char tmp[100]={'\0'};

int next[100]={0};
int len1=0;
int len2=0;
int n=0;
int r=0;

void KMP()
{
    next[0]=-1;
    int i=0;
    int j=-1;
    int m=0;
    while (i<=len2)
    {
        if (j==-1 || s2[i]==s2[j])
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
    r=100;
    for (int k=1;k<n;++k)
    {
        i=0;
        j=0;
        m=0;
        while (i<60 && j<len2)
        {
            if (j==-1 || s2[j]==s1[k][i])
            {
                ++i;
                ++j;
            }
            else
            {
                j=next[j];
            }
            if (j>m)
            {
                m=j;
            }
        }
        if (r>m)
        {
            r=m;
        }
    }
    
}
void find()
{
    int answer=0;
    for (int i=0;i<60;++i)
    {
        strcpy(s2,s1[0]+i);
        //printf("%s",s1[0]+i);
        len2=60-i;
        KMP();
        if (r>answer)
        {
            answer=r;
            strncpy(last,s1[0]+i,answer);
            last[answer]='\0';
        }
        else if (r==answer)
        {
            strncpy(tmp,s1[0]+i,answer);
            tmp[answer]='\0';
            if (strcmp(tmp,last)<0)
            {
                strcpy(last,tmp);
            }
        }
    }
    if (answer>=3)
    {
        printf("%s\n",last);
    }
    else
    {
        printf("no significant commonalities\n");
    }
}
int main()
{
    int t=0;
    //int n=0;
    scanf("%d",&t);

    while (t>0)
    {
        --t;
        scanf("%d",&n);
        for (int i=0;i<n;++i)
        {
            scanf("%s",s1[i]);
        }
        find();
        for (int i=0;i<100;++i)
        {
            last[i]='\0';
            tmp[i]='\0';
            s2[i]='\0';
            for (int j=0;j<100;++j)
            {
                s1[i][j]='\0';
            }
        }
    }



    return 0;
}
