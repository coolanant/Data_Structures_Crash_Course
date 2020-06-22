```c++
#include <iostream>
#include<vector>
#include<string>
using namespace std;

// 1. Tabulated
void rodCut(vector<int> prices){
    // vector<string> path(prices.size());
    vector<int> dp(prices.size());
    dp[0]=0;
    dp[1]=prices[1];
    // path[1]="1";
    //for 6 -> check (1,5),(2,4),(3,3) also
    for(int i=2;i<prices.size();i++){
        // path[i]=to_string(i);
        dp[i]=prices[i];
        int left=1;
        int right=i-1;
        while(left<=right){
            if(dp[left]+dp[right]>dp[i]){
                // path[i]=path[left]+path[right];
                dp[i]=dp[left]+dp[right];
            }
            left++;
            right--;
        }
    }
    cout<<dp[dp.size()-1]<<endl;
}

int main() {
    vector<int> prices={0,3,5,6,15,10,25,12,24}; //Prices as per length 0,1,2....
    //ans for 8
    rodCut(prices);

}

```
