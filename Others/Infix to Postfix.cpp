
            // UVA - 727

#include<bits/stdc++.h>
using namespace std;
#define   ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define   pb  push_back
stack<char>s;
string st,str,eq;
int main()
{
    ft
    int i,n,x;
    char c;
    cin>>n;
    cin.ignore();
    getline(cin,str);
    while(n--)
    {
        eq+='(';
        while(getline(cin,str))
        {
            x=str.size();
            if(x==0)
            {
                break;
            }
            eq+=str[0];
        }
        eq+=')';
        x=eq.size();
        for(i=0; i<x; i++)
        {
            if(eq[i]>='0' && eq[i]<='9')
            {
                st+=eq[i];
            }
            else if(eq[i]==')')
            {
                c=s.top();
                while(c!='(')
                {
                    st+=c;
                    s.pop();
                    c=s.top();
                }
                s.pop();
            }
            else if(eq[i]=='+' ||eq[i]=='-' ||eq[i]=='*' ||eq[i]=='/')
            {
                c=s.top();
                while(c=='+' ||c=='-' ||c=='*' ||c=='/')
                {
                    if(eq[i]=='+' || eq[i]=='-')
                    {
                        st+=c;
                        s.pop();
                    }
                    else if((eq[i]=='*' || eq[i]=='/') && (c=='*' || c=='/'))
                    {
                            st+=c;
                            s.pop();
                    }
                    else
                    {
                        break;
                    }
                    c=s.top();
                }
                s.push(eq[i]);
            }
            else
            {
                s.push(eq[i]);
            }
        }
        cout<<st<<"\n";
        if(n!=0)
        {
            cout<<"\n";
        }
        st.clear();
        eq.clear();
        str.clear();
        while(!s.empty())
        {
            s.pop();
        }
    }
    return 0;
}

