/*
    Author: Hamza Hasbi
    Date: 28-Jul-16 9:13:08 PM
    This One is an old one.
*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define uld unsigned long double
#define ui unsigned int
#define ud unsigned double
#define uf unsigned float
#define pi 2*acos(0.0)
#define module cin.ignore()
#define rep(i,l,r) for(auto i=l;i<=r;i++)
#define range(x,y) for(auto x:y)
#define lcm(a,b) a*b/__gcd(a,b)
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
    string s;
    map<string,int>val;
    map<int,string>word;
    vector<string>ans;
    while(getline(cin,s))
    {
        vector<string>p;
        for(int i=0;i<s.size();i++)
        {
            string tmp="";
            while(s[i]!=' ' && i<s.size())
            {
                tmp+=s[i];
                i++;
            }
            p.push_back(tmp);
        }
        
        if(p[0]=="def")
        {
            auto it=val.find(p[1]);
            if(it!=val.end())
            {
                auto itt=word.find(val[p[1]]);
                word.erase(itt);
            }
            val[p[1]]=stoi(p[2]);
            word[stoi(p[2])]=p[1];
        }
        else if(p[0]=="calc")
        {
            int x=1,y=0;
            bool possible=true;
            for(int i=1;i<p.size();i++)
            {
                
                cout<<p[i]<<" ";
                if(p[i]=="+") x=1;
                else if(p[i]=="-") x=-1;
                else if(p[i]!="+" && p[i]!="-" && p[i]!="=") 
                {
                    //cout<<x*val[p[i]]<<endl;
                    //cout<<p[i]<<" "<<exist[p[i]]<<endl;
                    auto it=val.find(p[i]);
                    if(it!=val.end() && possible) y+=val[p[i]]*x;
                    else possible=false;
                }
            
            }
            auto mm = word.find(y);
            if(mm != word.end() && possible) cout << word[y] << endl;
            else cout << "unknown" << endl;
        }
        else if(p[0] == "clear")
        {
            val.clear();
            
            word.clear();
        }
    }
        
        
  return 0;
}
