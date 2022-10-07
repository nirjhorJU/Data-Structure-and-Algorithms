

//                                      AtCoder - 4526

#include<bits/stdc++.h>
using namespace std;
#define   ll  long long
ll wt[105],val[105],dp[105][100005];
int main()
{
    ll i,j,n,w,v=0,mx=0;
    cin>>n>>w;
    for(i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
        v+=val[i];
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=v;j++)
        {
            dp[i][j]=1e14;
        }
    }
    dp[0][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=v;j++)
        {
            if(j-val[i-1]>=0)
            {
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-val[i-1]]+wt[i-1]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(i=0;i<=v;i++)
    {
        if(dp[n][i]<=w)
        {
            mx=i;
        }
    }
    cout<<mx<<"\n";
    return 0;
}
