#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define   ll  long long
int a[100005],b[100005];
ll f[100005];
void up(int i,int n)
{
    while(i<=n)
    {
        f[i]+=1;
        i+=i&(-i);
    }
}
ll sum(int i)
{
    ll s=0;
    while(i>0)
    {
        s+=f[i];
        i-=i&(-i);
    }
    return s;
}
int main()
{
    ft
    int i,n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
            f[i]=0;
        }
        f[n]=0;
        sort(b,b+n);
        for(i=0;i<n;i++)
        {
            a[i]=lower_bound(b,b+n,a[i])-b+1;
        }
        ll s=0;
        for(i=n-1;i>=0;i--)
        {
            s+=sum(a[i]-1);
            up(a[i],n);
        }
        cout<<s<<"\n";
    }
    return 0;
}


