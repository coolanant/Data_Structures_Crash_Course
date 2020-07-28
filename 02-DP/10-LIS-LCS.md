```c++
#include<bits/stdc++.h> 
using namespace std; 
	
// 1. LIS
int LIS(vector<int> arr){ 
	vector<int> dp(arr.size(),1); 
	
	int ans=1;
	for (int i=0; i<arr.size(); i++ ){ 
		for (int j = 0; j < i; j++ ){
			if ( arr[i]> arr[j] && dp[i] < dp[j] + 1){ 
				dp[i] = dp[j] + 1;
				ans=max(ans,dp[i]);
			}
		}
	} 
	return ans; 
} 

// 2. LDS
int LDS(vector<int> arr){ 
	vector<int> dp(arr.size(),1); 
	
	int ans=1;
	for (int i=0; i<arr.size(); i++ ){ 
		for (int j = 0; j < i; j++ ){
			if (arr[j]> arr[i] && dp[i] < dp[j] + 1){ 
				dp[i] = dp[j] + 1;
				ans=max(ans,dp[i]);
			}
		}
	} 
	return ans; 
} 

// 3. LCS
int LCS(string X,string Y){
    vector<vector<int> > dp(X.length()+1,vector<int>(Y.length()+1));
    for (int i = 0; i <=X.length(); i++){  
        for (int j = 0; j <=Y.length(); j++)  
        {  
        if (i == 0 || j == 0)  
            dp[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            dp[i][j] = dp[i - 1][j - 1] + 1;  
      
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
        }  
    } 
    
    // print
    int i=X.length(),j=Y.length();
    string path;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            path+= X[i-1];
            i--;j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    cout<<path<<endl;
    return dp[X.length()][Y.length()];
}

// 4. Bitonic Sequence - Strictly inc then dec
int bitoniSeq(vector<int> arr){
    
    vector<int> left(arr.size(),1);
	for (int i=0; i<arr.size(); i++ ){ 
		for (int j = 0; j < i; j++ ){
			if ( arr[i]> arr[j] && left[i] < left[j] + 1){ 
				left[i] = left[j] + 1;
			}
		}
	} 

	vector<int> right(arr.size(),1); 
	for (int i=arr.size()-1; i>=0; i-- ){ 
		for (int j = arr.size()-1; j > i; j-- ){
			if (arr[j]< arr[i] && right[i] < right[j] + 1){ 
				right[i] = right[j] + 1;
			}
		}
	} 

	int maxans=INT_MIN;
	for(int i=0;i<arr.size();i++){
        maxans=max(maxans,left[i]+right[i]-1);
    }
    return maxans;
}

// 5. Envelop

// 6. Overlapping Bridges

int main() 
{ 
    // 1. LIS	
	vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
	cout<<"LIS:"<<LIS(arr)<<endl;
	
    // 2. LDS
	cout<<"LDS:"<<LDS(arr)<<endl;
    
    // 3. lCS
    string X = "AGGTAB";  
    string Y = "GXTXAYB";
    cout<<"LCS:"<<LCS(X, Y)<<endl;
    
    // 4. Bitonic Sequence
    vector<int> arr2={1,3,5,7,4,3,5,2,6};
    cout<<"Bitnoic:"<<bitoniSeq(arr2);
    
        
	return 0; 
}

```
