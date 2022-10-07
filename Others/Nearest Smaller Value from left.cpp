
//                  CSES -Nearest Smaller Values

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<ll,ll>
stack<pi>s;
int main()
{
    ft
    ll i,n,m,l=0,r;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>r;
        while(!s.empty() && s.top().first>=r)
        {
            s.pop();
        }
        if(s.empty())
        {
            cout<<"0 ";
        }
        else
        {
            cout<<s.top().second<<" ";
        }
        s.push({r,i});
    }
    return 0;
}


