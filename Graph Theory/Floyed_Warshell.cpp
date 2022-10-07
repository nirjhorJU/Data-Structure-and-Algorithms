#include<bits/stdc++.h>
using namespace std;
#define  fn  freopen("out.txt","w",stdout);
#define  sf  scanf
#define  pf  printf
map<int,int>mp;
vector< pair<int,int> >v;
int a[105][105];
void init(int n)
{
    int i,j;
    for(i=1; i<n; i++)
    {
        for(j=1; j<n; j++)
        {
            if(i==j)
                a[i][j]=0;
            else
                a[i][j]=1e6;
        }
    }
}
int main()
{
    int i,l,r,c,s,z=1,m;
    while(~sf("%d %d",&l,&r))
    {
        if(l==0 && r==0)
        {
            break;
        }
        c=1,s=0,m=0;
        if(mp[l]==0)
            mp[l]=c++;
        if(mp[r]==0)
            mp[r]=c++;
        v.push_back(make_pair(mp[l],mp[r]));
        while(~sf("%d %d",&l,&r))
        {
            if(l==0 && r==0)
            {
                break;
            }
            if(mp[l]==0)
                mp[l]=c++;
            if(mp[r]==0)
                mp[r]=c++;
            v.push_back(make_pair(mp[l],mp[r]));
        }
        init(c);
        l=v.size();
        for(i=0; i<l; i++)
        {
            a[v[i].first][v[i].second]=1;
        }
        for(i=1; i<c; i++)
        {
            for(l=1; l<c; l++)
            {
                for(r=1; r<c; r++)
                {
                    if(a[l][r]>a[l][i]+a[i][r])
                    {
                        a[l][r]=a[l][i]+a[i][r];
                    }
                }
            }
        }
        for(l=1; l<c; l++)
        {
            for(r=1; r<c; r++)
            {
                if(l==r)
                {
                    continue;
                }
                s+=a[l][r];
                m++;
            }
        }
        pf("Case %d: average length between pages = %.3f clicks\n",z++,(s*1.0/m));
        mp.erase(mp.begin(),mp.end());
        v.clear();
    }
    return 0;
}
