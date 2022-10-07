
                        //  CF - 597B

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  pi  pair<int,int>
#define  F   first
#define  S   second
const int N=2e5+3;
int main()
{
    ft
    int t,i,j,n,m,l,r;
    cin>>n;
    pi a[n+1];
    for(i=0;i<n;i++)
    {
        cin>>a[i].S>>a[i].F;
    }
    sort(a,a+n);
    l=-1,r=0;
    for(i=0;i<n;i++)
    {
        if(l<a[i].S)
        {
            r++;
            l=a[i].F;
        }
    }
    cout<<r<<"\n";
    return 0;
}


