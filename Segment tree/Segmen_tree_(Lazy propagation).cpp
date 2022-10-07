#include<bits/stdc++.h>
using namespace std;
#define  ll  long long
const ll N=2e5+2;
struct data
{
    ll ss,pp;
} tr[3*N];
ll a[N];
void init(ll node,ll s,ll e)
{
    if(s==e)
    {
        tr[node].ss=a[s];
        tr[node].pp=0;
        return;
    }
    ll l=node*2;
    ll r=l+1;
    ll m=(s+e)/2;
    init(l,s,m);
    init(r,m+1,e);
    tr[node].ss=tr[l].ss+tr[r].ss;
    tr[node].pp=0;
}
void up(ll node,ll s,ll e,ll i,ll j,ll v)
{
    if(i>e || j<s)
    {
        return;
    }
    else if(s>=i && e<=j)
    {
        tr[node].ss+=v;
        tr[node].pp+=v;
        return;
    }
    ll l=node*2;
    ll r=l+1;
    if(tr[node].pp!=0)
    {
        ll x=tr[node].pp;
        tr[l].ss+=x,tr[l].pp+=x;
        tr[r].ss+=x,tr[r].pp+=x;
        tr[node].pp=0;
    }
    ll m=(s+e)/2;
    up(l,s,m,i,j,v);
    up(r,m+1,e,i,j,v);
    tr[node].ss=min(tr[l].ss,tr[r].ss);
}
ll Q(ll node,ll s,ll e,ll i)
{
    if(i>e || i<s)
    {
        return 0;
    }
    else if(s>=i && e<=i)
    {
        return tr[node].ss;
    }
    ll l=node*2;
    ll r=l+1;
    if(tr[node].pp>0)
    {
        ll x=tr[node].pp;
        tr[l].ss+=x, tr[l].pp+=x;
        tr[r].ss+=x, tr[r].pp+=x;
        tr[node].pp=0;
    }
    ll m=(s+e)/2;
    return (Q(l,s,m,i)+Q(r,m+1,e,i));
}
int main()
{
    ll i,j,n,m,l,r,q,u;
    scanf("%lld %lld",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    init(1,1,n);
    while(q--)
    {
        scanf("%lld",&m);
        if(m==2)
        {
            scanf("%lld",&l);
            printf("%lld\n",Q(1,1,n,l,0));
        }
        else
        {
            scanf("%lld %lld %lld",&l,&r,&u);
            up(1,1,n,l,r,u);
        }
    }
    return 0;
}

