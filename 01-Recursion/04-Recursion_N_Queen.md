### 04.3-Recursion (Queen Problem)

```c++
#include <iostream>
#include<vector>
#include<string>

using namespace std;
static int counter;

bool isQueenSafe(vector<vector<int> > chess, int row, int col){
    vector<vector<int> > dir={
        {1,0},{-1,0},{0,1},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}//8 dirs
    };
    
    for(int i=0;i<dir.size();i++){
        for(int dist=1;true;dist++){
            int eqcol=col + dist*dir[i][1];
            int eqrow=row + dist*dir[i][0];
            
            if(eqcol<0 || eqrow<0 || eqcol>=chess.size() || eqrow>=chess.size()){
                break;
            }
            
            if(chess[eqrow][eqcol]==1){
                return false;
            }
        }
    }
    return true;
}

bool isKnightSafe(vector<vector<int> > chess, int row, int col){
    vector<vector<int> > dir={
        {1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}//8 dirs
    };
    
    for(int i=0;i<dir.size();i++){
        int eqcol=col + dir[i][1];
        int eqrow=row + dir[i][0];
        
        if(eqcol<0 || eqrow<0 || eqcol>=chess.size() || eqrow>=chess.size()){
            continue;
        }
        
        if(chess[eqrow][eqcol]==1){
            return false;
        }
    }
    return true;
}

void nqueen(vector<vector<int> > chess,int tpq,string ans,int index){
    if(tpq==chess.size()){
        counter++;
        cout<<counter<<". "<<ans<<endl;
        return;
    }
    for(int i=index+1;i<chess.size()*chess.size();i++){
        int row=i/chess.size();
        int col=i%chess.size();
        if(chess[row][col]==0){
            if(isKnightSafe(chess,row,col)==true){
                chess[row][col]=1;
                nqueen(chess,tpq+1,ans+to_string(tpq+1)+" "+to_string(i)+" ",i);
                chess[row][col]=0;
            }
        }
    }
}



int main() {
    vector<vector<int> > chess(3,vector<int>(3));
    nqueen(chess,0,"",-1);
}
```
