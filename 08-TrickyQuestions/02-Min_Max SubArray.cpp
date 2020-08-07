#include <bits/stdc++.h>
using namespace std;
int main(){
    
    // 1. Given an array nums and a target value k, find the MAX length of a subarray that sums to k
    vector<int> arr={ 10, 5, 2, 7, 1, 9 };
    int n=arr.size();
    int k=15;

    int ans=INT_MIN;
    map<int,int> m;
    vector<int> prefixSum;
    int sum=0;
    
    prefixSum.push_back(0);
    for(int i=0;i<n;i++){
        sum+=arr[i];
        prefixSum.push_back(sum);
    }
    
    // prefixSum = 0, 10, 15, 17, 24, 25, 34
    for(int i=0;i<prefixSum.size();i++){
        m[prefixSum[i]]=i;
    }
    // 0 -> 0, 10 -> 1, 15 -> 2, 17-> 3, 24 -> 4, 25 -> 5, 34 -> 6
    for(int i=0;i<prefixSum.size();i++){
        if(m.find(k+prefixSum[i])!=m.end()){ // 15 + {0, 10, 15, 17, 24, 25, 34}
            ans=max(ans,m[k+prefixSum[i]]-i); // m[15+0]-0 = 2, m[15+10]-1 = 4
        }
    }
    
    // for(int i=0;i<prefixSum.size();i++){
    //     for(int j=0;j<i;j++){
    //         if(prefixSum[i]-prefixSum[j]==k){
    //             ans=max(ans,i-j);
    //         }
    //     }
    // }
    cout<<ans;
    
    // 2. Given an array of n positive integers and a positive integer s, find the MIN length of a contiguous subarray of which the sum ≥ s.
    // https://leetcode.com/problems/minimum-size-subarray-sum/
    vector<int> nums={2,3,1,2,4,3};
    int s=7;
    
    sum=0;
    ans=INT_MAX;
    arr={0};//prefixSum
    int j=0;
    for(int i=0;i<nums.size();i++){
        arr.push_back(nums[i]+arr[j]);
        j++;
    }
    
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<=i;j++){
            if(arr[i]-arr[j]>=s){
                ans=min(ans,i-j);
            }
        }    
    }
    if(ans==INT_MAX)return 0;
    cout<<endl<< ans;
        
    // 3. optimal
    sum=0;int start=0,end=0;
    ans=INT_MAX;
    while(end<nums.size()){
        // add sum if sum < s
        while (sum < s && end <nums.size()){
            sum += nums[end++];
        } 
        
        // remove from start if sum>=s
        while(sum>=s && start<nums.size()){
            ans=min(ans,end-start);
            sum-=nums[start++];
        }
    }
    if(ans==INT_MAX)return 0;
    cout<<endl<<ans;
    return 0;
}