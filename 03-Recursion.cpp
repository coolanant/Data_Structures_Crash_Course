#include <iostream>
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



int main() {
  toh(3,'A','B','C');
  return 0;
}
