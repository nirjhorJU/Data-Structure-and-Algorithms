
//                          Atcoder -  ABC 173(E)

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
const int N=2e5+3;
ll M=1e9+7;
ll a[N];
ll max_product(ll n,ll k)
{
    ll i,l,r,s=1;
    sort(a,a+n);
    if(k%2==1)
    {
        if(a[n-1]==0)
        {
            return 0;
        }
        else if(a[n-1]<0)
        {
            for(i=n-1; i>=(n-k); i--)
            {
                s=(s*(a[i]+M))%M;
            }
            return s;
        }
        else
        {
            s=(s*(a[n-1]+M))%M;
            n--,k--;
        }
    }
    l=0,r=n-1;
    while(k>0)
    {
        if((a[l]*a[l+1])>(a[r]*a[r-1]))
        {
            s=(s*(a[l]+M))%M;
            s=(s*(a[l+1]+M))%M;
            l+=2;
        }
        else
        {
            s=(s*(a[r]+M))%M;
            s=(s*(a[r-1]+M))%M;
            r-=2;
        }
        k-=2;
    }
    return s;
}
int main()
{
    ft
    ll i,n,k;
    cin>>n>>k;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<max_product(n,k)<<"\n";
    return 0;
}

