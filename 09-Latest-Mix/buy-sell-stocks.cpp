#include<bits/stdc++.h>
using namespace std;

// 1.
int oneTransaction(vector<int> arr){
    // int minl=arr[0];
    // int ans=0;
    // for(int i=1;i<n;i++){
    //     ans=max(ans,arr[i]-minl);
    //     minl=min(minl,arr[i]);
    // }
    // return ans;
    
    int maxl=arr[arr.size()-1];
    int ans2=0;
    for(int i=n-2;i>=0;i--){
        ans2=max(ans2,maxl-arr[i]);
        maxl=max(maxl,arr[i]);
    }
    return ans2;
}

// 2. 
// you must sell before buying again
// atmost 2 transactions
int twoTransaction(vector<int> prices){
    if(prices.size()==0||prices.size()==1) return 0;
    
    vector<int> left(prices.size()); int minl=prices[0];
    for(int i=1;i<prices.size();i++){
        left[i]=max(left[i-1],prices[i]-minl);
        minl=min(minl,prices[i]);
    }
    
    int ans=0;int maxr=prices[prices.size()-1]; int right=0;
    for(int i=prices.size()-2;i>=0;i--){
        right=max(right,maxr-prices[i]);
        maxr=max(maxr,prices[i]);
        ans=max(ans,left[i]+right);
    }
    return ans;
}

// 3. 
// Add all the +ve strokes(slopes)
int multipleTransaction(vector<int> arr){
    if(arr.size()==0||arr.size()==1) return 0;

    int cs=0;
    int ans=0;
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]<arr[i+1]){
            cs+=(arr[i+1]-arr[i]);
        }else{
            ans+=cs;
            cs=0;
        }
    }
    if(cs!=0) ans+=cs;
    return ans;
}

// 4. Multiple transaction - with fee 
int multipleTransactoinWithFee(vector<int>& prices,int fee) {
    vector<int> dpBuy(n, 0);
    vector<int> dpSell(n, 0);

    dpBuy[0] = -prices[0];
    dpSell[0] = 0;
    
    // do nothing, buy, sell
    for(int i=1; i<prices.size(); i++){
        dpBuy[i] = max(dpBuy[i-1], dpSell[i-1]-prices[i]);
        dpSell[i] = max(dpSell[i-1], dpBuy[i-1]+prices[i]-fee);
    }
    return dpSell[prices.size()-1];
}

// 5. Infinite Transacation - with 1 day Cooldown
int multipleTransactionWithCoolDown(vector<int> arr,int fee){
    int buy=-arr[0];
    int sell=0;
    int cooldown=0;
    
    for(int i=1;i<arr.size();i++){
        int nbuy=max(buy, cooldown-arr[i]);
        int nsell=max(sell, buy + arr[i]);
        int ncooldown=max(cooldown, sell);
        
        buy=nbuy;
        sell=nsell;
        cooldown=ncooldown;
    }
    
    return sell;
}

// 6. multipleTransaction - K Transactions
int maxProfitC(vector<int>& p, int res = 0) {
    for (int i = 1; i < p.size(); ++i) 
        res += max(0, p[i] - p[i - 1]);
    return res;
}
int maxProfit(int k, vector<int>& prices) {
    if (k >= prices.size() / 2) return maxProfitC(prices);
    vector<int> buy(k + 1, INT_MIN);
    vector<int> sell(k + 1, 0);
    for (auto p : prices)
        for (auto i = 1; i <= k; ++i) {
        buy[i] = max(buy[i], sell[i - 1] - p);
        sell[i] = max(sell[i], buy[i] + p);  
    }
    return sell[k];
}

int main(){
    vector<int> arr={3,3,5,0,0,3,1,4};
    
    cout<<oneTransaction(arr);

    cout<<twoTransaction(arr);

    cout<<multipleTransaction(arr);

    cout<<multipleTransactoinWithFee(arr,3);
}