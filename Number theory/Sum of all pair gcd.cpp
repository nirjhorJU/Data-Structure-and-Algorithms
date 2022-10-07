

                //              UVA   -   11424

#include<iostream>
using namespace std;
#define  ll  long long
const ll N=2e5+1;
ll a[N],p[N],s[N];
void compute()
{
    p[1]=1;
    for(ll i=2; i<N; i++)
    {
        if(p[i]==0)
        {
            p[i]=i-1;
            for(ll j=i+i; j<N; j+=i)
            {
                if(p[j]==0)
                {
                    p[j]=j;
                }
                p[j]=(p[j]/i)*(i-1);
            }
        }
    }
}
void solve()
{
    compute();
    for(ll i=1;i<N;i++)
    {
        for(ll j=2;i*j<N;j++)
        {
            s[i*j]+=i*p[j];
        }
    }
    for(ll i=1;i<N;i++)
    {
        s[i]+=s[i-1];
    }
}
int main()
{
    ll t,i,j,n;
    solve();
    while(~scanf("%lld",&n) && n!=0)
    {
        printf("%lld\n",s[n]);
    }
    return 0;
}

