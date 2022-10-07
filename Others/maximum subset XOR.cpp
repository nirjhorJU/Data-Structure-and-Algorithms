#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
const ll N=1e5+3;
ll a[N];
int main()
{
    ft
    ll t,i,j,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll ind=0;
        for(i=31;i>=0;i--)
        {
            ll mx=LLONG_MIN;
            ll mx_ind;
            for(j=ind;j<n;j++)
            {
                if((a[j]&(1<<i))!=0 && a[j]>mx)
                {
                    mx=a[j];
                    mx_ind=j;
                }
            }
            if(mx==LLONG_MIN)
            {
                continue;
            }
            swap(a[ind],a[mx_ind]);
            for(j=0;j<n;j++)
            {
                if(j!=ind && (a[j]&(1<<i))!=0)
                {
                    a[j]^=mx;
                }
            }
            ind++;
        }
        ll s=0;
        for(i=0;i<n;i++)
        {
            s^=a[i];
        }
        cout<<s<<"\n";
    }
    return 0;
}

