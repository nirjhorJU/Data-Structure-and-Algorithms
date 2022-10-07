
                //                  UVA   -   12716

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long int
const int N=3e7+1;
ll a[N];
int main()
{
    ft
    ll t,i,j,n;
    for(i=1;i<N;i++)
    {
        for(j=i;j+i<N;j+=i)
        {
            n=i+j;
            if((n^i)==j)
            {
                a[n]++;
            }
        }
    }
    for(i=2;i<N;i++)
    {
        a[i]+=a[i-1];
    }
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        printf("Case %lld: %lld\n",i,a[n]);
    }
    return 0;
}



