#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string a;
int dp[1005][1005];
int geralt(int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    else if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    else if(a[i]==a[j])
    {
        return dp[i][j]=geralt(i+1,j-1);
    }
    else
    {
        return dp[i][j]=1+min(geralt(i+1,j-1),min(geralt(i+1,j),geralt(i,j-1)));
    }
}
int main()
{
    ft
    int z,t,i,j,n;
    cin>>t;
    for(z=1;z<=t;z++)
    {
        cin>>a;
        n=a.size();
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                dp[i][j]=-1;
            }
        }
        n=geralt(0,n-1);
        cout<<"Case "<<z<<": "<<n<<"\n";
    }
    return 0;
}

