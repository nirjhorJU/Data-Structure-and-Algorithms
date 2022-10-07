
//                  Sum of Divisors (1 to n and n<=10^12)

#include <bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
ll M=1e9+7;
ll BM(ll a,ll b,ll r)
{
    a%=M;
    ll k=1ll;
    while(b>0)
    {
        if(b%2==1)
        {
            k=(k*a)%M;
        }
        a=(a*a)%M;
        b/=2ll;
    }
    return k;
}
ll MI()
{
    return BM(2ll,M-2,M);
}
ll cal(ll n,ll m)
{
    return (((n%M)*((n+1)%M))%M)*m;
}
int main()
{
    ft
    ll i,n,s=0,x,l,r,m;
    m=MI();
    cin>>n;
    for(i=1;i<=(n/i);i++)
    {
        x=n/i;
        s+=i*(x-i);
        s%=M;
        l=cal(x,m);
        r=cal(i-1,m);
        s+=l-r;
        s%=M;
    }
    cout<<s<<"\n";
    return 0;
}


