// OPTIMAL BST - MINIMIZE COST
#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> freq, int i, int j){
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int optCost(vector<int> freq, int i, int j, vector<vector<int>> &dp){
    // if (i>j) return 0;
    if (j == i)
        return freq[i];

    if (dp[i][j] != 0)
        return dp[i][j];

    int fsum = sum(freq, i, j);
    int minCost = INT_MAX;
    for (int root = i; root <= j; root++)
    {
        int lcost = root - 1 >= i ? optCost(freq, i, root - 1, dp) : 0;
        int rcost = root + 1 <= j ? optCost(freq, root + 1, j, dp) : 0;
        int cost = lcost + rcost + fsum;

        minCost = min(minCost, cost);
    }
    return dp[i][j] = minCost;
}

int main(){
    vector<int> keys = {10, 12, 20}; //sorted (with freq)
    vector<int> freq = {34, 8, 50};
    vector<vector<int>> dp(keys.size(), vector<int>(keys.size(), 0));
    cout << optCost(freq, 0, freq.size() - 1, dp);
    return 0;
}
