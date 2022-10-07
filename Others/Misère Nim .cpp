
//  https://vjudge.net/problem/HackerRank-misere-nim

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    ft
    int c,t,i,n,s,ans,cnt;
    cin>>t;
    for(c=1;c<=t;c++)
    {
        cin>>n;
        ans=cnt=0;
        for(i=0;i<n;i++)
        {
            cin>>s;
            if(s==1)
            {
                cnt++;
            }
            ans^=s;
        }
        if(cnt==n)
        {
            (n%2==0)? cout<<"First": cout<<"Second";
        }
        else
        {
            (ans>0)? cout<<"First": cout<<"Second";
        }
        cout<<"\n";
    }
    return 0;
}


