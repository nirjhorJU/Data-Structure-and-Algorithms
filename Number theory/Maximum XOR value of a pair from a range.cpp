

            //              CF - 276D

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
void go(ll l, ll r)
{
    ll i,p=l^r,x=0;
    for(i=1;p>0;i*=2,p/=2)
    {
        x+=i;
    }
    cout<<x<<"\n";
}
int main()
{
    ft
    ll t,i,j,n,m,l,r;
    cin>>l>>r;
    go(l,r);
    return 0;
}


