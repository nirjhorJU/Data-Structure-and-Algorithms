#define  ll  long long
ll a[100005];
bool Binary_Search(ll l,ll r,ll element)
{
    while(l<=r)
    {
        ll m=(l+r)/2;
        if(a[m]==element) return true;
        else if(a[m]<element) l=m+1;
        else r=m-1;
    }
    return false;
}
