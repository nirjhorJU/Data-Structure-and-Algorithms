#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll a[100005];
void up(int j,ll c)
{
    while(j<=n)
    {
        a[j]=(a[j]+c)%1000000007;
        j+=(j&(-j));
    }
    return ;
}
ll S(int j)
{
    ll s=0;
    while(j>0)
    {
        s=(s+a[j])%1000000007;
        j-=(j&(-j));
    }
    return s;
}
int main()
{
    int t,l,r,j,i,b[100005],p[100005];
    ll v;
    b[0]=0,p[0]=0;
    map<int,int>m;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%d",&l);
        for(i=0;i<l;i++)
        {
            scanf("%d",&b[i]);
            p[i]=b[i];
        }
        sort(p,p+l);
        m.clear();
        n=1;
        for(i=0;i<l;i++)
        {
            a[i+1]=0;
            if(m[p[i]]==0)
            {
                m[p[i]]=n++;
            }
        }
        n--;
        for(i=0;i<l;i++)
        {
            r=m[b[i]];
            v=S(r-1);
            up(r,v+1);
        }
        printf("Case %d: %lld\n",j,S(n));
    }
    return 0;
}
