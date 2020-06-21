### 05-Recursion (Sudoku)

```c++
#include <iostream>
#include<cmath>
using namespace std;

bool canPlace(int mat[][9],int i,int j, int n, int number){
    //row & col
    for(int x=0;x<n;x++){
        if(mat[i][x]==number || mat[x][j]==number){
            return false;
        }
    }
    //check small box
    int rn=sqrt(number);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;
    
    for(int x=sx;x<sx+rn;x++){
        for(int y=sy;y<sy+rn;y++){
            if(mat[x][y]==number){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][9],int i,int j,int n){
    if(i==n){
        //print solved mat
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //Move to next row
    if(j==n){
        return solveSudoku(mat,i+1,0,n);
    }
    //Skip pre filled cells
    if(mat[i][j]!=0){
        return solveSudoku(mat,i,j+1,n);
    }
    //Fill
    for(int number=1;number<=n;number++){
        if(canPlace(mat,i,j,n,number)){
            mat[i][j]=number;
            bool couldWeSolve=solveSudoku(mat,i,j+1,n);
            if(couldWeSolve==true){
                return true;
            }
        }
    }
    //BackTrack
    mat[i][j]=0;
    return false;
}

int main() {
    int mat[9][9]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    
    solveSudoku(mat,0,0,9);
}

```
