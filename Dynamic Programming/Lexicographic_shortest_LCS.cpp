#include<bits/stdc++.h>
using namespace std;
#define  ll  long long
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string s1,s2,dp[105][105];
string check(string a,string b)
{
    int n=a.size(),m=b.size();
    if(n==m)
    {
        return (a<b)? a : b;
    }
    else
    {
        return (n>m)? a : b;
    }
}
string LCS(int n,int m)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j].clear();
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+s1[i-1];
            }
            else
            {
                dp[i][j]=check(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
    ft
    int t,z,i,j;
    cin>>t;
    for(z=1;z<=t;z++)
    {
        cin>>s1>>s2;
        s1=LCS(s1.size(),s2.size());
        cout<<"Case "<<z<<": ";
        if(s1.size()==0)
        {
            cout<<":(\n";
        }
        else
        {
            cout<<s1<<"\n";
        }
    }
    return 0;
}


