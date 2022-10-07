#include<stdio.h>
int cop(int n)
{
    if(n==1)
    {
        return 0;
    }
    int ans=n;
    for(int p=2; p*p<=n ;p++)
    {
        if(n%p==0)
        {
            while(n%p==0)
            {
                n/=p;
            }
            ans-=(ans/p);
        }
    }
    if(n>1)
    {
        ans-=(ans/n);
    }
    return ans;
}
int main()
{
    int n;
    while(~scanf("%d",&n) && n)
    {
        printf("%d\n",cop(n));
    }
    return 0;
}

