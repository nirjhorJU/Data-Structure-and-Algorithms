//  https://codeforces.com/contest/1730/problem/B

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);
#define  ll  long long
const int N=1e5+5;
double a[N],c[N];
double go(ll n,double x)
{
    double ans=0.0;
    for(ll i=0;i<n;i++)
    {
        ans=max(ans,c[i]+abs(a[i]-x));
    }
    return ans;
}
void Solution()
{
    double m1,m2,l,r,eps=1e-6;
    ll i,n;
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++) cin>>c[i];
    l=0.0,r=1e8;
    while(r-l>eps)
    {
        m1=l+((r-l)/3.0);
        m2=r-((r-l)/3.0);
        double f1=go(n,m1);
        double f2=go(n,m2);
        if(f1>f2) l=m1;
        else if(f1<f2) r=m2;
        else l=m1,r=m2;
    }
    cout<<setprecision(10)<<fixed<<l<<"\n";
}
int32_t main()
{
    ft
    ll t=1;
    cin>>t;
    while(t--)
    {
        Solution();
    }
    return 0;
}
