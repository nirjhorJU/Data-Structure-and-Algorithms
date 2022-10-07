//          LOJ-1348


#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);
#define  ll  long long
#define  pii pair<ll,ll>
#define  pb  push_back
const int N=3e4+3;
ll val[N],head[N],ID[N],d[N],pos,chain[N],vis[N],par[N],tr[4*N];
vector<ll>g[N],a;
ll dfs(ll f,ll p)
{
    ll ans=1,mx=0,ind=-1;
    for(ll x: g[f])
    {
        if(x!=p)
        {
            ans+=dfs(x,f);
            if(d[x]>mx) mx=d[x],ind=x;
        }
    }
    ID[f]=ind;
    return d[f]=ans;
}
void go(ll f,ll p)
{
    if(head[pos]==-1) head[pos]=f;
    chain[f]=pos;
    par[f]=p;
    a.pb(f);
    if(ID[f]==-1)
    {
        pos++;
        return;
    }
    go(ID[f],f);
    for(ll x: g[f])
    {
        if(x!=p && x!=ID[f]) go(x,f);
    }
}
void init(ll node,ll s,ll e)
{
    if(s==e)
    {
        tr[node]=val[a[s]];
        return;
    }
    ll l=node*2;
    ll r=l+1;
    ll m=(s+e)/2;
    init(l,s,m);
    init(r,m+1,e);
    tr[node]=tr[l]+tr[r];
}
void up(ll node,ll s,ll e,ll i,ll upd)
{
    if(s>i || e<i) return;
    else if(s==e && s==i)
    {
        tr[node]=upd;
        return;
    }
    ll l=node*2;
    ll r=l+1;
    ll m=(s+e)/2;
    up(l,s,m,i,upd);
    up(r,m+1,e,i,upd);
    tr[node]=tr[l]+tr[r];
}
ll Q(ll node,ll s,ll e,ll i,ll j)
{
    if(s>j || e<i) return 0ll;
    else if(s>=i && e<=j) return tr[node];
    ll m=(s+e)/2;
    return (Q(node*2,s,m,i,j)+Q(1+node*2,m+1,e,i,j));
}
void Solution()
{
    ll q,i,j,n,m,l,r,o;
    cin>>n;
    for(i=0;i<n;i++) cin>>val[i],g[i].clear(),head[i+1]=-1;
    a.clear();
    a.pb(-1);
    for(i=1;i<n;i++)
    {
        cin>>l>>r;
        g[l].pb(r);
        g[r].pb(l);
    }
    dfs(0,-1);
    pos=1;
    go(0,-1);
    for(i=1;i<=n;i++) vis[a[i]]=i;
    init(1,1,n);
    cin>>q;
    while(q--)
    {
        cin>>o>>l>>r;
        if(o==0)
        {
            ll u,v,ans=0;
            while(1)
            {
                u=chain[l],v=chain[r];
                if(u==v) break;
                if(u>v)
                {
                    ans+=Q(1,1,n,vis[head[u]],vis[l]);
                    l=par[head[u]];
                }
                else
                {
                    ans+=Q(1,1,n,vis[head[v]],vis[r]);
                    r=par[head[v]];
                }
            }
            l=vis[l],r=vis[r];
            if(l>r) swap(l,r);
            ans+=Q(1,1,n,l,r);
            cout<<ans<<"\n";
        }
        else up(1,1,n,vis[l],r);
    }
}
int32_t main()
{
    ft
    ll t;
    cin>>t;
    for(ll cs=1;cs<=t;cs++)
    {
        cout<<"Case "<<cs<<":\n";
        Solution();
    }
    return 0;
}
