#include<bits/stdc++.h>
#define  pb  push_back
#define  mk  make_pair
#define  pi  pair<int,int>
using namespace std;
vector< pair<int,pi > >v;
long long int vis[1010];
int main()
{
    int t,s,i,j,l,r,w,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=0; i<n; i++)
        {
            vis[i]=1e7;
        }
        vis[0]=0;
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&l,&r,&w);
            v.pb(mk(l,mk(r,w)));
        }
        s=n-1;
        for(i=0; i<s; i++)
        {
            for(j=0; j<m; j++)
            {
                l=v[j].first;
                r=v[j].second.first;
                w=v[j].second.second;
                if(vis[l]+w<vis[r])
                {
                    vis[r]=vis[l]+w;
                }
            }
        }
        for(j=0; j<m; j++)
        {
            l=v[j].first;
            r=v[j].second.first;
            w=v[j].second.second;
            if(vis[l]+w<vis[r])
            {
                j=-1;
                break;
            }
        }
        if(j==-1)
        {
            printf("possible\n");
        }
        else
        {
            printf("not possible\n");
        }
        v.clear();
    }
    return 0;
}
