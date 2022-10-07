
//                      CF - 26B

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,i,j,n,m,l,r;
    string s;
    cin>>s;
    n=s.size();
    l=r=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            l++;
        }
        else
        {
            if(l==0)
            {
                r++;
            }
            else
            {
                l--;
            }
        }
    }
    cout<<(n-l-r)<<"\n";
    return 0;
}


