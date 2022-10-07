#include<bits/stdc++.h>
using namespace std;
int n,m,val[2005],wt[2005],k[2005][2005];
void ks()
{
    int i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                k[i][j]=0;
            }
            else if(wt[i-1]<=j)
            {
                k[i][j]=max(val[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
            }
            else
            {
                k[i][j]=k[i-1][j];
            }
        }
    }
    printf("%d\n",k[m][n]);
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&wt[i],&val[i]);
    }
    ks();
    return 0;
}
