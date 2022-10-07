#include<bits/stdc++.h>
using namespace std;
int a[100005],b[300005];
// Finding minimum value in an array between range[l,r];
void build(int nn,int l,int r)
{
    if(l==r)
    {
        b[nn]=a[l];
        return;
    }
    int mid = (l+r)/2;
    build(nn*2,l,mid);
    build(nn*2+1,mid+1,r);
    b[nn]=min(b[nn*2],b[nn*2+1]);
}
int query(int nn,int s,int e,int l,int r)
{
    if(l<=s&&e<=r)
    {
        return b[nn];
    }
    int mid = (s+e)/2;
    if(l<=mid)
    {
        return query(nn*2,s,mid,l,r);
    }
    if(mid<l)
    {
        return query(nn*2+1,mid+1,e,l,r);
    }
    return min(query(nn*2,s,mid,l,mid),query(nn*2+1,mid+1,l,mid+1,r));
}
int main()
{

    int n,i,q,t,l,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        build(1,1,n);
        for(i=1;i<=q;i++)
        {
            scanf("%d %d",&l,&r);
            printf("%d\n",query(1,1,n,l,r));
        }
    }
    return 0;
}
