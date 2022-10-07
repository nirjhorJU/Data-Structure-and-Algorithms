#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define   mk  make_pair
#define   pi  pair<int,int>
#define   pb  push_back
pair<int,int>a[1005];
int vis[1005],b[1005];
map< pi, int>mp;
vector<int>v;
int main()
{
    ft
    int t,i,j,n=0,m,k,l,r,s=0;
    mp.clear();
    while(cin>>l>>r)
    {
        a[n]=mk(l,r);
        mp[a[n]]=(n+1);
        n++;
    }
    sort(a,a+n);
    for(i=n-1; i>=0; i--)
    {
        vis[i]=lower_bound(b+1,b+s+1,a[i].second)-b;
        s=max(vis[i],s);
        b[vis[i]]=a[i].second;
    }
    cout<<s<<"\n";
    for(i=0; i<n; i++)
    {
        if(vis[i]==s)
        {
            v.pb(mp[a[i]]);
            s--;
        }
    }
    j=v.size();
    for(i=0;i<j;i++)
    {
        cout<<v[i]<<"\n";
    }
    return 0;
}


