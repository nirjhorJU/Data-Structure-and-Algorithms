#include<bits/stdc++.h>
using namespace std;
const int N=8;
string s[N];
int backtrack(int x,int c,int d1,int d2)
{
    if(x==N)
    {
        return 1;
    }
    int ans=0;
    for(int i=0; i<N; i++)
    {
        if(s[x][i]=='*' || (c&(1<<i))!=0 || (d1&(1<<(x+i)))!=0 || (d2&(1<<(x+N-i)))!=0)
        {
            continue;
        }
        ans+=backtrack(x+1,c|(1<<i),d1|(1<<(x+i)),d2|(1<<(x+N-i)));
    }
    return ans;
}
int main()
{
    for(int i=0; i<N; i++)
    {
        cin>>s[i];
    }
    cout<<backtrack(0,0,0,0);
    return 0;
}


