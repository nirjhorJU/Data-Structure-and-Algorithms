#include<bits/stdc++.h>
using namespace std;
int boss[200005];
int fd(int u)
{
    if(boss[u]==u)                      //UVA - 11503
    {
        return u;
    }
    return fd(boss[u]);
}
int main()
{
    int i,j,x,y,l,r,t,c,m,p;
    char a[30],s[30];
    map<string,int>mp;
    map<int,int>cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&m);
        mp.clear();
        cnt.clear();
        c=1;
        for(i=0; i<m; i++)
        {
            scanf("%s %s",a,s);
            p=0;
            if(mp[a]==0)
            {
                boss[c]=c;
                cnt[c]++;
                mp[a]=c++;
            }
            if(mp[s]==0)
            {
                boss[c]=c;
                cnt[c]++;
                mp[s]=c++;
            }
            x=fd(mp[a]);
            y=fd(mp[s]);
            if(x!=y)
            {
                boss[x]=y;
                cnt[y]+=cnt[x];
            }
            printf("%d\n",cnt[y]);
        }
        for(i=1;i<c;i++)
        {
            boss[i]=0;
        }
    }
    return 0;
}
