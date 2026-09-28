class Solution { 
public: 
    int maxDepth(string s) { 
        stack<char> st;
        int len = 0; 
        
        for(char c : s){ 
           
            if(c == '(') {
                st.push(c); 
               
                len = max(len, (int)st.size());
            } 
            if(c == ')') {
                st.pop();
            } 
        }
        return len; 
    } 
};
