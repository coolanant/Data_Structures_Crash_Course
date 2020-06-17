#include <iostream>
#include <vector>
#include <string>
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

int searchLast(vector<int> arr, int key, int start, int end, int ans){
    if(start==end){
        return ans;
    }
    if(arr[start]==key){
        ans=start;
    }
    return searchLast(arr, key, start+1, end, ans);
}

vector<int> searchAll(vector<int> arr, int key, int start, int end, vector<int> ans){
    if(start==end){
        return ans;
    }
    if(arr[start]==key){
        ans.push_back(start);
    }
    return searchAll(arr, key, start+1, end, ans);
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

// 5. String to Integer
int string2int(string s,int i){
    if(i==-1){
        return 0;
    }
    int digit=s[i]-'0';
    int smallans=string2int(s,i-1);
    return smallans*10+digit;
}

// 6. Binary Search
int binarySearch(vector<int> arr, int key, int start, int end){
    if(end>=start){
        int mid = start + (end - start) / 2;
        if(arr[mid]==key){
            return mid;
        }
        else{
        if(arr[mid]>key){
            return binarySearch(arr,key,start,mid-1);
        }
        else{
        return binarySearch(arr,key,mid+1,end);
        }
        }
    }
    else{
        return -1;
    }
}

// 7. Replace pi -> 3.14  (xpiskndjnnc -> x3.14skndjnnc)
void replacePi(char s[],int i){
    if(s[i]=='\0'){
        cout<<s<<endl;
        return;
    }
    else{
        if(s[i]=='p' && s[i+1]=='i'){
            //shift and replace
            int j=i+2;
            while(s[j]!='\0'){
                j++;
            }
            while(j>=i+2){
                s[j+2]=s[j];
                j--;
            }
            s[i]='3';
            s[i+1]='.';
            s[i+2]='1';
            s[i+3]='4';
            return replacePi(s,i+4);
        }
        return replacePi(s,i+1);
    }
    
}

int main() {
    // 1. Is Array Sorted
    vector<int> arr={1,2,5,7,9,1};
    cout<<isArraySorted(arr,arr.size())<<endl;
    
    // 2. 2048 Problem
    int x=2048;
    problem1(x); cout<<endl;
    
    // 3. Linear Search 
    cout<<"Search:"<<search(arr,1,0,arr.size())<<endl;
    cout<<"Search Last:"<<searchLast(arr,1,0,arr.size(),-1)<<endl;
    vector<int> ans={};
    cout<<"Search All:";
    vector<int> a=searchAll(arr,1,0,arr.size(),ans);
    for(auto it:a){
        cout<<it<<",";
    }
    cout<<endl;
    
    // 4. Bubble Sort - last wala sorted
    int arr2[]={10,2,5,7,9,1};
    // cout<<sizeof(arr2)/sizeof(int);
    sort(arr2,6);
    cout<<"Sorted?:"<<isArraySorted2(arr2,6)<<endl;
    
    // 5. String to Integer
    string s="12340";
    cout<<string2int(s,s.length()-1)<<endl;
    
    // 6. Binary Search
    vector<int> sortedArray={1,4,24,90,100};
    cout<<"Binary Search:"<<binarySearch(sortedArray,24,0,sortedArray.size())<<endl;
    
    // 7. Replace pi -> 3.14  (xpiskndjnnc -> x3.14skndjnnc)
    char ss[1000]="xpiskndjnncpim";
    replacePi(ss,0);
}
