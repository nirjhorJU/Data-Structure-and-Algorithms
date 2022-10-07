#include<bits/stdc++.h>
using namespace std;
#define  ll  long long
const ll M = 1e9+7;
ll c[8005];
vector< ll >v;
int main()
{
    ll i,j,n,m,k,s=0;
    cin>>n>>k;
    for(i=0; i<n; i++)
    {
        cin>>m;
        if(c[m]==0)
        {
            v.push_back(m);
            s++;
        }
        c[m]++;
    }
    k = min(s,k);
    ll dp[k+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    ll sz = v.size();
    for(i=0; i<sz; i++)
    {
        for(j=k ; j>0; j--)
        {
            ll p = ((dp[j-1]%M)*(c[v[i]]%M))%M;
            dp[j] = (dp[j]%M + p%M)%M;
        }
    }
    ll ans = 0;
    for(i=0; i<=k; i++)
    {
        ans = (ans + dp[i])%M;
    }
    cout<<ans<<"\n";
    return 0;
}

