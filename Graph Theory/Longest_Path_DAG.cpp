#include<bits/stdc++.h>
using namespace std;
#define  pb  push_back
queue<int>q;
int main()
{
    int i,j,n,m,x,f,mx=0;                 //AtCoder - 4528
    cin>>n>>m;
    int ind[n+2],dp[n+2];
    vector<int>v[n+2];
    memset(ind,0,sizeof(ind));              // Longest path using topsorts
    memset(dp,0,sizeof(dp));
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        v[x].pb(y);
        ind[y]++;
    }
    for(i=1;i<=n;i++)
    {
        if(ind[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        f=q.front();
        q.pop();
        for(auto y: v[f])
        {
            dp[y]=max(dp[y],1+dp[f]);
            mx=max(mx,dp[y]);
            ind[y]--;
            if(ind[y]==0)
            {
                q.push(y);
            }
        }
    }
    cout<<mx<<"\n";
    return 0;
}


