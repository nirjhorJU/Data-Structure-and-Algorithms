#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string s,p,a;
void z_algo(int n,int m)
{
    int i,l=0,r=0;
    int z[n+5];
    memset(z,0,sizeof(z));
    for(i=1;i<n;i++)
    {
        if(i<=r)
        {
            z[i]=min(z[i-l],r-i+1);
        }
        while(i+z[i]<n && a[z[i]]==a[i+z[i]])
        {
            z[i]++;
        }
        if(i+z[i]-1>r)
        {
            l=i,r=i+z[i]-1;
        }
    }
    for(i=m;i<n;i++)
    {
        if(z[i]==m)
        {
            cout<<i-m-1<<"\n";
        }
    }
    cout<<"\n";
}
int main()
{
    ft
    int t,i;
    while(cin>>t)
    {
        cin>>p>>s;
        a.clear();
        a=p+"#"+s;
        z_algo(a.length(),t);
    }
    return 0;
}

