#include<stdio.h>
#include<string.h>
char a[1005];
int pp()
{
    int i,j,k,l;
    int n = strlen(a);
    int c[n];
    bool p[n][n];
    for (i=0; i<n; i++)
    {
        p[i][i] = true;
    }
    for (l=2; l<=n; l++)
    {
        for (i=0; i<n-l+1; i++)
        {
            j = i+l-1;
            if (l == 2)
                p[i][j] = (a[i] == a[j]);
            else
                p[i][j] = (a[i] == a[j]) && p[i+1][j-1];
        }
    }
    for (i=0; i<n; i++)
    {
        if (p[0][i] == true)
            c[i] = 0;
        else
        {
            c[i]=n;
            for(j=0; j<i; j++)
            {
                if(p[j+1][i] == true && 1+c[j]<c[i])
                    c[i]=1+c[j];
            }
        }
    }
    return (c[n-1]+1);
}
int main()
{
    int z,t,i,j;
    scanf("%d",&t);
    for(z=1; z<=t; z++)
    {
        scanf("%s",a);
        printf("Case %d: %d\n",z,pp());
    }
    return 0;
}
