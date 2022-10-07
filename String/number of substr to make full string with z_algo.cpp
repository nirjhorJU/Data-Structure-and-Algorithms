#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int  z[1000005];
void zfunction()
{
    memset(z,0,sizeof(z));
    int i,len,left,right,S=0,j;
    z[0] = 0;
    left = 0;
    right = 0;
    len=strlen(s);
    for(i=1; i<len; i++)
    {
        if(i<=right)
        {
            z[i]=min(z[i-left],right-i+1);
        }
        while(i+z[i]<len && s[i+z[i]]==s[z[i]])
        {
            ++z[i];
        }
        if(i+z[i]-1>right)
        {
            left=i;
            right=i+z[i]-1;
        }
    }
    for(i=0; i<len; i++)
    {
        if(z[i]>S)
        {
            S=z[i];
            j=i;
        }
    }
    if((len-j)==S && len%2==0)
    {
        printf("%d\n",(len/j));
    }
    else
    {
        printf("1\n");
    }
}
int main()
{
    int t,l,r;
    while(~scanf("%s",s))
    {
        int n=strlen(s);
        if(n==1 && s[0]=='.')
        {
            break;
        }
        zfunction();
    }
    return 0;
}

