
                // ligjtoj - 1140
// Number of zeros between n and m (32 bit integers)

#include<bits/stdc++.h>
using namespace std;
#define  ll  long long
ll go(ll n)
{
    if(n<0) return 0;
    else if(n<10) return 1;
    ll c=1,m=10ll;
    while(m<=n)
    {
        c+=((n/m)-1ll)*(m/10ll)+min((m/10ll),(n%m)+1ll);
        m*=10ll;
    }
    return c;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,cs;
    ll n,m;
    cin>>t;
    for(cs=1; cs<=t; cs++)
    {
        cout<<"Case "<<cs<<": ";
        cin>>n>>m;
        cout<<(go(m)-go(n-1ll))<<endl;
    }
    return 0;
}
