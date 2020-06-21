### 04-Recursion (Borad Game)

```c++
#include <iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

//---------------------------------------
void boardgame(int src,int dest, string ans){
    if(src==dest){
        cout<<ans<<endl;
        return;
    }
    if(src>dest){
        return;
    }
    for(int dice=1;dice<=6;dice++){
        int inter=src+dice;
        boardgame(inter,dest,ans+to_string(dice));
    }
}

//---------------------------------------
void boardgame16(int src,int dest, string ans){
    if(src==dest){
        cout<<ans<<endl;
        return;
    }
    if(src>dest){
        return;
    }
    if(src==0){
        boardgame16(1,dest,ans+"1");
        boardgame16(1,dest,ans+"6");
    }
    else{
        for(int dice=1;dice<=6;dice++){
            int inter=src+dice;
            boardgame16(inter,dest,ans+to_string(dice));
        }
    }
}



//---------------------------------------
void boardgame16withladder(int src,int dest,vector<int> ladder, string ans){
    if(src==dest){
        cout<<ans<<endl;
        return;
    }
    if(src>dest){
        return;
    }
    if(src==0){
        boardgame16withladder(1,dest,ladder,ans+"1");
        boardgame16withladder(1,dest,ladder,ans+"6");
    }
    if(ladder[src]!=0){
         boardgame16withladder(ladder[src],dest,ladder,ans+"["+to_string(src)+"->"+to_string(ladder[src])+"]");
    }
    else{
        for(int dice=1;dice<=6;dice++){
            int inter=src+dice;
            boardgame16withladder(inter,dest,ladder,ans+to_string(dice));
        }
    }
}


//---------------------------------------
int main() {
    vector<int> ladder(16);
ladder[2]=13;
ladder[5]=7;
    boardgame(7,10,"");
    cout<<endl<<"New GAME!!!!!!!"<<endl;
    boardgame16(0,3,"");
    cout<<endl<<"New GAME!!!!!!!"<<endl;
    boardgame16withladder(1,7,ladder,"");
}

```
