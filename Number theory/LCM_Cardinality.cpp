
        // link : https://stackoverflow.com/questions/39558111/from-1-to-n-how-many-pairs-have-lcm-n

#include <bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define  ll  long long
bool prime(ll n)
{
    for(ll i=2; i<=(n/i); i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ft
    ll z,t,n,i,c,x;
    while(cin>>n && n)
    {
        cout<<n<<" ";
        if(n==1)
        {
            cout<<"1\n";
            continue;
        }
        c=1;
        if(prime(n)==true)
        {
            c*=3;
            n=1;
        }
        for(i=2; n!=1; i++)
        {
            if(n%i==0)
            {
                ll d=0;
                while(n%i==0)
                {
                    d++;
                    n/=i;
                }
                c*=((d<<1)+1);
                if(prime(n)==true && n!=1)
                {
                    c*=3;
                    n=1;
                }
            }
        }
        c++;
        cout<<(c>>1)<<"\n";
    }
    return 0;
}
// 12 has 8 pairs whose LCMs are 12
// 12 = 2^2 * 3^1
// so result = (( (2*2+1) * (2*1+1) ) + 1)/ 2 = 8
