#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int wt[4000],val[4000],dp[4000][4000];
vector<int>v;
int ks(int n,int m)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}
void choosing_selected_items_value(int n,int s,int m)
{
    for(int i=n;i>0 && s>0;i--)
    {
        if(s==dp[i-1][m])
        {
            continue;
        }
        else
        {
            v.push_back(val[i-1]);
            s-=val[i-1];
            m-=wt[i-1];
        }
    }
}
int main()
{
    ft
    int i,j,n,m,s;
    // m  = max_weight
    // n  = number_of_items
    // wt = contains_items_weight
    // val= contains_items_value
    while(cin>>m)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>wt[i];
            val[i]=wt[i];
        }
        j=ks(n,m);
        v.clear();
        choosing_selected_items_value(n,j,m);
        s=v.size();
        for(i=s-1;i>=0;i--)
        {
            cout<<v[i]<<" ";
        }
        cout<<"sum:"<<j<<"\n";
    }
    return 0;
}

