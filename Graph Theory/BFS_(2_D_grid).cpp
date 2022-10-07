#include<bits/stdc++.h>
using namespace std;
int n,vis[15][15];
int dx[]= {2,2,1,1,-1,-1,-2,-2};
int dy[]= {1,-1,2,-2,2,-2,1,-1};
char a[5],b[5];
queue<int>q;
void bfs(int s,int e)
{
    memset(vis,-1,sizeof(vis));
    int x,y,xx,yy;
    q.push(s);
    q.push(e);
    vis[s][e]=0;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        for(int i=0; i<8; i++)
        {
            xx=x+dx[i];
            yy=y+dy[i];
            if(vis[xx][yy]==-1&&xx>0&&yy>0&&xx<9&&yy<9)
            {
                vis[xx][yy]=vis[x][y]+1;
                q.push(xx);
                q.push(yy);
            }
        }
    }
}
int main()
{
    int j;
    while(~scanf("%s %s",a,b))
    {
        bfs((a[0]-96),(a[1]-48));
        j=vis[(b[0]-96)][(b[1]-48)];
        printf("To get from %s to %s takes %d knight moves.\n",a,b,j);
    }
    return 0;
}
