
void solve(int row,int n,vector<bool> &diag1,vector<bool> &diag2,
vector<bool> &col, string ans){
    if(row==n){
        cout<<ans+"."<<endl;return;
    }
    //move to each col
    for(int c=0;c<n;c++){
        if(col[c]==false && diag1[row-c+n-1]==false && diag2[row+c]==false){
            //true;
            diag2[row+c]=true;
            diag1[row-c+n-1]=true;
            col[c]=true;
            ///call;
            solve(row+1,n,diag1,diag2,col,
            ans+to_string(row)+"-"+to_string(c)+", ");
            //false;
            diag2[row+c]=false;
            diag1[row-c+n-1]=false;
            col[c]=false;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > chess(n,vector<int>(n));
    
    vector<bool> diag1(2*n-1);
    vector<bool> diag2(2*n-1);
    vector<bool> col(n);
    
    solve(0,n,diag1,diag2,col,"");
}