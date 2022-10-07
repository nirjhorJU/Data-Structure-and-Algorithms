#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=1005;
const int M=1000007;
int dp[N][N],ans[N][N];
int main()
{
    ft
    int z,t,i,j,n,m,l;
    string s,p;
    cin>>t;
    for(z=1;z<=t;z++)
    {
        cin>>s>>p;
        n=s.size();
        m=p.size();
        l=max(n,m);
        for(i=0;i<=l;i++)
        {
            ans[0][i]=ans[i][0]=1;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans[i][j]=ans[i-1][j-1];
                }
                else if(dp[i-1][j]>dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    ans[i][j]=ans[i-1][j];
                }
                else if(dp[i][j-1]>dp[i-1][j])
                {
                    dp[i][j]=dp[i][j-1];
                    ans[i][j]=ans[i][j-1];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                    ans[i][j]=ans[i-1][j]+ans[i][j-1];
                    if(dp[i][j]==dp[i-1][j-1])
                    {
                        ans[i][j]-=ans[i-1][j-1];
                    }
                    if(ans[i][j]<0)
                    {
                        ans[i][j]+=M;
                    }
                    ans[i][j]%=M;
                }
            }
        }
        cout<<"Case "<<z<<": "<<ans[n][m]<<"\n";
    }
    return 0;
}
