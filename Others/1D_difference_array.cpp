
            //                  CF   -   296C

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
const ll N=1e5+3;
ll a[N],d[N];
struct op
{
    ll f,s,v;
}b[N];
ll on[N],to[N];
int main()
{
    ft
    ll t,i,j,n,m,k,l,r,p;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        d[i]=a[i]-a[i-1];
    }
    for(i=1;i<=m;i++)
    {
        cin>>l>>r>>p;
        b[i]={l,r,p};
    }
    for(i=0;i<k;i++)
    {
        cin>>l>>r;
        on[l]++;
        to[r]++;
    }
    for(i=1;i<=m;i++)
    {
        on[i]+=on[i-1];
        to[i]+=to[i-1];
    }
    for(i=1;i<=m;i++)
    {
        b[i].v*=(on[i]-to[i-1]);
    }
    for(i=1;i<=m;i++)
    {
        l=b[i].f;
        r=b[i].s;
        p=b[i].v;
        d[l]+=p;
        d[r+1]-=p;
    }
    for(i=1;i<=n;i++)
    {
        d[i]+=d[i-1];
        cout<<d[i]<<" ";
    }
    return 0;
}
