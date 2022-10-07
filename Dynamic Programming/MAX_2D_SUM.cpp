#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a[110][110],b[110],dp[110];
int MAX(int n)
{
    int i,s=b[0];
    for(i=1;i<n;i++)
    {
        if(dp[i-1]+b[i]>b[i])
        {
            dp[i]=dp[i-1]+b[i];
        }
        s=max(s,dp[i]);
    }
    return s;
}
int main()
{
    ft
    int n,l,r,c,s;
    cin>>n;
    for(l=0;l<n;l++)
    {
        for(r=0;r<n;r++)
        {
            cin>>a[l][r];
        }
    }
    for(l=0;l<n;l++)
    {
        for(r=l;r<n;r++)
        {
            for(c=0;c<n;c++)
            {
                if(r==l)
                {
                    b[c]=a[c][r];
                }
                else
                {
                    b[c]+=a[c][r];
                }
                dp[c]=b[c];
            }
            if(l==0 && r==0)
            {
                s=MAX(n);
            }
            else
            {
                s=max(s,MAX(n));
            }
        }
    }
    cout<<s<<"\n";
    return 0;
}
