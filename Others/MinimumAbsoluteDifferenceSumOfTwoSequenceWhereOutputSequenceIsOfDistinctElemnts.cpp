
//                      https://codeforces.com/contest/1437/problem/C

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
ll t,n,a[202],d[202][404];
ll go(ll i,ll j)
{
    if(i==n) return 0;
    else if(j>2*n) return INT_MAX;
    else if(d[i][j]!=-1) return d[i][j];
    return d[i][j]=min(go(i,j+1),abs(a[i]-j)+go(i+1,j+1));
}
int main()
{
    ft
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        memset(d,-1,sizeof(d));
        cout<<go(0,1)<<"\n";
    }
    return 0;
}


