#include <bits/stdc++.h>
using namespace std;
#define  ll  long long
const ll M=1e9+7;
const ll N=1e9+6;
ll BM(ll a,ll b,ll r)
{
    ll k=1;
    while(b!=0)
    {
        if(b&1==1)
        {
            k=(k*a)%r;
        }
        a=(a*a)%r;
        b>>=1;
    }
    return k;
}
int main()
{
    ll t,a,b,c;             // First (a^b^c) % m = (a ^ (p*(m-1)+q)) % m
    cin>>t;                 //  a^(p*(m-1)) % m = 1
    while(t--)              // result = a^q % m
    {                       // q = (b^c) % (m-1)
        cin>>a>>b>>c;
        ll d=BM(b,c,N);  // (b^c) % (m-1) // here m-1 = N
        cout<<BM(a,d,M)<<"\n"; // (a^d) % m
    }
    return 0;
}

