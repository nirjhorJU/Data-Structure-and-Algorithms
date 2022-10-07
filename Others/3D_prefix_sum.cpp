
                //              UVA   -  10755

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
const int N=2e5+3;
ll a[22][22][22];
ll cal(ll x,ll y,ll z)
{
    return (a[x-1][y][z]+a[x][y-1][z]+a[x][y][z-1])-(a[x-1][y-1][z]+a[x-1][y][z-1]+a[x][y-1][z-1])+a[x-1][y-1][z-1];
}
ll go(ll x1,ll y1,ll z1,ll x2,ll y2,ll z2)
{
    ll p=a[x2][y2][z2]-(a[x2][y2][z1-1]+a[x2][y1-1][z2]+a[x1-1][y2][z2]);
    ll q=a[x1-1][y1-1][z2]+a[x2][y1-1][z1-1]+a[x1-1][y2][z1-1]-a[x1-1][y1-1][z1-1];
    return (p+q);
}
int main()
{
    ft
    ll c=1,t,i,j,k,n,m,l,r,p,q;
    cin>>t;
    for(c=1; c<=t; c++)
    {
        if(c>1)
        {
            cout<<"\n";
        }
        cin>>n>>m>>l;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                for(k=1; k<=l; k++)
                {
                    cin>>a[i][j][k];
                }
            }
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                for(k=1; k<=l; k++)
                {
                    a[i][j][k]+=cal(i,j,k);
                }
            }
        }
        ll mx=LLONG_MIN;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                for(k=1; k<=l; k++)
                {
                    for(p=i; p<=n; p++)
                    {
                        for(q=j; q<=m; q++)
                        {
                            for(r=k; r<=l; r++)
                            {
                                mx=max(mx,go(i,j,k,p,q,r));
                            }
                        }
                    }
                }
            }
        }
        cout<<mx<<"\n";
    }
    return 0;
}
