#include <iostream>
using namespace std;

// 1. Factorial
int factorial(int n){
    if(n==1){
        return 1;
    }
    return n*factorial(n-1);
}

// 2. Counting
void counting(int n){
    if(n==0){
        return;
    }
    counting(n-1);
    cout<<n;
}

// 3. Counting Rev
void countingRev(int n){
    if(n==0){
        return;
    }
    cout<<n;
    countingRev(n-1);
}

//4. Fibonacci
int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

//5. Power
int power(int x,int n){
    if(n==0){
        return 1;
    }
    return x*power(x,n-1);
}
    
//6. Fast Power
int fastPower(int x,int n){
    if(n==0){
        return 1;
    }
    int b=fastPower(x,n/2);
    if(n%2==0){
        return b*b;
    }
    else{
        return x*b*b;
    }
}

//7. Multiply
int multiply(int a, int b){
    if(a<b){
        multiply(b,a);
    }
    if(b==1){
        return a;
    }
    return a+multiply(a,b-1);
}

//8. Multiply2
int multiply2(int a,int b){
    if(a>0 && b<0){
        return multiply2(b,a);
    }
    else if(a<0 && b<0){
        return multiply2((-1*a),(-1*b));
    }
    else if(b==1){
        return a;
    }
    else{
        return a+multiply2(a,b-1);
    }
}

int main() {
    //1. Factorial
    int x=5;
    cout<<factorial(x)<<endl;
    
    //2. Counting
    counting(x);cout<<endl;
    
    //3. Counting Rev
    countingRev(x); cout<<endl;
    
    //4. Fibonacci
    cout<<fibonacci(x)<<endl;
    
    //5. Power
    cout<<power(2,3)<<endl;
    
    //6. Fast Power
    cout<<fastPower(2,3)<<endl;
    
    //7. Multiply
    cout<<multiply(4,5)<<endl;
    
    //8. Multiply2
    cout<<multiply2(-4,5)<<endl;
}
