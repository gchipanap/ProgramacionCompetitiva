/*
3. 1584 – Circular Sequence
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=1
6&page=show_problem&problem=4459
*//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s;

string solve(int ind)
{
    string tmp(s.begin()+ind,s.end());
    for(int i=0;i<ind;i++)
        tmp+=s[i];
    return tmp;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        vector<int> v[4];
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='A')
                v[0].push_back(i);
            if(s[i]=='C')
                v[1].push_back(i);
            if(s[i]=='G')
                v[2].push_back(i);
            if(s[i]=='T')
                v[3].push_back(i);
        }
        int res=-1;
        string ans,tmp;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                tmp=solve(v[i][j]);
                if(ans.empty()||tmp<ans)
                    ans=tmp;
                if(ans.size()!=0)
                    res=0;
            }
            if(res!=-1)
            {
                cout<<ans<<endl;
                break;
            }
        }
    }
    return 0;
}
