/*
    Author: Hamza Hasbi
    Copyrights: "h.hamza" ==> "www.hamzahasbi.me"
    Date: 02/05/2017 17:50:40
    Another (G)old one.
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
//inline lcm(int a,int b) {return a*b/__gcd(a,b);}
//inline gcd(ll a,ll b) {return 1LL*b == 0 ? a : gcd(1LL*b, a*1LL % b*1LL);}
using namespace std;

main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    while(cin>>n){
        if(n==0) break;
        int mx=INT_MAX,mn=1;
        vector<int>div;
        string s,sep;
        int a;
        while(n--){
            cin>>s>>sep>>a;
            if(s[0]=='l'){
                mx=min(mx,a-1);
            }
            else if(s[0]=='d') {
                if(a==1) continue;
                div.push_back(a);
            }
            else{
                mn=max(mn,a+1);
            }
            
        }
    
        if(mn>mx) cout<<"none"<<endl;
        else{
            vector<int>ans;
            if(!div.size()){
                if(mx-mn+1>50000) cout<<"infinite"<<endl;
                else {
                    for(int i=mn;i<=mx-1;i++){
                    cout<<i<<" ";
                    }
                    cout<<mx<<endl;
                }
            }
            else{
                
                for(int i=mn;i<=mx;i++){
                    bool flag=true;
                    for(int j=0;j<div.size();j++){
                        flag&=(i%div[j]==0);
                    }
                    if(flag) ans.push_back(i);
                    if(ans.size()>50000) break;
                }
                
                if(!ans.size()) cout<<"none"<<endl;
                else{
                    if(ans.size()>50000) cout<<"infinite"<<endl;
                    else{
                        for(int k=0;k<ans.size()-1;k++) cout<<ans[k]<<" ";
                        cout<<ans[ans.size()-1]<<endl;
                    }
                }
            }
        }
    }
    
    return 0;
}
