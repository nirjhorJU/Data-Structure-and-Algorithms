

                // LOJ - Efficient Pseudo Code

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
const int N=46342;
ll M=1e9+7;
ll a[N];
ll BM(ll a,ll b)
{
    ll k=1;
    while(b!=0)
    {
        if(b%2==1)
        {
            k=(k*a)%M;
        }
        a=(a*a)%M;
        b/=2;
    }
    return k;
}
ll MI(ll a)
{
    return BM(a,M-2);
}
int main()
{
    ll n,m,l,r;
    cin>>n>>m;
    l=BM(n,m+1)-1;
    r=MI(n-1);
    cout<<(l*r)%M<<"\n";
    return 0;
}

