#include<bits/stdc++.h>
#define b 10000000
using namespace std;
typedef long long int lli;
static bool hashTable[5][b];
lli p[5]={2311,83,446141,123457,13331};
lli val(char c);
lli hasH(string &s,lli po);


lli hasH(string &s,lli po)
{

    lli d=1;
    lli k=0;
    for(lli i=0;i<s.size();i++)
    {
        k+=(d*val(s[i]))%b;
        k%=b;
        d*=po;
        d%=b;
    }
    return k;
}

lli val(char c)
{
    if(c>='a'&&c<='z')
    {
        return (lli)(c-'a'+1);
    }
    else
        return (lli)(c-'A'+27);
}

int main()
{
    lli n;
    cin>>n;
    vector<string> v;
    for(lli i=0;i<n;i++)
    {
        string s;
        cin>>s;
        string r=s;
        reverse(r.begin(),r.end());
        if(s!=r)
        {
            v.push_back(s);
            for(lli a=0;a<5;a++)
            {
                hashTable[a][hasH(r,p[a])]=1;
            }
        }
    }
    for(auto s:v)
    {
        lli flag=1;
        for(lli i=0;i<5;i++)
        {
            if(hashTable[i][hasH(s,p[i])]==0){
                flag=0;
            }
        }
        if(flag==1)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    

    return 0;
}
