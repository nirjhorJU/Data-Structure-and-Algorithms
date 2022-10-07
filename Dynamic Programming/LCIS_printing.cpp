#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define   pb  push_back
int a[550],b[550],n,m;
vector<int>v;
void LCIS()
{
    int table[550],par[550],cur,last,i,j,s=0,idx=-1;
    for(i=0; i<m; i++)
    {
        table[i]=0;
    }
    for(i=0; i<n; i++)
    {
        cur=0 ,last=-1;
        for(j=0; j<m; j++)
        {
            if(a[i]==b[j] && cur+1>table[j])
            {
                table[j]=cur+1;
                par[j]=last;
            }
            else if(a[i]>b[j] && table[j]>cur)
            {
                cur=table[j];
                last=j;
            }
        }
    }
    for(i=0;i<m;i++)
    {
        if(table[i]>s)
        {
            s=table[i];
            idx=i;
        }
    }
    for(i=0;idx!=-1;i++)
    {
        v.pb(b[idx]);
        idx=par[idx];
    }
    last=v.size();
    cout<<s<<"\n";
    for(i=last-1;i>=0;i--)
    {
        cout<<v[i]<<" ";
    }
}
int main()
{
    ft
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>b[i];
    }
    LCIS();
    return 0;
}


