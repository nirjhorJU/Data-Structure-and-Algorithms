#include<bits/stdc++.h>
using namespace std;
int coin[105];
long long int c[102][10002];
void cc(int n,int m)
{
    int i,j;
    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        {
            if(j==0)
            {
                c[i][j]=1;
            }
            else if(i==0)
            {
                c[i][j]=0;
            }
            else if(coin[i]<=j)
            {
                c[i][j]=(c[i-1][j]+c[i][j-coin[i]])%100000007;
            }
            else
            {
                c[i][j]=c[i-1][j];
            }
        }
    }
    printf("%lld\n",c[m][n]);
}
int main()
{
    int t,i,j,n,m;
    scanf("%d",&t);
    //m = number of coins
    //n = given value
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&m,&n);
        for(j=1;j<=m;j++)
        {
            scanf("%d",&coin[j]);
        }
        coin[0]=0;
        printf("Case %d: ",i);
        cc(n,m);
    }
    return 0;
}
