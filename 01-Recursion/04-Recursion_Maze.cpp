#include <iostream>
#include<vector>
#include<string>
using namespace std;


//-------------------no.
int mazepath(int m, int n){
    if(m==1 || n==1){
        cout<<endl;
        return 1;
    }
    return mazepath(m-1,n)+mazepath(m,n-1);
    //+mazepath(m-1,n-1); (diagonal)
}

//______________________________________________________________________________
static int counter;
static int count;

void mazepath2(int fromx,int fromy,int tox,int toy, string  ans){
    if(fromx==tox && fromy==toy){
        counter++;
        cout<<counter<<":"<<ans<<endl;
        return;
    }
    //(DIAGONAL)
    // if(fromx+1<=tox && fromy+1<=toy){
    //     mazepath2(fromx+1,fromy+1,tox,toy,ans+"D");
    // }
    if(fromx+1<=tox){
         mazepath2(fromx+1,fromy,tox,toy,ans+"H");
    }
    if(fromy+1<=toy){
        mazepath2(fromx,fromy+1,tox,toy,ans+"V"); 
    }
    
}


//____________________queen like moves__________________________________________________________
void mazepathmultistep(int fromx,int fromy,int tox,int toy, string  ans){
    if(fromx==tox && fromy==toy){
        count++;
        cout<<count<<":"<<ans<<endl;
        return;
    }
    for(int i=1;i<=toy-fromy;i++){
        mazepathmultistep(fromx,fromy+i,tox,toy,ans+"H"+to_string(i));
    }
     for(int i=1;i<=tox-fromx;i++){
        mazepathmultistep(fromx+i,fromy,tox,toy,ans+"V"+to_string(i));
    }
     for(int i=1; i<=tox-fromx && i<=toy-fromy;i++){
        mazepathmultistep(fromx+i,fromy+i,tox,toy,ans+"D"+to_string(i));
    }
    
}

//__________________Restricted path 4 dirns____________________________________
void restrictedmaze(int fromx,int fromy, vector<vector<int> > maze,vector<vector<int> > visited, string ans){
    if(fromx==maze.size()-1 && fromy==maze[0].size()-1){
        cout<<ans<<endl;
        return;
    }
    
    if(fromx<0 || fromy<0 || fromx>maze.size()-1 || fromy>maze[0].size()-1 || maze[fromx][fromy]==0){
        return;
    }
    
    if(visited[fromx][fromy]==1 ){
        return;
    }
    
    visited[fromx][fromy]=1;
    //RIGHT
    restrictedmaze(fromx,fromy+1,maze,visited,ans+"R");
    //DOWN
    restrictedmaze(fromx+1,fromy,maze,visited,ans+"D");
    //LEFT
    restrictedmaze(fromx,fromy-1,maze,visited,ans+"L");
    //TOP
    restrictedmaze(fromx-1,fromy,maze,visited,ans+"T");
    
    // visited[fromx][fromy]=0;//remove for 1 path only
}


int main() {
    cout<<mazepath(3,3);
    cout<<endl;
    mazepath2(0,0,2,2,"");
    cout<<endl;
    // mazepathmultistep(0,0,3,3,"");
    
    cout<<endl;
    vector<vector<int> > maze={{1,0,1,1},{1,1,1,1},{1,0,1,1},{1,1,0,1}};
    vector<vector<int> > visited(maze.size(),vector<int>(maze[0].size()));
    
    restrictedmaze(0,0,maze,visited,"");
    cout<<endl;
}
