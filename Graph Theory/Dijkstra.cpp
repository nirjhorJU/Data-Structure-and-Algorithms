#include<bits/stdc++.h>
using namespace std;
priority_queue< pair<int,int> >q;
vector< pair<int,int> >v[10005];
int vis[10005],n;
pair<int,int>l;
void dj(int s)
{
	for(int m=1;m<=n;m++)
	{
		vis[m]=10000005;
	}
	l.first=0;
	l.second=s;
	q.push(l);
	while(!q.empty())
	{
		l=q.top();
		q.pop();
		for(int i=0;i<v[l.second].size();i++)
		{
			int u=v[l.second][i].first;
			int c=v[l.second][i].second;
			int ct=c+(-l.first);
			if(ct<vis[u])
			{
				vis[u]=ct;
				q.push(make_pair(-ct,u));
			}
		}
	}
}
int main()
{
    int t,m,x,y,s,e,z;
    scanf("%d",&t);
    while(t--)
	{
		scanf("%d %d",&n,&m);
		memset(v,0,sizeof(v));
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			v[x].push_back(make_pair(y,z));
		}
		scanf("%d %d",&s,&e);
		dj(s);
		if(vis[e]!=10000005)
		{
			printf("%d\n",vis[e]);
		}
		else
		{
			printf("NO\n");
		}
	}
    return 0;
}
