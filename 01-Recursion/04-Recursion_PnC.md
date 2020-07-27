### 04.4-Recursion (PnC)

```c++
#include <iostream>
#include<vector>
#include<string>
using namespace std;

// 1. Boxes
void permuteboxes(vector<int> arr,int tq, int queen_placed_so_far, string ans){
    if(queen_placed_so_far==tq){
        cout<<ans<<endl;
        return;
    }
    for(int box=0;box<arr.size();box++){
        if(arr[box]!=1){
            arr[box]=1;
            permuteboxes(arr,tq, queen_placed_so_far+1,ans+"Q"+to_string(queen_placed_so_far+1)+" " +to_string(box)+" ");
            arr[box]=0;
        }
        
    }
}

void combinationboxes(vector<int> arr,int tq, int queen_placed_so_far, string ans,int last_placed_queen_index){
    if(queen_placed_so_far==tq){
        cout<<ans<<endl;
        return;
    }
    for(int box=last_placed_queen_index+1;box<arr.size();box++){
        if(arr[box]!=1){
            arr[box]=1;
            combinationboxes(arr,tq, queen_placed_so_far+1,ans+"Q"+to_string(queen_placed_so_far+1)+" " +to_string(box)+" ",box);
            arr[box]=0;
        }
        
    }
}


// 2. Coin Change / Payment Installment
void coinchangep(vector<int> arr, int total, int paid, string ans ){
    if(paid==total){
        cout<<ans<<endl;return;
    }
    for(int inst=0;inst<arr.size();inst++){
        if(total>=paid+arr[inst]){
             coinchangep(arr,total,paid+arr[inst],ans+to_string(arr[inst]));
        }
    }
}

void coinchangec(vector<int> arr, int total, int paid, string ans,int lpi){
    if(paid==total){
        cout<<ans<<endl;return;
    }
    for(int inst=lpi;inst<arr.size();inst++){
        if(total>=paid+arr[inst]){
         coinchangec(arr,total,paid+arr[inst],ans+to_string(arr[inst]),inst);   
        }
    }
}

// 3. Permuation of String
void permutation(string in,string ans){
    if(in.length()==0){
        cout<<ans<<endl; return;
    }
    for(int i=0;i<in.size();i++){
        char ch=in[i];
        string left=in.substr(0,i);
        string right=in.substr(i+1);
        permutation(left+right,ans+ch);
    }
}

int main() {
    // 1. Boxes
    vector<int> arr1(4);
    cout<<"P"<<endl;
    permuteboxes(arr1,2,0,"");
    cout<<"C"<<endl;
    combinationboxes(arr,2,0,"",-1);
    cout<<endl;
    
    // 2. Coin Change / Payment Installation
    vector<int> arr={2,3,5,6};
    coinchangep(arr,10,0,"");
    cout<<"C"<<endl;
    coinchangec(arr,10,0,"",0);
    
    // 3. Permuation of String
    cout<<endl<<"Permuation:"<<endl;
    string in="abc";
    permutation(in,""); 
}
```
