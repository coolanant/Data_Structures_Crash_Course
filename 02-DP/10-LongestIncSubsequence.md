```c++
#include <iostream>
#include<climits>
#include<vector>
#include<string>
using namespace std;

void longestIncSubsequence(vector<int> arr){
    vector<int> dp(arr.size(),0);
    vector<string> path(arr.size());
    dp[0]=1;
    int max=INT_MIN;
    string opath="";
    path[0]=to_string(arr[0]);
    for(int i=1;i<arr.size();i++){
        for(int j=0;j<=i-1;j++){
            if(arr[j]<arr[i]){
                if(dp[i]<dp[j]){
                    dp[i]=dp[j];
                    path[i]=path[j];
                }
            }
        }
        dp[i]+=1;
        path[i]=path[i] + " " + to_string(arr[i]);
        if(dp[i]>max){
            max=dp[i];
            opath=path[i];
        }
    }
    cout<<max<<endl<<opath;
}

int main() {
    vector<int> arr={10,22,9,33,21,50,41,60,80,1};
    longestIncSubsequence(arr);
}
```
