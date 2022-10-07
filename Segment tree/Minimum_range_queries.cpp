#include<bits/stdc++.h>
using namespace std;
#define  ll  long long
const int N=2e5+2;
ll a[N],tr[3*N];
void init(int node,int s,int e)
{
    if(s==e)
    {
        tr[node]=a[s];
        return;
    }
    int l=node*2;
    int r=node*2+1;
    int m=(s+e)/2;
    init(l,s,m);
    init(r,m+1,e);
    tr[node]=min(tr[l],tr[r]);
}
ll Q(int node,int s,int e,int i,int j)
{
    if(i>e || j<s)
    {
        return INT_MAX;
    }
    else if(i<=s && e<=j)
    {
        return tr[node];
    }
    int l=node*2;
    int r=node*2+1;
    int m=(s+e)/2;
    ll p=Q(l,s,m,i,j);
    ll q=Q(r,m+1,e,i,j);
    return min(p,q);
}
void up(int node,int s,int e,int i,int v)
{
    if(i>e || i<s)
    {
        return;
    }
    else if(s==e && i==s)
    {
        tr[node]=v;
        return;
    }
    int l=node*2;
    int r=node*2+1;
    int m=(s+e)/2;
    up(l,s,m,i,v);
    up(r,m+1,e,i,v);
    tr[node]=min(tr[l],tr[r]);
}
int main()
{
    int i,j,n,m,q,l,r;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    init(1,1,n);
    while(q--)
    {
        scanf("%d",&m);
        if(m==1)
        {
            scanf("%d %d",&l,&r);
            up(1,1,n,l,r);
        }
        else
        {
            scanf("%d %d",&l,&r);
            printf("%lld\n",Q(1,1,n,l,r));
        }
    }
    return 0;
}
