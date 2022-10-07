#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int phi[N],cop[N];
void coprimes()
{
    int i,j,p;
    for(i=1; i<N; i++)
    {
        phi[i]=i;
    }
    for(p=2; p<N; p++)
    {
        if(phi[p]==p)
        {
            phi[p]=p-1;
            for(i=p*2; i<N; i+=p)
            {
                phi[i]=(phi[i]/p)*(p-1);
            }
        }
    }
    for(i=1; i<N; i++)
    {
        cop[i]=cop[i-1]+phi[i];
    }
}
int main()
{
    coprimes();
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<cop[n]<<"\n"; // number of Coprime pairs between (1 to n)
    }
    return 0;
}
