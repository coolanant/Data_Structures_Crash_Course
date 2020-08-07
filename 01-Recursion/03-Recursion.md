### 03-Recursion (Good Questions)

```c++
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 1. Tower Of Hanoi
void toh(int n, char from, char to,char aux){
    if(n==1){
        cout<<"Disk 1 "<<from<<":"<<to<<endl;
        return;
    }
    toh(n-1,from,aux,to);
    cout<<"Disk "<<n<<" "<<from <<":"<<to<<endl;
    toh(n-1,aux,to,from);
}

// 2. Subsequence/Subset
void subsequence(string in, string out){
    if(in.length()==0){
        cout<<out<<endl;
        return;
    }
    subsequence(in.substr(1),out);
    subsequence(in.substr(1),out+in[0]);
}

void subsequence2(char in[],char out[],int i, int j){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    out[j]=in[i];
    subsequence2(in,out,i+1,j+1);
    subsequence2(in,out,i+1,j);
}

// 3. generate brackets
void generateBrackets(string ans,int n, int i, int closing, int opening){
    if(i==2*n){
        cout<<ans<<endl;
        return;
    }
    if(opening<n){
        generateBrackets(ans+"{",n, i+1, closing, opening+1);
    }
    if(closing<opening){
        generateBrackets(ans+"}",n, i+1, closing+1, opening);
    }
}

// 4. 0/1 KnapSack
// - DP Solution
int knapsack(vector<int> w,vector<int> p,int i, int cap,unordered_map<int,unordered_map<int,int> > &dp){
    if(i==w.size() ||cap==0){
        return 0;
    }
    if(dp[i][w[i]]!=0) return dp[i][w[i]];
    int ans=0;
    int inc=0,exc=0;
    if(cap>=w[i]){
         inc= p[i]+ knapsack(w,p,i+1,cap-w[i],dp);
    }
    exc=knapsack(w,p,i+1,cap,dp);
    return dp[i][w[i]]=ans=max(inc,exc);
}

//5. Phone Keypad
vector<string> keypad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void phoneKeypad(vector<int> in, string out, int i){
    if(i==in.size()){
        cout<<out<<endl;
        return;
    }
    if(in[i]==1||in[i]==0){
        phoneKeypad(in,out,i+1);
    }
    for(int k=0;k<keypad[in[i]].size();k++){
        phoneKeypad(in,out+keypad[in[i]][k],i+1);
    }
}

// 6.Number To Characters 1->A 10->J (1-26)
void numtoChars(string in,string out,int i){
    if(i>=in.length()){
        cout<<out<<endl;return;
    }
    int fdigit=in[i]-'0';
    char ch= fdigit + 'A' - 1;
    numtoChars(in,out+ch,i+1);

    if(i+1!=in.length()){
        int sdigit=in[i+1]-'0';
        int no=fdigit*10+sdigit;
        if(no<=26 && no>=1){
            char ch=no+'A'-1;
            numtoChars(in,out+ch,i+2);
        }
    }
}

int main() {
  // 1. Tower Of Hanoi
  toh(3,'A','B','C');

  // 2. Subsequence/Subset
  string s="abc";
  subsequence(s,"");cout<<endl;

  char s2[]="abc";
  char out[5];
  subsequence2(s2,out,0,0);

  //3. generate brackets
  generateBrackets("",3,0,0,0);

  // 4. 0/1 KnapSack
  vector<int> weights={5,3,2,1};
  vector<int> prices={100,30,20,40};
  int capacity=7;
  unordered_map<int,unordered_map<int,int> > dp;
  cout<<knapsack(weights,prices,0,capacity,dp)<<endl;

  //5. Phone Keypad
  vector<int> in={6,2};
  phoneKeypad(in,"",0);cout<<endl;

  // 6.Number To Characters 1->A 10->J (1-26)
  string s="123";
  numtoChars(s,"",0);

  return 0;
}
```
