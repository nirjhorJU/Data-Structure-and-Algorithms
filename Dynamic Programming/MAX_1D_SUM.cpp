#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define   ll  long long
int ind[100005];
ll dp[100005],a[100005],s;
int main()
{
    ft
    int z,t,i,x,n;
    cin>>t;
    for(z=1; z<=t; z++)
    {
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>a[i];
            dp[i]=a[i];
            ind[i]=i;
        }
        s=a[1],x=1;
        for(i=2; i<=n; i++)
        {
            if(dp[i-1]+a[i]>=a[i])
            {
                dp[i]=dp[i-1]+a[i];
                ind[i]=ind[i-1];
            }
            if(s<dp[i])
            {
                s=dp[i];
                x=i;
            }
        }
        cout<<"Case "<<z<<":\n"<<s<<" "<<ind[x]<<" "<<x<<"\n";
        if(z!=t)
        {
            cout<<"\n";
        }
    }
    return 0;
}


