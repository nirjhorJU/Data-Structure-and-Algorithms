#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define   pb  push_back
const int mx=1e6+5;
int a[mx],f[mx],b[mx];
vector<int>v;
void LIS(int n)
{
    int i,ans=0;
    for(i=1;i<n;i++)
    {
        f[i]=lower_bound(b+1,b+ans+1,a[i])-b;
        ans=max(ans,f[i]);
        b[f[i]]=a[i];
    }
    cout<<"Max hits: "<<ans<<"\n";
    for(i=n-1;i>0;i--)
    {
        if(f[i]==ans)
        {
            v.pb(a[i]);
            ans--;
        }
    }
    n=v.size();
    for(i=n-1;i>=0;i--)
    {
        cout<<v[i]<<"\n";
    }
}
int main()
{
    ft
    int i,n,t;
    string s;
    cin>>t;
    getchar();
    getline(cin,s);
    while(t--)
    {
        i=1;
        while(getline(cin,s))
        {
            if(s.empty())
            {
                break;
            }
            a[i++]=stoi(s);
        }
        n=i;
        for(i=0;i<n;i++)
        {
            b[i]=0;
            f[i]=0;
        }
        v.clear();
        LIS(n);
        if(t!=0)
        {
            cout<<"\n";
        }
    }
    return 0;
}
