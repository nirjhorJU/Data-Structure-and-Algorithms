
//https://codeforces.com/contest/220/problem/B

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pii pair<ll,ll>
#define  pb  push_back
#define  B   begin()
#define  E   end()
const int N=1e5+5;
ll c[N],L[N],R[N],ans[N],a[N];
pii b[N];
vector<ll>V[N],tr[4*N],ind[4*N];
void Merge(ll node,ll l,ll r)
{
    tr[node].clear();
    ind[node].clear();
    ll i,j,n,m;
    n=tr[l].size();
    m=tr[r].size();
    for(i=0,j=0;i<n && j<m;)
    {
        if(tr[l][i]<tr[r][j]) tr[node].pb(tr[l][i]),ind[node].pb(ind[l][i++]);
        else tr[node].pb(tr[r][j]),ind[node].pb(ind[r][j++]);
    }
    for(;i<n;i++) tr[node].pb(tr[l][i]),ind[node].pb(ind[l][i]);
    for(;j<m;j++) tr[node].pb(tr[r][j]),ind[node].pb(ind[r][j]);
}
void init(ll node,ll s,ll e)
{
    if(s==e)
    {
        tr[node].clear();
        ind[node].clear();
        tr[node].pb(R[s]);
        ind[node].pb(b[s].second);
        return;
    }
    ll l=node*2;
    ll r=l+1;
    ll m=(s+e)/2;
    init(l,s,m);
    init(r,m+1,e);
    Merge(node,l,r);
}
void Q(ll node,ll s,ll e,ll i,ll j,ll lo,ll hi)
{
    if(s>j || e<i) return ;
    else if(s>=i && e<=j)
    {
        ll x=lower_bound(tr[node].B,tr[node].E,lo)-tr[node].B;
        ll y=upper_bound(tr[node].B,tr[node].E,hi)-tr[node].B;
        for( ;x<y;x++) ans[ind[node][x]]++;
        return;
    }
    ll l=node*2;
    ll r=l+1;
    ll m=(s+e)/2;
    Q(l,s,m,i,j,lo,hi);
    Q(r,m+1,e,i,j,lo,hi);
}
int main()
{
    ft
    ll t,i,j,n,m,l,r,x,y;
    cin>>n>>t;
    for(i=1;i<=n;i++) V[i].pb(0);
    for(i=1;i<=n;i++)
    {
        cin>>l;
        if(l<=n)
        {
            c[l]++;
            V[l].pb(i);
        }
    }
    for(i=1;i<=t;i++) cin>>L[i]>>R[i],b[i]={L[i],i},a[i]=R[i];
    sort(b+1,b+t+1);
    for(i=1;i<=t;i++)
    {
        L[i]=b[i].first;
        R[i]=a[b[i].second];
    }
    init(1,1,t);
    for(i=1;i<=n;i++)
    {
        if(c[i]<i) continue;
        l=V[i].size();
        V[i].pb(n+1);
        for(j=1,r=i;r<l;j++,r++)
        {
            x=lower_bound(L+1,L+t+1,V[i][j-1]+1)-L;
            y=upper_bound(L+1,L+t+1,V[i][j])-L;
            Q(1,1,t,x,y-1,V[i][r],V[i][r+1]-1);
        }
    }
    for(i=1;i<=t;i++) cout<<ans[i]<<"\n";
    return 0;
}


