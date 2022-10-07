
                //Lightoj - 1289

#include<bits/stdc++.h>
using namespace std;
#define   ll  unsigned int
#define   N   100000002
ll p[5761465];
ll sum[5761465];
bitset<N>a;
ll primes()
{
    for(ll i=3; i<10001; i+=2)
    {
        for(ll j=i*i; j<N; j+=2*i)
        {
            a[j]=1;
        }
    }
    p[0]=2;
    sum[0]=2;
    ll n=1;
    for(ll i=3; i<N; i+=2)
    {
        if(a[i]==0)
        {
            p[n]=i;
            sum[n]=sum[n-1]*i;
            n++;
        }
    }
    return n;
}
ll lcm(ll n,ll sz)
{
    ll u,ans=1;
    for(ll i=0; i<sz && p[i]<=(n/p[i]) ; i++)
    {
        ll k=n/p[i];
        while(k>=p[i])
        {
            k/=p[i];
            ans*=p[i];
        }
    }
    u=upper_bound(p,p+sz,n)-p-1;
    return (ans*sum[u]);
}
int main()
{
    ll z,t,l,m=1,sz;
    sz=primes();
    scanf("%u",&t);
    for(z=1; z<=t; z++)
    {
        scanf("%u",&l);
        printf("Case %u: %u\n",z,lcm(l,sz));
    }
    return 0;
}
