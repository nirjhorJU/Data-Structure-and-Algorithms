#include<bits/stdc++.h>
using namespace std;
#define  sf  scanf
#define  pf  printf
int a[105],dp[105][100005];
map<int,int>mp;
int subset_sum(int n,int m)
{
    int i,j,s=0;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(j==0)
            {
                dp[i][j]=1;
            }
            else if(i==0)
            {
                dp[i][j]=0;
            }
            else if(a[i]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i]];
            }
            if(dp[i][j]==1 && mp[j]==0)
            {
                s+=j;
                mp[j]=1;
            }
        }
    }
    return s;
}
int main()
{
    int i,j,t,s,n,m;
    sf("%d",&t);
    while(t--)
    {
        sf("%d",&n);
        m=0;
        for(i=1;i<=n;i++)
        {
            sf("%d",&a[i]);
            m+=a[i];
        }
        a[0]=0;
        s=subset_sum(n,m);
        pf("%d\n",s);
        mp.erase(mp.begin(),mp.end());
    }
    return 0;
}
