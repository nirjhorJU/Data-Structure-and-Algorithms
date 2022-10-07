//      LOJ-1380

#include<bits/stdc++.h>
using namespace std;
#define  ll  long long
#define  pb  push_back
const int N=1e3+5;
struct edge
{
    ll x,y,w;
};
vector<edge>e;
ll vis[N],id[N],in[N],pre[N],INF=LLONG_MAX;
ll ZhuLiu(ll root,ll n,ll m)
{
    ll res=0;
    while(true)
    {
        for(ll i=0; i<n; i++) in[i]=INF,id[i]=vis[i]=-1;
        for(ll i=0; i<m; i++)
        {
            ll x=e[i].x;
            ll y=e[i].y;
            if(e[i].w<in[y] && x!=y)
            {
                pre[y]=x;
                in[y]=e[i].w;
            }
        }
        in[root]=0;
        for(ll i=0; i<n; i++)
        {
            if(in[i]==INF) return -1;
        }
        ll cnt=0;
        for(ll i=0; i<n; i++)
        {
            res+=in[i];
            ll y=i;
            while(vis[y]!=i && id[y]==-1 && y!=root)
            {
                vis[y]=i;
                y=pre[y];
            }
            if(y!=root && id[y]==-1)
            {
                for(ll x=pre[y]; x!=y; x=pre[x]) id[x]=cnt;
                id[y]=cnt++;
            }
        }
        if(cnt==0) break;
        for(ll i=0; i<n; i++)
        {
            if(id[i]==-1)
            {
                id[i]=cnt++;
            }
        }
        for(ll i=0; i<m; i++)
        {
            ll x=e[i].x;
            ll y=e[i].y;
            e[i].x=id[x];
            e[i].y=id[y];
            if(id[x]!=id[y]) e[i].w-=in[y];
        }
        n=cnt;
        root=id[root];
    }
    return res;
}
void Solution(ll cas)
{
    ll i,n,m,k,l,r,w;
    scanf("%lld%lld%lld",&n,&m,&k);
    e.clear();
    for(i=0; i<m; i++)
    {
        cin>>l>>r>>w;
        if(l==r) w=INF;
        e.pb({l,r,w});
    }
    l=ZhuLiu(k,n,m);
    printf("Case %lld: ",cas);
    if(l==-1)
    {
        printf("impossible\n");
        return;
    }
    printf("%lld\n",l);
}
int main()
{
    ll t,cas;
    scanf("%lld",&t);
    for(cas=1;cas<=t;cas++) Solution(cas);
    return 0;
}
