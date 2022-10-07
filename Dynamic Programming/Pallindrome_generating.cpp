#include<bits/stdc++.h>
using namespace std;
#define  sf  scanf
#define  pf  printf
#define  pb  push_back
char a[1005];
int dp[1005][1005];
int pal(int i,int j)
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
        return dp[i][j]=pal(i+1,j-1);
    }
    else
    {
        return dp[i][j]=1+min(pal(i,j-1),pal(i+1,j));
    }
}
void pt(int i,int j)
{
    string b,c;
    while(i<=j)
    {
        if(i==j)
        {
            b.pb(a[i]);
            break;
        }
        else if(i+1==j && a[i]==a[j])
        {
            b.pb(a[i]);
            c.pb(a[j]);
            break;
        }
        else if(a[i]==a[j])
        {
            b.pb(a[i]);
            c.pb(a[j]);
            i++,j--;
        }
        else if(dp[i][j-1]<dp[i+1][j])
        {
            b.pb(a[j]);
            c.pb(a[j]);
            j--;
        }
        else
        {
            b.pb(a[i]);
            c.pb(a[i]);
            i++;
        }
    }
    reverse(c.begin(),c.end());
    cout<<(b+c)<<'\n';
}
int main()
{
    int t,i,j,s,n;
    while(gets(a))
    {
        n=strlen(a);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                dp[i][j]=-1;
            }
        }
        s=pal(0,n-1);
        pf("%d ",s);
        pt(0,n-1);
    }
    return 0;
}
