// https://codeforces.com/contest/1702/problem/G2

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);
#define  ll  long long
#define  pb  push_back
#define  B   begin()
#define  E   end()
const int N=2e5+3;
vector<ll>g[N],a;
ll lg[2*N],d[N],first[N],last[N],b[2*N],tr[2*N][21],ind[2*N][21];
void dfs(ll f,ll p)
{
    d[f]=d[p]+1;
    a.pb(f);
    for(ll x: g[f])
    {
        if(x!=p)
        {
            dfs(x,f);
            a.pb(f);
        }
    }
}
void go(ll n,ll L)
{
    for(ll i=1;i<=n;i++) tr[i][0]=b[i],ind[i][0]=a[i];
    for(ll j=1;j<=L;j++)
    {
        for(ll i=1;i+(1<<j)-1<=n;i++)
        {
            if(tr[i][j-1]<tr[i+(1<<(j-1))][j-1]) tr[i][j]=tr[i][j-1],ind[i][j]=ind[i][j-1];
            else  tr[i][j]=tr[i+(1<<(j-1))][j-1],ind[i][j]=ind[i+(1<<(j-1))][j-1];
        }
    }
}
ll Q(ll i,ll j)
{
    if(i>j) swap(i,j);
    ll k=lg[j-i+1];
    if(tr[i][k]<tr[j-(1<<k)+1][k]) return ind[i][k];
    return ind[j-(1<<k)+1][k];
}
bool cmp(ll x,ll y)
{
    return (d[x]>d[y]);
}
void Solution()
{
    ll q,i,j,n,m,l,r,sz;
    cin>>n;
    for(i=2;i<2*n;i++) lg[i]=lg[i/2]+1;
    for(i=1;i<n;i++)
    {
        cin>>l>>r;
        g[l].pb(r);
        g[r].pb(l);
    }

    // Eulerian path

    a.pb(0);
    dfs(1,0);
    m=a.size();
    m--;
    for(i=1;i<=m;i++) last[a[i]]=i,b[i]=d[a[i]];
    for(i=m;i>0;i--) first[a[i]]=i;

    //Sparse table
    go(m,lg[m]);
    cin>>q;
    while(q--)
    {
        cin>>sz;
        vector<ll>v;
        for(i=0;i<sz;i++)
        {
            cin>>l;
            v.pb(l);
        }
        sort(v.B,v.E,cmp);
        vector<ll>mark(sz,0);
        for(i=0;i<sz;i++)
        {
            if(Q(last[v[0]],last[v[i]])==v[i]) mark[i]=1;
        }
        ll k=0;
        while(k<sz && mark[k]==1) k++;
        if(k==sz)
        {
            cout<<"YES\n";
            continue;
        }
        for(i=k;i<sz;i++)
        {
            if(Q(last[v[k]],last[v[i]])==v[i]) mark[i]=1;
        }
        ll ans=1;
        for(i=0;i<sz;i++) ans&=mark[i];
        if(ans==1 && d[Q(last[v[0]],last[v[k]])]<=d[v[sz-1]]) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
int32_t main()
{
    ft
    Solution();
    return 0;
}
