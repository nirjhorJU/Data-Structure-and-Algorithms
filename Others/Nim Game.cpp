

//  https://vjudge.net/problem/HackerRank-day-2-nim-game

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    ft
    int c,t,i,n,s,ans;
    cin>>t;
    for(c=1;c<=t;c++)
    {
        cin>>n;
        ans=0;
        for(i=0;i<n;i++)
        {
            cin>>s;
            ans^=s;
        }
        if(ans==0)
        {
            cout<<"Second\n";
        }
        else
        {
            cout<<"First\n";
        }
    }
    return 0;
}


