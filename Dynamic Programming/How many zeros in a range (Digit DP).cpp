#include<bits/stdc++.h>
using namespace std;
#define  ll  long long
#define  pb  push_back
const ll NX = 70 ;
ll dp[2][2][NX][NX];
ll vis[2][2][NX][NX];
ll lim, tt ;
vector < ll > inp ;
ll DP( ll pos, ll small,ll start, ll value)
{
    if( pos == lim )
        return value ;
    ll &ret = dp[small][start][pos][value];
    ll &v = vis[small][start][pos][value];
    if( v == tt )
        return ret ;
    v = tt ;
    ll ses = small ? 9 : inp[pos];
    ll i ;
    ret = 0 ;
    if( !start )
    {
        for ( i = 0 ; i <= ses ; i++ )
        {
            ret += DP( pos + 1, small | i < inp[pos],0, (i == 0) + value );
        }
    }
    else
    {
        for ( i = 1 ; i <= ses ; i++ )
        {
            ret += DP( pos + 1, small | i < inp[pos],0, (i == 0) + value );
        }
        ret += DP( pos + 1, 1,1, 0 );
    }
    return ret ;
}
ll Cal( ll x )
{
    if( x < 0 )
        return 0 ;
    if( x <= 9 )
        return 1 ;
    inp.clear();
    while( x )
    {
        inp.pb(x%10);
        x/=10;
    }
    reverse(inp.begin(),inp.end());
    lim = inp.size();
    tt++;
    return DP( 0, 0, 1, 0 ) + 1;
}
int main()
{
    ll cs, t,l,r ;
    cin>>t;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        cin>>l>>r;
        ll ans = Cal(r) - Cal(l-1);
        printf("Case %lld: %lld\n",cs,ans);
    }
    return 0;
}

