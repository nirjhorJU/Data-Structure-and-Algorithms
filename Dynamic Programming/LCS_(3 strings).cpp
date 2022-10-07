#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dp[100][100][100];
string a,b,c;
int LCS(int n,int m,int l)
{
    int i,j,k;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            for(k=0;k<=l;k++)
            {
                if(i==0 || j==0 || k==0)
                {
                    dp[i][j][k]=0;
                }
                else if(a[i-1]==b[j-1] && a[i-1]==c[k-1])
                {
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                }
                else
                {
                    dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
    }
    return dp[n][m][l];
}
int main()
{
    ft
    int z,t,n,m,l;
    cin>>t;
    for(z=1; z<=t; z++)
    {
        cin>>a>>b>>c;
        n=a.size();
        m=b.size();
        l=c.size();
        cout<<"Case "<<z<<": "<<LCS(n,m,l)<<"\n";
    }
    return 0;
}

