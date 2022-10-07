#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=1e6+2;
int dp[N];
int main()
{
    ft
    int a[105],i,j,n,x;
    cin>>n>>x;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=1; i<=x; i++)
    {
        dp[i]=1e9;
    }
    for(i=0; i<n; i++)
    {
        for(j=a[i]; j<=x; j++)
        {
            dp[j]=min(dp[j],(1+dp[j-a[i]]));
        }
    }
    if(dp[x]==1e9)
    {
        dp[x]=-1;
    }
    cout<<dp[x]<<"\n";
    return 0;
}
