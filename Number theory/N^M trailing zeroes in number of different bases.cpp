
                                // UVA - 12216

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
ll M=1e8+7;
ll F(ll n,ll m,ll t)
{
    ll i,s1=1,s2=1,l;
    for(i=2; i<=(n/i); i++)
    {
        if(n%i==0)
        {
            l=0;
            while(n%i==0)
            {
                n/=i;
                l++;
            }
            s1*=(l*m/t)+1;
            s1%=M;
            s2*=(l*m/(t+1))+1;
            s2%=M;
        }
    }
    if(n>1)
    {
        s1*=(m/t)+1;
        s1%=M;
        s2*=(m/(t+1))+1;
        s2%=M;
    }
    return (s1-s2+2*M)%M;
}
int main()
{
    ft
    ll c=1,t,n,m;
    while(cin>>n>>m>>t && (n+m+t)!=0)
    {
        cout<<"Case "<<c++<<": "<<F(n,m,t)<<"\n";
    }
    return 0;
}


