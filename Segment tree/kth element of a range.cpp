
//                  Spoj - K-th Number

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=1e5+1;
vector<int>tr[3*N];
int a[N];
pair<int,int>b[N];
void Merge(int node,int l,int r)
{
    int i,j,n,m;
    n=tr[l].size();
    m=tr[r].size();
    for(i=0,j=0;i<n && j<m;)
    {
        if(tr[l][i]<tr[r][j])
        {
            tr[node].push_back(tr[l][i]);
            i++;
        }
        else
        {
            tr[node].push_back(tr[r][j]);
            j++;
        }
    }
    for(;i<n;i++)
    {
        tr[node].push_back(tr[l][i]);
    }
    for(;j<m;j++)
    {
        tr[node].push_back(tr[r][j]);
    }
}
void init(int node,int s,int e)
{
    if(s==e)
    {
        tr[node].push_back(b[s].second);
        return;
    }
    int l=node*2;
    int r=l+1;
    int m=(s+e)/2;
    init(l,s,m);
    init(r,m+1,e);
    Merge(node,l,r);
}
int Q(int node,int s,int e,int i,int j,int k)
{
    if(s==e)
    {
        return tr[node][0];
    }
    int l=node*2;
    int r=l+1;
    int m=(s+e)/2;
    int val=upper_bound(tr[l].begin(),tr[l].end(),j)-lower_bound(tr[l].begin(),tr[l].end(),i);
    if(val>=k)
    {
        return Q(l,s,m,i,j,k);
    }
    else
    {
        return Q(r,m+1,e,i,j,k-val);
    }
}
int main()
{
    ft
    int i,k,n,m,l,r;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]={a[i],i};
    }
    sort(b+1,b+n+1);
    init(1,1,n);
    while(m--)
    {
        cin>>l>>r>>k;
        cout<<a[Q(1,1,n,l,r,k)]<<"\n";
    }
    return 0;
}

