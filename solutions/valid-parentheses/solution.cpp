class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for(int i=0; i<str.size(); i++) {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[')
                st.push(str[i]);

            else if(str[i] == ')' && !st.empty() && st.top() == '(')
                st.pop();

            else if(str[i] == '}' && !st.empty() && st.top() == '{')
                st.pop();

            else if(str[i] == ']' && !st.empty() && st.top() == '[')
                st.pop();

            else
                return false;
        }

        return st.empty();
    }
};