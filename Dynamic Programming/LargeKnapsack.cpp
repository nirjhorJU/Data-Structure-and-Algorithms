#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,K,N;
    cin >> K >> N;
    int v[N];
    int w[N];
    for(int i = 0; i<N; i++)
    {
        cin >> v[i] >> w[i];
    }
    int dp[K+1][N+1]; //represents the max value in knapsack of size K with N items remaining.
    for(i = 0; i<=N; i++)
    {
        dp[0][i] = 0;
    }
    for(i = 0; i<=K; i++)
    {
        dp[i][0] = 0;
    }

    for(i = 1; i<=K; i++)
    {
        for(j = 1; j<=N; j++)
        {
            if(w[j-1] <= i)
            {
                dp[i][j] = max(v[j-1] + dp[i - w[j-1]][j-1], dp[i][j-1]);
            }
            else
            {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    cout << dp[K][N];
    return 0;
}

