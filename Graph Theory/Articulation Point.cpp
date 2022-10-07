//  LOJ-1026
#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define   pi  pair<int,int>
#define   mk  make_pair
#define   pb  push_back
#define   cc  10005
vector<int>g[cc];
vector<pi>ans;
static int clk,root,rootch;
int dfs_num[cc],dfs_low[cc],prt[cc];
bool vertex[cc];
void arti_point(int u)
{
    int i,j,v,sz=g[u].size();
    dfs_low[u]=dfs_num[u]=++clk;
    for(i=0;i<sz;i++)
    {
        v=g[u][i];
        if(!dfs_num[v])
        {
            prt[v]=u;
            if(u==root)
            {
                rootch++;
            }
            arti_point(v);
            if(dfs_low[v]>=dfs_num[u])
            {
                vertex[u]=true;
            }
            if(dfs_low[v]>dfs_num[u])
            {
                ans.pb(mk(min(u,v),max(u,v)));
            }
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
        }
        else if(v!=prt[u])
        {
            dfs_low[u]=min(dfs_low[u],dfs_num[v]);
        }
    }
}
void reset(int n)
{
    clk=0;
    for(int i=0;i<=n;i++)
    {
        g[i].clear();
        dfs_low[i]=dfs_num[i]=0;
        prt[i]=vertex[i]=0;
    }
}
int main()
{
    ft
    int z,t,n,u,v,i;
    string s;
    cin>>t;
    for(z=1; z<=t; z++)
    {
        cin>>n;
        reset(n);
        int l=n;
        while(l--)
        {
            cin>>u>>s;
            int num=0,nn=s.size()-1;
            for(i=1; i<nn; i++)
            {
                num=(num*10)+(s[i]-48);
            }
            for(i=0; i<num; i++)
            {
                cin>>v;
                g[u+1].pb(v+1);
                g[v+1].pb(u+1);
            }
        }
        ans.clear();
        for(i=1;i<=n;i++)
        {
            if(!dfs_num[i])
            {
                root=i,rootch=0;
                arti_point(i);
                vertex[root]=(rootch>1);
            }
        }
        int sz=ans.size();
        cout<<"Case "<<z<<":\n"<<sz<<" critical links"<<endl;
        sort(ans.begin(),ans.end());
        for(i=0;i<sz;i++)
        {
            cout<<--ans[i].first<<" - "<<--ans[i].second<<endl;
        }
    }
    return 0;
}
