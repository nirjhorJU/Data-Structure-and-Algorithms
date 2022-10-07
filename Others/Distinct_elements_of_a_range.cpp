#include<bits/stdc++.h>
using namespace std;
#define  sf(n)  scanf("%d",&n);
const int N=1e5+2;
struct D
{
    int l,r,i;
};
int a[N],ans[50003],cnt[N],mod,cur_ans;
D q[50003];
bool cmp(D x,D y)
{
    if((x.l/mod)==(y.l/mod))
    {
        return x.r<y.r;
    }
    return (x.l/mod)<(y.l/mod);
}
void add(int l)
{
    cnt[a[l]]++;
    if(cnt[a[l]]==1)
    {
        cur_ans++;
    }
}
void subtract(int l)
{
    cnt[a[l]]--;
    if(cnt[a[l]]==0)
    {
        cur_ans--;
    }
}
int main()
{
    int z,t,i,j,n,m,x,y;
    sf(t)
    for(z=1; z<=t;z++)
    {
        sf(n)
        sf(m)
        for(i=0;i<n;i++)
        {
            sf(a[i])
        }
        mod=sqrt(n*1.0);
        for(i=0;i<m;i++)
        {
            sf(x)
            sf(y)
            x--,y--;
            q[i].l=x;
            q[i].r=y;
            q[i].i=i;
        }
        sort(q,q+m,cmp);
        int cl,cr;
        cl=cr=cur_ans=0;
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<m;i++)
        {
            x=q[i].l;
            y=q[i].r;
            while(cl<x)
            {
                subtract(cl);
                cl++;
            }
            while(cl>x)
            {
                add(cl-1);
                cl--;
            }
            while(cr<=y)
            {
                add(cr);
                cr++;
            }
            while(cr>y+1)
            {
                subtract(cr-1);
                cr--;
            }
            ans[q[i].i]=cur_ans;
        }
        printf("Case %d:\n",z);
        for(i=0;i<m;i++)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
