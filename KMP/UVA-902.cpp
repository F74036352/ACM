#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

using namespace std;
/*
用map及string
分析輸入的子字串
存到map中並記錄次數
次數最多的為答案

P.S C++ string 
printf and scanf有點麻煩
用cin cout比較簡單
但會比較慢
*/
int main()
{
    int n=0;
    int len=0;
    int max=0;    
    //string s1;
    while (scanf("%d",&n)!=EOF)    
    {
        string s1;
        string s2;
        //string answer;    
        map<string, int> trie;
        cin >> s1;
        //scanf("%s",s1);
        //cin.get();
        //getline(cin,s1);
        //printf("%s\n",s1);
        //len=s1.length();
        for (int i=0;i<=s1.size()-n;++i)
        {
            s2=s1.substr(i,n);
            if (trie[s2]==0)
            {
                trie[s2]=1;
            }
            else
            {
                trie[s2]+=1;
            }
        }        
        for (auto &m:trie)
        {
            if (m.second > max)
            {
                max=m.second;
                s1=m.first;
            }
        }
        //printf("%s\n",s1);        
        cout<<s1<<endl;
        max=0;
    }
    return 0;
}
