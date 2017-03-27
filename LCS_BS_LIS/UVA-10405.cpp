#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
/*LCS*/
using namespace std;

char s1[1100]={'\0'};
char s2[1100]={'\0'};
int LCS[1100][1100]={0};
int pre[1100][1100]={0};
int len1=0;
int len2=0;

void Find_LCS()
{
    int i=0;
    int j=0;
    int answer=0;
    for (i=1;i<=len1;++i)
    {
        LCS[i][0]=0;
    }
    for (j=1;j<=len2;++j)
    {
        LCS[0][j]=0;
    }
    for (i=1;i<=len1;++i)
    {
        for (j=1;j<=len2;++j)
        {
            if (s1[i-1]==s2[j-1])
            {
                LCS[i][j]=LCS[i-1][j-1]+1;
                pre[i][j]=0;
            }
            else 
            {
                if (LCS[i-1][j]>=LCS[i][j-1])
                {
                    LCS[i][j]=LCS[i-1][j];
                    pre[i][j]=1;
                }
                else
                {
                    LCS[i][j]=LCS[i][j-1];
                    pre[i][j]=2;
                }
            }
        
        }
    }
    /*for (i=1;i<=len1;++i)
    {
        for (j=1;j<=len2;++j)
        {
            if (pre[i][j]==0)
            {
                ++answer;               
            }
        }

    }
    */
    //printf("%d\n",answer);
    printf("%d\n",LCS[len1][len2]); 
}

int main()
{
    while (gets(s1))
    {
        gets(s2);    
        len1=strlen(s1);
        len2=strlen(s2);
        //puts(s1);
        //puts(s2);
        //printf("%d\n",len1);
        //printf("%d\n",len2);
        
        Find_LCS();

        /*To initialize*/
        for (int i=0;i<1100;++i)
        {
            s1[i]='\0';
            s2[i]='\0';
            for (int j=0;j<1100;++j)
            {
                LCS[i][j]=0;
                pre[i][j]=0;
            }
        }
    }
    return 0;
}

