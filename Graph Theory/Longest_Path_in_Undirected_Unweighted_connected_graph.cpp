#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  pb  push_back
const int N=1e4+2;
int vis[N],ans,mx,ind;
vector<int>v[N];
void DFS(int f)
{
    vis[f]=1;
    ans++;
    if((ans-1)>mx)
    {
        mx=ans-1;
        ind=f;
    }
    for(auto x:v[f])
    {
        if(vis[x]==0)
        {
            DFS(x);
        }
    }
    ans--;
}
int main()
{
    ft
    int t,i,j,n,m,l,r;
    cin>>n;
    for(i=1; i<n; i++)
    {
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    DFS(1);
    memset(vis,0,sizeof(vis));
    DFS(ind);
    cout<<mx<<"\n";
    return 0;
}
