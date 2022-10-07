#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string s[105],p[105];
int dp[105][105];
int main()
{
    ft
    int i,j,n=0,m=0,x;
    while(cin>>s[n])
    {
        while(1)
        {
            if(s[n]=="#")
            {
                break;
            }
            cin>>s[++n];
        }
        while(1)
        {
            cin>>p[m];
            if(p[m]=="#")
            {
                break;
            }
            m++;
        }

        // LCS calculating

        for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
                else if(s[i-1]==p[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        vector<string>v;

        // LCS printing

        while(dp[n][m])
        {
            if(dp[n][m]==dp[n-1][m])
            {
                n--;
            }
            else if(dp[n][m]==dp[n][m-1])
            {
                m--;
            }
            else
            {
                n--,m--;
                v.push_back(s[n]);
            }
        }
        x=v.size()-1;
        for(i=x;i>=0;i--)
        {
            if(i==x)
            {
                cout<<v[i];
            }
            else
            {
                cout<<" "<<v[i];
            }
        }
        cout<<"\n";
        n=0,m=0;
    }
    return 0;
}

