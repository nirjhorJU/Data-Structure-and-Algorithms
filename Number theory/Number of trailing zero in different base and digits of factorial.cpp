#include <bits/stdc++.h>
#define P 1000000000
using namespace std;
double dp[1048579];
int ZERO(int N, int B)
{
    int i, zero = P, a, b, tmp;
    for(i = 2; i <= B; i++)
    {
        if(B%i == 0)
        {
            a = 0;
            while(B%i == 0)
            {
                a++, B /= i;
            }
            b = 0;
            tmp = N;
            while(tmp!=0)
            {
                b += tmp/i, tmp /= i;
            }
            zero = min(zero, b/a);
        }
    }
    if(zero == P)
    {
        return 0;
    }
    return zero;
}
int main()
{
    int N, B,k,i;
    dp[0]=0.0;
    for(i = 1; i <1048576; i++)
    {
        dp[i] = dp[i-1]+log(i*1.0);
    }
    while(scanf("%d %d", &N, &B) == 2)
    {
        k=(dp[N]/(log(B)))+1;
        printf("%d %d\n", ZERO(N, B),k);
    }
    return 0;
}

