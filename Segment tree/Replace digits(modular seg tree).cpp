                // ACL Beginner Contest - E (https://atcoder.jp/contests/abl)
#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
const ll N=2e5+2,M=998244353;
ll tr[N*4],lazy[N*4],pw[N],v[10][N];
void push_down(ll node,ll s,ll e,ll l,ll r)
{
    if(lazy[node]>0)
    {
        ll x=lazy[node];
        tr[node]=v[x][e-s+1];
        if(s<e) lazy[l]=x,lazy[r]=x;
        lazy[node]=0;
    }
}
void up(ll node,ll s,ll e,ll i,ll j,ll d)
{
    ll l=node*2;
    ll r=l+1;
    ll m=(s+e)/2;
    push_down(node,s,e,l,r);
    if(s>j || e<i)
    {
        return;
    }
    else if(s>=i && e<=j)
    {
        lazy[node]=d;
        push_down(node,s,e,l,r);
        return;
    }
    up(l,s,m,i,j,d);
    up(r,m+1,e,i,j,d);
    tr[node]=(tr[l]*pw[e-m]+tr[r])%M;
}
int main()
{
    ft
    ll i,j,n,l,r,q,d;
    cin>>n>>q;
    pw[0]=1;
    for(i=1;i<=n;i++)
    {
        pw[i]=(pw[i-1]*10)%M;
    }
    for(i=1;i<10;i++)
    {
        for(j=1;j<=n;j++)
        {
            v[i][j]=(v[i][j-1]*10+i)%M;
        }
    }
    up(1,1,n,1,n,1);
    while(q--)
    {
        cin>>l>>r>>d;
        up(1,1,n,l,r,d);
        cout<<tr[1]<<"\n";
    }
    return 0;
}
