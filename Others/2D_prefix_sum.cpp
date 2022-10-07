
            //              UVA  - 108

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a[102][102];
int cal(int x,int y,int l,int r)
{
    return a[l][r]-a[x-1][r]-a[l][y-1]+a[x-1][y-1];
}
int main()
{
    ft
    int t,i,j,n,m,l,r,mx=INT_MIN;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(l=i;l<=n;l++)
            {
                for(r=j;r<=n;r++)
                {
                    mx=max(mx,cal(i,j,l,r));
                }
            }
        }
    }
    cout<<mx<<"\n";
    return 0;
}
