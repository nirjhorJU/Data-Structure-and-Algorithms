#include<bits/stdc++.h>
using namespace std;
char a[50][50][50];
int l,n,m,vis[50][50][50];
int dx[]={-1,1,0,0,0,0};
int dy[]={0,0,0,0,-1,1};
int dz[]={0,0,1,-1,0,0};
queue< int >q;
void bfs(int x,int y,int z)
{
    memset(vis,-1,sizeof(vis));
    int xx,yy,zz,i;
    vis[x][y][z]=0;
    q.push(x);
    q.push(y);
    q.push(z);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        z=q.front();
        q.pop();
        for(i=0;i<6;i++)
        {
            xx=x+dx[i];
            yy=y+dy[i];
            zz=z+dz[i];
            if(vis[xx][yy][zz]==-1&&xx>=0&&xx<l&&yy>=0&&yy<n&&zz>=0&&zz<m&&a[xx][yy][zz]!='#')
            {
                vis[xx][yy][zz]=vis[x][y][z]+1;
                q.push(xx);
                q.push(yy);
                q.push(zz);
            }
        }
    }
}
int main()
{
    int i,j,k,sx,sy,sz,ex,ey,ez;
    while(~scanf("%d %d %d",&l,&n,&m)&&l&&n&&m)
    {
        for(i=0; i<l; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%s",a[i][j]);
                for(k=0;k<m;k++)
                {
                    if(a[i][j][k]=='S')
                    {
                        sx=i,sy=j,sz=k;
                    }
                    else if(a[i][j][k]=='E')
                    {
                        ex=i,ey=j,ez=k;
                    }
                }
            }
        }
        bfs(sx,sy,sz);
        if(vis[ex][ey][ez]==-1)
        {
            printf("Trapped!\n");
        }
        else
        {
            printf("Escaped in %d minute(s).\n",vis[ex][ey][ez]);
        }
    }
    return 0;
}
