
// UVA - 10617

#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    ft
    int i,j,k,n,m;
    string s;
    cin>>n;
    while(n--)
    {
        cin>>s;
        m=s.size();
        long long dp[60][60];
        for(i=0;i<m;i++) dp[i][i]=1;
        for(i=1;i<m;i++)
        {
            for(j=0;j+i<m;j++)
            {
                dp[j][j+i]=dp[j][j+i-1]+1;
                for(k=j;k<j+i;k++)
                {
                    if(s[k]==s[j+i])
                    {
                        if((k+1)!=(j+i))
                        {
                            dp[j][j+i]+=dp[k+1][j+i-1];
                        }
                        dp[j][j+i]++;
                    }
                }
            }
        }
        cout<<dp[0][m-1]<<"\n";
    }
    return 0;
}

