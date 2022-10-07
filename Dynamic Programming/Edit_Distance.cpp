#include <bits/stdc++.h>
using namespace std;
int dp[5003][5003];
void ED(string s,string p)
{
    int i,j,n,m;
    n=s.size();
    m=p.size();
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=m; j++)
        {
            if(i==0)
            {
                dp[i][j]=j;
            }
            else if(j==0)
            {
                dp[i][j]=i;
            }
            else if(s[i-1]==p[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }
    cout<<dp[n][m]<<"\n";

                        // Printing operations of Edit distance

    for(int no=1,i=n,j=m; i>0 || j>0 ; )
    {
        if(s[i-1]==p[j-1])
        {
            i--,j--;
        }
        else
        {
            if(i>0 && j>0 &&(dp[i-1][j-1]+1==dp[i][j]))
            {
                cout<<no++<<" Replace "<<i<<","<<p[j-1]<<"\n";
                s[i-1]=p[j-1];
                i--,j--;
            }
            else if(j>0 && (dp[i][j-1]+1==dp[i][j]))
            {
                cout<<no++<<" Insert "<<i+1<<","<<p[j-1]<<"\n";
                s.insert(i,1,p[j-1]);
                j--;
            }
            else if(i>0 && (dp[i-1][j]+1==dp[i][j]))
            {
                cout<<no++<<" Delete "<<i<<"\n";
                s.erase(i-1,1);
                i--;
            }
        }
    }
}
int main()
{
    ft
    string s,p;
    cin>>s>>p;
    ED(s,p);
    return 0;
}

