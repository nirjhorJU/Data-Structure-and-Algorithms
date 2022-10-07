#include<bits/stdc++.h>
using namespace std;
int n,test[120];
pair<float,float>p[120];
vector< pair<int,float> >v[120];
priority_queue< pair<float,int> >q;
float vis[120];
void mst()
{
    int i,f,x;
    float c,s=0;
    for(i=0;i<n;i++)
    {
        vis[i]=1000000.00;
        test[i]=-1;
    }
    vis[0]=0.0;
    q.push(make_pair(0.0,0));
    while(!q.empty())
    {
        f=q.top().second;
        c=-q.top().first;
        q.pop();
        if(test[f]!=-1)
        {
            continue;
        }
        test[f]=1;
        s+=c;
        for(i=0;i<v[f].size();i++)
        {
            x=v[f][i].first;
            c=v[f][i].second;
            if(vis[x]>c)
            {
                vis[x]=c;
                q.push(make_pair(-c,x));
            }
        }
    }
    printf("%.2f\n",s);
}
int main()
{
    //freopen("out.txt","w",stdout);
    int z,t,i,j;
    float c;
    scanf("%d",&t);
    for(z=1; z<=t; z++)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%f %f",&p[i].first,&p[i].second);
            v[i].clear();
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i!=j)
                {
                    c=sqrt(((p[i].first-p[j].first)*(p[i].first-p[j].first))+((p[i].second-p[j].second)*(p[i].second-p[j].second)));
                    v[i].push_back(make_pair(j,c));
                    v[j].push_back(make_pair(i,c));
                }
            }
        }
        mst();
        if(z!=t)
        {
            printf("\n");
        }
    }
    return 0;
}
