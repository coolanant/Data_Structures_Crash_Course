#include<bits/stdc++.h>
using namespace std;

void solve(string str, int count, string ans){
    if(str.length()==0){
        if(count!=0){
            cout<<ans+to_string(count)<<endl;
        }else{
            cout<<ans<<endl;
        }
        return;   
    }
    if(count==0){
        solve(str.substr(1),count,ans+str[0]);
    }else{
        solve(str.substr(1),0,ans+to_string(count)+str[0]);
    }
        solve(str.substr(1),count+1,ans);
}

int main(){
    string str;
    cin>>str;
    
    solve(str,0,"");
}