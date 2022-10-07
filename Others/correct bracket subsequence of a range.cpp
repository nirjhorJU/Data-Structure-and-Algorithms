
//                                  CF  -  380C

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
struct go
{
    int o,c;
}tr[3*N];
char str[N];
void init(int node,int s,int e)
{
    if(s==e)
    {
        tr[node].o=(str[s]=='(');
        tr[node].c=(str[s]==')');
        return;
    }
    int l=node*2;
    int r=l+1;
    int m=(s+e)/2;
    init(l,s,m);
    init(r,m+1,e);
    int x=min(tr[l].o,tr[r].c);
    tr[node].o=tr[l].o+tr[r].o-x;
    tr[node].c=tr[l].c+tr[r].c-x;
}
go Q(int node,int s,int e,int i,int j)
{
    if(s>j || e<i)
    {
        go ans;
        ans.o=0,ans.c=0;
        return ans;
    }
    else if(s>=i && e<=j)
    {
        return tr[node];
    }
    int l=node*2;
    int r=l+1;
    int m=(s+e)/2;
    go p=Q(l,s,m,i,j);
    go q=Q(r,m+1,e,i,j);
    int x=min(p.o,q.c);
    go ans;
    ans.o=p.o+q.o-x,ans.c=p.c+q.c-x;
    return ans;
}
int main()
{
    int i,j,n,m,l,r;
    scanf("%s %d",str,&m);
    n=strlen(str);
    init(1,0,n-1);
    while(m--)
    {
        scanf("%d %d",&l,&r);
        l--,r--;
        go x=Q(1,0,n-1,l,r);
        printf("%d\n",(r-l+1-x.o-x.c));
    }
    return 0;
}


