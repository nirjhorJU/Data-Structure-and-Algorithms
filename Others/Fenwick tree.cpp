#include <bits/stdc++.h>
using namespace std;
long long int a[1000003],n;
void up(int j,int ch)
{
    while(j<=n)
    {
        a[j]+=ch;
        j+=(j&(-j));
    }
    return;
}
long long int S(int j)
{
    long long int s=0;
    while(j>0)
    {
        s+=a[j];
        j-=(j&(-j));
    }
    return s;
}
int main()
{
    int i,q,m,p;
    long long int s;
    char c[2];
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&m);
        up(i,m);
    }
    scanf("%d",&q);
    for(i=1; i<=q; i++)
    {
        scanf("%s%d%d",c,&m,&p);
        if(c[0]=='q')
        {
            s=(S(p)-S(m-1));
            printf("%lld\n",s);
        }
        else
        {
            up(m,p);
        }
    }
    return 0;
}
