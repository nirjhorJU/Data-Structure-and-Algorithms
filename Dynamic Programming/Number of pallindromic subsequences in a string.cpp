#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define   ll  long long
ll dp[70][70];
ll ps(string s)
{
    int i,j,k,n;
    n=s.size();
    memset(dp, 0,sizeof(dp));
    for(i=0; i<n; i++)
    {
        dp[i][i]=1;
    }
    for(j=2; j<=n; j++)
    {
        for(i=0; i<n; i++)
        {
            k=j+i-1;
            if(k<n)
            {
                if(s[i]==s[k])
                {
                    dp[i][k]=dp[i][k-1]+dp[i+1][k]+1;
                }
                else
                {
                    dp[i][k]=dp[i][k-1]+dp[i+1][k]-dp[i+1][k-1];
                }
            }
        }
    }
    return dp[0][n-1];
}
int main()
{
    ft
    int z,t;
    string s;
    cin>>t;
    for(z=1; z<=t; z++)
    {
        cin>>s;
        cout<<"Case "<<z<<": "<<ps(s)<<"\n";
    }
    return 0;
}

