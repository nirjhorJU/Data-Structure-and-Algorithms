#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a[1005],b[1005],n,m;
void LCIS()
{
    int table[1005],cur,i,j,s=0;
    for(i=0; i<m; i++)
    {
        table[i]=0;
    }
    for(i=0; i<n; i++)
    {
        cur=0;
        for(j=0; j<m; j++)
        {
            if(a[i]==b[j] && cur+1>table[j])
            {
                table[j]=cur+1;
                s=max(s,table[j]);
            }
            else if(a[i]>b[j] && table[j]>cur)
            {
                cur=table[j];
            }
        }
    }
    cout<<s<<"\n";
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


