
//                  https://cses.fi/problemset/task/1753/

#include<bits/stdc++.h>
using namespace std;
void create_lps(string p,int* lps)
{
    int idx,i,n;
    n=p.size();
    lps[0]=0;
    for(idx=0,i=1; i<n;)
    {
        if(p[idx]==p[i])
        {
            lps[i]=idx+1;
            idx++,i++;
        }
        else
        {
            if(idx!=0)
            {
                idx=lps[idx-1];
            }
            else
            {
                lps[i]=0,i++;
            }
        }
    }
}
int kmp(string s,string p)
{
    int i,j,n,m,c=0;
    n=s.size();
    m=p.size();
    int lps[m];
    create_lps(p,lps);
    for(i=0,j=0; i<n;)
    {
        if(s[i]==p[j])
        {
            i++,j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
        if(j==m)
        {
            c++;
            j=lps[j-1];
        }
    }
    return c;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,i,j,n,m,l,r;
    string s,p;
    cin>>s>>p;
    cout<<kmp(s,p)<<"\n";
    return 0;
}


