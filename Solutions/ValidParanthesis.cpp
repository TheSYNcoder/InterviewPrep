class Solution {
public:
    bool isValid(string s) {
        int l = s.size();
        if(l == 0) return true;
        
        stack<char> st;
        
        st.push(s[0]);
        
        bool possible = true;
        
        for(int i = 1; i < l; i++){
            char currChar = s[i];
            
            if(currChar == '(' || currChar == '[' || currChar == '{')
                st.push(currChar);
            
            else{
                if(currChar == ')'){
                    if(st.empty()) {possible = false; break;}
                    
                    else if(st.top() != '(') {
                        possible = false;
                        break;
                    }
                    
                    else st.pop();
                }
                else if(currChar == ']'){ 
                    if(st.empty()) {possible = false; break;}
                    
                    else if(st.top() != '[') {
                        possible = false;
                        break;
                    }
                    else st.pop();
                }
                
                else{
                    if(st.empty()) {possible = false; break;}
                    else if(st.top() != '{') {
                        possible = false;
                        break;
                    }
                    else st.pop();
                }
            }
        }
        
        
        if(st.empty()) return possible;
        else return false;
    }
};
