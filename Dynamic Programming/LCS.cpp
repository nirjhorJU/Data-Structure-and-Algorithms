#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,m,dp[2005][2005];
string a,b;
void LCS(int n,int m)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<"\n";
}
int main()
{
    ft
    while(getline(cin,a))
    {
        getline(cin,b);
        n=a.size();
        m=b.size();
        LCS(n,m);
    }
    return 0;
}
