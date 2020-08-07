//  Input: ")()())"
//  Output: 4
 
 int longestValidParentheses(string s) {
    stack<int> st;
    int curr=0;
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push(curr);
            curr=0;
        }
        else{
            if(st.empty()){
                curr=0;
            }else{
                curr=curr+st.top()+2;
                st.pop();
                ans=max(ans,curr);
            }
        }
    }
    return ans;
}