

                    //  CF  - 803F
                    //  Loj - 1161

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
const int N=1e4+3;
ll f[N];
ll val(ll n)
{
    return (n*(n-1)*(n-2)*(n-3))/24;
}
int main()
{
    ft
    ll c,t,i,j,n,m,l,r;
    cin>>t;
    for(c=1;c<=t;c++)
    {
        cout<<"Case "<<c<<": ";
        cin>>n;
        m=0;
        memset(f,0,sizeof(f));
        for(i=0;i<n;i++)
        {
            cin>>l;
            m=max(m,l);
            f[l]++;
        }
        for(i=1;i<=m;i++)
        {
            for(j=2*i;j<=m;j+=i)
            {
                f[i]+=f[j];
            }
            f[i]=val(f[i]);
        }
        for(i=m;i>0;i--)
        {
            for(j=2*i;j<=m;j+=i)
            {
                f[i]-=f[j];
            }
        }
        cout<<f[1]<<endl;
    }
    return 0;
}
