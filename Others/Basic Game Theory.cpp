
//  https://vjudge.net/problem/HackerRank-day-1-a-chessboard-game

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int vis[16][16],ch[16][16];
int dx[]= {-2,-2,1,-1};
int dy[]= {1,-1,-2,-2};
void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>0 && yy>0 && xx<16 && yy<16)
        {
            if(vis[xx][yy]==0)
            {
                dfs(xx,yy);
            }
            if(ch[xx][yy]==0)
            {
                ch[x][y]=1;
            }
        }
    }
}
int main()
{
    ft
    int t,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        memset(vis,0,sizeof(vis));
        memset(ch,0,sizeof(ch));
        dfs(x,y);
        (ch[x][y]==1)? cout<<"First\n": cout<<"Second\n";
    }
    return 0;
}

