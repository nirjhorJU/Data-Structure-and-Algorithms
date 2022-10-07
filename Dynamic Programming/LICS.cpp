
        //CF - 977F

#include <bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int a[N],n;
void LICS()
{
    map<int, int>mp;
    int dp[n],x;
    memset(dp, 0, sizeof(dp));
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (mp[a[i]-1]!=0)
        {
            int lastIndex = mp[a[i] - 1] - 1;
            dp[i] = 1 + dp[lastIndex];
        }
        else
        {
            dp[i] = 1;
        }
        mp[a[i]] = i + 1;
        if(mx<dp[i])
        {
            mx=dp[i];
            x=i;
        }
    }
    cout<<mx<<"\n"; // mx = LICS
    int y=a[x];
    // Printing LICS
    for(int i=y-mx+1; i<=y; i++)
    {
        if(i==y)
        {
            cout<<i<<"\n";
        }
        else
        {
            cout<<i<<" ";
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    LICS();
    return 0;
}

