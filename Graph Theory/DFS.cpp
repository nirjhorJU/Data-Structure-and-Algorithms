#include<bits/stdc++.h>
using namespace std;
int n,c,vis[1005];
char a[5];
stack<int>q;
vector<int>v[1005];
void bfs(int s)
{
    int x,f;
    q.push(s);
    vis[s]=c;
    while(!q.empty())
    {
        f=q.top();
        q.pop();
        for(int i=0; i<v[f].size(); i++)
        {
            x=v[f][i];
            if(vis[x]==-1)
            {
                vis[x]=c;
                q.push(x);
            }
        }
    }
}
int main()
{
    int i,j,l,t,x,y;
    scanf("%d",&t);
    getchar();
    for(l=1; l<=t; l++)
    {
        memset(v,0,sizeof(v));
        scanf("%s",a);
        getchar();
        n=a[0]-64;
        while(gets(a))
        {
            int p=strlen(a);
            if(p==0)
            {
                break;
            }
            x=a[0]-64;
            y=a[1]-64;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        memset(vis,-1,sizeof(vis));
        c=0;
        for(i=1; i<=n; i++)
        {
            if(vis[i]==-1)
            {
                bfs(i);
                c++;
            }
        }
        printf("%d\n",c);
        if(l!=t)
        {
            printf("\n");
        }
    }
    return 0;
}
