#include <iostream>
using namespace std;

//count a+b+c subsequence (regular expression)
int main(){
    string s = "abcabc";

    int a = 0;
    int ab = 0;
    int abc = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'a'){
            a = 2 * a + 1;
        }
        else if (s[i] == 'b'){
            ab = 2 * ab + a;
        }
        else if (s[i] == 'c'){
            abc = abc + abc + ab;
        }
    }
    cout << abc;
}

// Subsequence (2^n -> 2^6=64)