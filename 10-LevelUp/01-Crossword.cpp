#include<bits/stdc++.h>
using namespace std;

bool wordsFitH(vector<vector<char> > arr,string word,int i,int j){
    // cout<<"H: i,j:"<<i<<","<<j<<endl;
    if(j>0 && arr[i][j-1]!='+'){
        return false;
    }
    for(int x=0;x<word.length();x++){
        // cout<<word[x]<<endl;
        if(j>arr[0].size()) return false;
        if(arr[i][j]!=word[x] && arr[i][j]!='-'){
            return false;
        }
        j++;
    }
    if(j<arr[0].size() && arr[i][j]!='+'){
        return false;
    }
    return true;
}

bool wordsFitV(vector<vector<char> > arr,string word,int i,int j){
    // cout<<"V: i,j:"<<i<<","<<j<<endl;
    if(i>0 && arr[i-1][j]!='+'){
        return false;
    }
    for(int x=0;x<word.length();x++){
        // cout<<word[x]<<endl;
        if(i>arr.size()) return false;
        if(arr[i][j]!=word[x] && arr[i][j]!='-'){
            return false;
        }
        i++;
    }
    if(i<arr.size() && arr[i][j]!='+'){
        return false;
    }
    return true;
}

bool solve(vector<vector<char> > &arr,vector<string> words,int idx, 
int i, int j){
    if(idx==words.size()||i==10){
        //print ans
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cout<<arr[i][j];
            }
            cout<<endl;
        }
        return true;
    }
    else if(arr[i][j]=='+'){
        return solve(arr,words,idx,i,j+1);
    }
    else if(j==10){
        return solve(arr,words,idx,i+1,0);
    }
    else{
        if(wordsFitH(arr,words[idx],i,j)){
            //set H
            for(int x=0;x<words[idx].length();x++){
                arr[i][x+j]=words[idx][x];
            }
            
            // debug
            // cout<<i<<","<<j<<endl;
            // for(int x=0;x<10;x++){
            //     for(int y=0;y<10;y++){
            //         cout<<arr[x][y]<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
            
            //call
            bool call=solve(arr,words,idx+1,0,0);
            if(call) return true;
            
            //backtrack
            for(int x=0;x<words[idx].length();x++){
                arr[i][x+j]='-';
            }
        }else if(wordsFitV(arr,words[idx],i,j)){
            //set V
            for(int x=0;x<words[idx].length();x++){
                arr[i+x][j]=words[idx][x];
            }
            
            //debug
            // cout<<i<<","<<j<<endl;
            // for(int x=0;x<10;x++){
            //     for(int y=0;y<10;y++){
            //         cout<<arr[x][y]<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
            
            //call
            bool call=solve(arr,words,idx+1,0,0);
            if(call) return true;
            
            // backtrack
            for(int x=0;x<words[idx].length();x++){
                arr[i+x][j]=words[idx][x];
            }
        }
        else{
            return solve(arr,words,idx,i,j+1);
        }
        
    }
    return false;
}

int main(){
    vector<vector<char> > arr(10,vector<char>(10));
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>arr[i][j];
        }
    }
    
    int n;cin>>n;vector<string> words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    // cout<<wordsFitV(arr,"LONDON",0,1);
    solve(arr,words,0,0,0);
}