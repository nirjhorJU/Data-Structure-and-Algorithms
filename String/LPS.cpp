//                         UVA - 11404

#include<bits/stdc++.h>
using namespace std;
const int N=1e3+2;
string s,d[N][N];
string Max(string x,string y)
{
    int n=x.size();
    int m=y.size();
    if(n==m)
    {
        return (x<y)? x: y;
    }
    else
    {
        return (n>m)? x: y;
    }
}
void LPS()
{
    int i,j,n,l;
    n=s.size();
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            d[i][j].clear();
        }
    }
    for(i=0; i<n; i++)
    {
        d[i][i]=s[i];
    }
    for(l=2; l<=n; l++)
    {
        for(i=0; i<n-l+1; i++)
        {
            j=l+i-1;
            if(s[i]==s[j] && l==2)
            {
                d[i][j]+=s[i];
                d[i][j]+=s[j];
            }
            else if(s[i]==s[j])
            {
                d[i][j]+=s[i];
                d[i][j]+=d[i+1][j-1];
                d[i][j]+=s[j];
            }
            else
            {
                d[i][j]=Max(d[i][j-1],d[i+1][j]);
            }
        }
    }
    cout<<d[0][n-1]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,i,j,n,m,c,r=0,ans=0,ind,x;
    while(cin>>s)
    {
        LPS();
    }
    return 0;
}
