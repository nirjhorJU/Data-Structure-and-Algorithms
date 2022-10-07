
//                  POJ - 2955

#include<iostream>
#include<string>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=102;
string s;
int d[N][N];
int go(int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    else if(d[i][j]!=-1)
    {
        return d[i][j];
    }
    else
    {
        if(s[i]=='(' && s[j]==')')
        {
            d[i][j]=2+go(i+1,j-1);
        }
        else if(s[i]=='[' && s[j]==']')
        {
            d[i][j]=2+go(i+1,j-1);
        }
        for(int k=i; k<j; k++)
        {
            d[i][j]=max(d[i][j],go(i,k)+go(k+1,j));
        }
        return d[i][j];
    }
}
int main()
{
    ft
    int t,i,j,n,m,l,r;
    while(cin>>s && s!="end")
    {
        memset(d,-1,sizeof(d));
        n=s.size();
        cout<<go(0,n-1)<<"\n";
    }
    return 0;
}

