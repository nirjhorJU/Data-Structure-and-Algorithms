
                //              UVA - 10212

#include<bits/stdc++.h>
using namespace std;
const int M = 1e9;
int main()
{
    int  n,r,i,k;
    long long int t;
    while(~scanf("%d %d",&n,&r))
    {
        k=n-r,t=1;
        for(i=n;i>k;i--)
        {
            t*=i;
            while(t%10==0)
            {
                t/=10;
            }
            t=(t%M);
        }
        t=t%10;
        printf("%d\n",t);
    }
    return 0;
