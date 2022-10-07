//            https://cses.fi/problemset/result/327436/

#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
string s,p;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,i,j,n,m,c,r=0,ans=0,ind,x;
    cin>>p;
    s+="$";
    n=p.length();
    for(i=0; i<n;)
    {
        if(r==0)
        {
            s+="#";
        }
        else
        {
            s+=p[i];
            i++;
        }
        r=(r+1)%2;
    }
    s+="#@";                                    // Algorithm starts.
    c=r=0;
    n=s.size();
    for(i=1; i<(n-1); i++)
    {
        int mirr=2*c-i;
        if(i<r)
        {
            a[i]=min(r-i,a[mirr]);
        }
        while(s[i+(1+a[i])]==s[i-(1+a[i])])
        {
            a[i]++;
        }
        if((i+a[i])>r)
        {
            c=i;
            r=i+a[i];
        }
        if(a[i]>ans)
        {
            ans=a[i];
            ind=i;
        }
    }
    if(ans&1==1)
    {
        i=j=ind;
        x=1;
    }
    else
    {
        i=ind-1;
        j=ind+1;
        x=2;
    }
    while(x<ans)
    {
        x+=2;
        i-=2;
        j+=2;
    }
    for(; i<=j; i+=2)
    {
        cout<<s[i];
    }
    cout<<"\n";
    return 0;
}
