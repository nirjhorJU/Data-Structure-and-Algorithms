
                                    // lightoj - 1319
        // Learning Source - https://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/

#include<bits/stdc++.h>
using namespace std;
#define  ll  unsigned long long
ll BM(ll a,ll b,ll r)
{
    a%=r;
    ll k=1ll;
    while(b>0)
    {
        if(b%2==1)
        {
            k=(k*a)%r;
        }
        a=(a*a)%r;
        b/=2ll;
    }
    return k;
}
ll MI(ll a,ll m)
{
    return BM(a,m-2ll,m);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,i,n;
    cin>>t;
    for(int cs=1; cs<=t; cs++)
    {
        cout<<"Case "<<cs<<": ";
        cin>>n;
        ll a[n+1],pp[n+1],inv[n+1],r[n+1],prod=1ll;
        for(i=0;i<n;i++)
        {
            cin>>a[i]>>r[i];   // a - array of prime numbers
            prod*=a[i];        // r - array of remainders
        }                      // prod - Product of the elments of a
        for(i=0;i<n;i++)
        {
            pp[i]=prod/a[i];  // pp - array of prod/a[i]
        }
        for(i=0;i<n;i++)
        {
            inv[i]=MI(pp[i],a[i]); // inv - array of the mode inverse of pp[i] respect to a[i]
        }
        ll ans=0,tmp;
        for(i=0;i<n;i++)
        {
            tmp=((pp[i]%prod)*(r[i]%prod)*(inv[i]%prod))%prod;  // result = ((pp[i]*r[i]*inv[i])+....)%prod;
            ans=(ans+tmp)%prod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
