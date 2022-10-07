
//          CF - 1462E2

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
const int N=2e5+3;
ll M=1e9+7;
ll finv[N],inv[N],f[N],a[N];
void IN()
{
    inv[0]=inv[1]=1;
    for (ll i=2; i<N; i++)
    {
        inv[i]=(inv[M%i]*(M-(M/i))%M)%M;
    }
}
void IF()
{
    finv[0]=finv[1]=1;
    for (ll i=2; i<N; i++)
    {
        finv[i]=(inv[i]*finv[i-1])%M;
    }
}
ll cal(ll n, ll r)
{
    if(n<r)
    {
        return 0;
    }
    return (((f[n]*finv[r])%M)*finv[n-r])%M;
}
ll fact()
{
    f[0]=1;
    for(ll i=1; i<N; i++)
    {
        f[i]=f[i-1]*i;
        f[i]%=M;
    }
}
void mod_inv()
{

    IN();
    IF();
    fact();
}
int main()
{
    ft
    ll t,i,j,n,m,k,l,r,s;
    mod_inv();
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        s=0;
        for(i=0; i<n; i++)
        {
            l=upper_bound(a+i+1,a+n,(a[i]+k))-lower_bound(a+i+1,a+n,a[i]);
            s+=cal(l,m-1);
            s=(s+M)%M;
        }
        cout<<s<<"\n";
    }
    return 0;
}

