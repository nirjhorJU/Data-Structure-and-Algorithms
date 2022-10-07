
//              lightoj - 1096

#include <bits/stdc++.h>
using namespace std;
#define  ll  long long
#define  ft  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll M=10007;
void MM(ll a[4][4],ll b[4][4])
{
    int i,j,l;
    ll x,t[4][4];
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            t[i][j]=0;
            for(l=0; l<4; l++)
            {
                t[i][j]=(t[i][j]+a[i][l]*b[l][j])%M;
            }
        }
    }
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            a[i][j]=t[i][j];
        }
    }
}
void BM(ll a[4][4],ll b)
{
    ll k[4][4];
    int i,j,c=0;
    while(b!=0)
    {
        if(b&1==1)
        {
            if(c==0)
            {
                for(i=0; i<4; i++)
                {
                    for(j=0; j<4; j++)
                    {
                        k[i][j]=a[i][j];
                    }
                }
            }
            else
            {
                MM(k,a);
            }
            c=1;
        }
        MM(a,a);
        b>>=1;
    }
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            a[i][j]=k[i][j];
        }
    }
}
ll F(ll k[4][4],ll n)
{
    BM(k,n-2);
    return (k[0][3]%M);
}
int main()
{
    ft
    ll i,j,n,m,t,z,a,b,c;
    cin>>t;
    for(z=1; z<=t; z++)
    {
        cin>>n>>a>>b>>c;
        if(n<3)
        {
            cout<<"Case "<<z<<": 0\n";
        }
        else
        {
            ll k[4][4];
            k[0][0]=a,k[0][1]=0,k[0][2]=b,k[0][3]=1;
            k[1][0]=1,k[1][1]=0,k[1][2]=0,k[1][3]=0;
            k[2][0]=0,k[2][1]=1,k[2][2]=0,k[2][3]=0;
            k[3][0]=0,k[3][1]=0,k[3][2]=0,k[3][3]=1;
            cout<<"Case "<<z<<": "<<((c*F(k,n))%M)<<"\n";
        }
    }
    return 0;
}
