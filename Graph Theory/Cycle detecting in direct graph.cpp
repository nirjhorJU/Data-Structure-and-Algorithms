
//      https://codeforces.com/contest/919/problem/D

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  pb  push_back
const int N=3e5+3;
vector<int>v[N];
int d[N][26],vis[N],mark[N],ind[N];
char s[N];
bool iscyclic(int f)
{
    if(vis[f]==0)
    {
        vis[f]=mark[f]=1;
        for(int x:v[f])
        {
            if(vis[x]==0 && iscyclic(x)==true)
            {
                return true;
            }
            else if(mark[x]==1)
            {
                return true;
            }
        }
    }
    mark[f]=0;
    return false;
}
int main()
{
    ft
    int t,i,j,n,m,l,r;
    cin>>n>>m>>s+1;
    for(i=0;i<m;i++)
    {
        cin>>l>>r;
        v[l].pb(r);
        ind[r]++;
    }
    for(i=1;i<=n;i++)
    {
        if(iscyclic(i)==true)
        {
            cout<<"Cyclic\n";
            return 0;
        }
    }
    cout<<"No cycle\n;
    return 0;
}


