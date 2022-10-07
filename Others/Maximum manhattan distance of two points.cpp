
//                                          ABC - 178(E)

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    ft
    long long n,l,r,i,j,mn1,mn2,mx1,mx2;
    mn1=mn2=LLONG_MAX;
    mx1=mx2=LLONG_MIN;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>l>>r;
        mn1=min(mn1,l+r);
        mn2=min(mn2,l-r);
        mx1=max(mx1,l+r);
        mx2=max(mx2,l-r);
    }
    mx1-=mn1;
    mx2-=mn2;
    cout<<max(mx1,mx2)<<"\n";
    return 0;
}

