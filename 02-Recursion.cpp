#include <iostream>
#include <vector>
using namespace std;

// 1. Is Array Sorted
bool isArraySorted(vector<int> arr,int n){
    if(n<=1){
        return true;
    }
    if(arr[0]<arr[1]){
        arr.erase(arr.begin());
        if(isArraySorted(arr,n-1)){
            return true;
        }
    }
    return false;
}
bool isArraySorted2(int arr[],int n){
    if(n<=1){
        return true;
    }
    if(arr[0]<arr[1] &&isArraySorted2(arr+1,n-1)){
            return true;
    }
    return false;
}

// 2. 2048 Problem
char numbers[][50]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void problem1(int n){
    if(n==0){
        return;
    }
    int x=n%10;
    problem1(n/10);
    cout<<numbers[x]<<" ";
}

// 3. Linear Search 
int search(vector<int> arr, int key, int start, int end){
    if(start==end){
        return -1;
    }
    if(arr[start]==key){
        return start;
    }
    return search(arr, key, start+1, end);
}

// 4. Bubble Sort
void sort(int *arr, int n){
    if(n<=1){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    sort(arr,n-1);
}

int main() {
    // 1. Is Array Sorted
    vector<int> arr={10,2,5,7,9,1};
    cout<<isArraySorted(arr,arr.size())<<endl;
    
    // 2. 2048 Problem
    int x=2048;
    problem1(x); cout<<endl;
    
    // 3. Linear Search 
    cout<<search(arr,19,0,arr.size())<<endl;
    
    // 4. Bubble Sort - last wala sorted
    int arr2[]={10,2,5,7,9,1};
    // cout<<sizeof(arr2)/sizeof(int);
    sort(arr2,6);
    cout<<isArraySorted2(arr2,6);

}
