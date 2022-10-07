                //  AtCoder - ABC(F)

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=3e5+2;
int a[N],tr[4*N];
void init(int node,int s,int e)
{
    if(s==e)
    {
        tr[node]=a[s];
        return;
    }
    int l=node*2;
    int r=l+1;
    int m=(s+e)/2;
    init(l,s,m);
    init(r,m+1,e);
    tr[node]=tr[l]^tr[r];
}
int Q(int node,int s,int e,int i,int j)
{
    if(i>e || j<s) return 0;
    else if(s>=i && e<=j) return tr[node];
    int l=node*2;
    int r=l+1;
    int m=(s+e)/2;
    int p=Q(l,s,m,i,j);
    int q=Q(r,m+1,e,i,j);
    return (p^q);
}
void up(int node,int s,int e,int i,int v)
{
    if(i>e || i<s) return;
    else if(s==e && s==i)
    {
        tr[node]^=v;
        return;
    }
    int l=node*2;
    int r=l+1;
    int m=(s+e)/2;
    up(l,s,m,i,v);
    up(r,m+1,e,i,v);
    tr[node]=tr[l]^tr[r];
}
int main()
{
    ft
    int i,j,n,m,l,r,q,t;
    cin>>n>>q;
    for(i=1;i<=n;i++) cin>>a[i];
    init(1,1,n);
    while(q--)
    {
        cin>>t>>l>>r;
        if(t==1) up(1,1,n,l,r);
        else cout<<Q(1,1,n,l,r)<<"\n";
    }
    return 0;
}


