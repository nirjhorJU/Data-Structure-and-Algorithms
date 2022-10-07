/*We have N integers A1,A2,...,AN.
There are N(N−1)/2 ways to choose two of them and form a pair.
If we compute the product of each of those pairs and sort the results in ascending order,
what will be the K-th number in that list?
*/
//                  Atcoder - Beginner Contest (155_d)

#include <bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
const ll N=2e5+5;
ll v[N];
int main()
{
    ft
    ll n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    sort(v,v+n);
    ll s=-1e18,e=1e18,mid;
    while(s+1<e)
    {
        mid=(s+e)/2;
        ll ind=0;
        for(int i=0; i<n; i++)
        {
            if(v[i]<0)
            {
                ll lo=i,hi=n,m;
                while(lo+1!=hi)
                {
                    m=(lo+hi)/2;
                    if(v[i]*v[m]<=mid)
                        hi=m;
                    else
                        lo=m;
                }
                ind+=n-hi;
            }
            else
            {
                ll lo=i,hi=n,m;
                while(lo+1!=hi)
                {
                    m=(lo+hi)/2;
                    if(v[i]*v[m]<=mid)
                        lo=m;
                    else
                        hi=m;
                }
                ind+=lo-i;
            }
        }
        if(ind<k)
        {
            s=mid;
        }
        else
        {
            e=mid;
        }
    }
    cout << e;
    return 0;
}

