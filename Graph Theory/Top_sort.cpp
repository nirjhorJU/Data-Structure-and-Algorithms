#include<bits/stdc++.h>
using namespace std;
int ind[150];
int main()
{
    int i,x,y,n,m,f;
    vector<int>ans;
    vector<int>v[150];
    queue<int>q;
    while(~scanf("%d %d",&n,&m))
    {
        if(n==0&&m==0)
        {
            break;
        }
        ans.clear();
        memset(v,0,sizeof(v));
        for(i=1; i<=n; i++)
        {
            ind[i]=0;
        }
        for(i=1; i<=m; i++)
        {
            scanf("%d %d",&x,&y);
            ind[y]++;
            v[x].push_back(y);
        }
        for(i=1; i<=n; i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            f = q.front();
            q.pop();
            ans.push_back(f);
            for(i=0; i<v[f].size(); i++)
            {
                x = v[f][i];
                ind[x]--;
                if(ind[x]==0)
                {
                    q.push(x);
                }
            }
        }
        for(int j=0; j<ans.size(); j++)
        {
            if(j>0)
            {
                printf(" ");
            }
            printf("%d",ans[j]);
        }
        printf("\n");
    }
    return 0;
}
