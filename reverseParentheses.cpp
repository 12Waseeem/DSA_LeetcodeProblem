class Solution {
public:
    void reverse(string& s, int i, int e){
        while(i<=e){
            swap(s[i], s[e]);
            i++, e--;
        }
    }
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> st;
        for(int i=0; i<n; i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                reverse(s, st.top()+1, i-1);
                st.pop();
            }
        }
        string ans;
        for(auto ch:s){
            if(ch=='(' ||  ch==')') continue;
            ans.push_back(ch);
        }
        return ans;
    }
};
