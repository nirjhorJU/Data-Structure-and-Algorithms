#include <bits/stdc++.h>
using namespace std;
#define  ll  long long
const ll N=1e6+2;
ll arr[N],c[N];
ll MAXGCD(ll n)
{
    ll high = 0;
    for (ll i = 0; i < n; i++)
    {
        high = max(high, arr[i]);
        c[arr[i]]++;
    }
    for (ll i = high; i >= 1; i--)
    {
        ll j = i;
        ll check = 0;
        while (j <= high)
        {
            if(c[j] >=2)
            {
                return j;
            }
            else if (c[j] == 1)
            {
                check++;
            }
            j += i;
            if(check == 2)
            {
                return i;
            }
        }
    }
}
int main()
{
    ll i,n;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<MAXGCD(n)<<"\n";
    return 0;
}

