
//https://codeforces.com/problemset/problem/5/C

#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=1e6+3;
string s;
int d[N];
int main()
{
    ft
    int t,i,j,n,m,l,r;
    cin>>s;
    n=s.size();
    stack<int>st;
    for(i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            st.push(i);
        }
        else
        {
            if(!st.empty())
            {
                l=st.top();
                st.pop();
                d[l]=i-l+1;
            }
        }
    }
    l=0;
    for(i=n-1;i>=0;i--)
    {
        d[i]=d[i]+d[i+d[i]];
        l=max(l,d[i]);
    }
    if(l==0)
    {
        cout<<"0 1\n";
    }
    else
    {
        for(i=0,r=0;i<n;i++)
        {
            if(d[i]==l)
            {
                r++;
            }
        }
        cout<<l<<" "<<r<<"\n";
    }
    return 0;
}


