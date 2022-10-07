#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int a[N],tr[3*N];
void init(int node,int s,int e)
{
    if(s==e)
    {
        tr[node]=a[s];
        return;
    }
    int l=node*2;
    int r=node*2+1;
    int m=(s+e)/2;
    init(l,s,m);
    init(r,m+1,e);
    tr[node]=tr[l]+tr[r];
}
int Q(int node,int s,int e,int l,int r)
{
    if(l>e || r<s)
    {
        return 0;
    }
    else if(s>=l && e<=r)
    {
        return tr[node];
    }
    int i=node*2;
    int j=node*2+1;
    int m=(s+e)/2;
    int p=Q(i,s,m,l,r);
    int q=Q(j,m+1,e,l,r);
    return (p+q);
}
void up(int node,int b,int e,int i,int v)
{
    if(i>e || i<b)
    {
        return;
    }
    else if(b>=i && e<=i)
    {
        tr[node]+=v;
        return;
    }
    int l=node*2;
    int r=node*2+1;
    int m=(b+e)/2;
    up(l,b,m,i,v);
    up(r,m+1,e,i,v);
    tr[node]=tr[l]+tr[r];
}
int main()
{
    int z,t,n,m,i,q,l,r;
    scanf("%d",&t);
    for(z=1; z<=t; z++)
    {
        scanf("%d %d",&n,&q);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        printf("Case %d:\n",z);
        init(1,1,n);
        while(q--)
        {
            scanf("%d",&m);
            if(m==1)
            {
                scanf("%d",&l);
                l++;
                r=Q(1,1,n,l,l);
                printf("%d\n",r);
                up(1,1,n,l,-r);
            }
            else if(m==2)
            {
                scanf("%d %d",&l,&r);
                l++;
                up(1,1,n,l,r);
            }
            else
            {
                scanf("%d %d",&l,&r);
                l++,r++;
                printf("%d\n",Q(1,1,n,l,r));
            }
        }
    }
    return 0;
}
