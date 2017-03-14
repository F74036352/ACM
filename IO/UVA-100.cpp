#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int big(int k)
{
    int count=1;
    while(k!=1)
    {
        ++count;
        if(k%2==1)
        {
            k=3*k+1;
        }
        else
        {
            k=k/2;
        }
    }
    return count;
}
int main()
{
    int i,j;
    int is,js;
    int max=0;
    int num=0;
    while(scanf("%d %d",&i,&j)==2)
    {
    if(i<j)
    {
        for(is=i;is<=j;++is)
        {
            if(max<(num=big(is)))
            {
                max=num;
            }
        }
        printf("%d %d %d\n",i,j,max);
    }
    else
    {
        for(js=j;js<=i;++js)
        {
            if(max<(num=big(js)))
            {
                max=num;
            }
        }
        printf("%d %d %d\n",i,j,max);
    }
        max=0;
        num=0;
    }
    return 0;
}

