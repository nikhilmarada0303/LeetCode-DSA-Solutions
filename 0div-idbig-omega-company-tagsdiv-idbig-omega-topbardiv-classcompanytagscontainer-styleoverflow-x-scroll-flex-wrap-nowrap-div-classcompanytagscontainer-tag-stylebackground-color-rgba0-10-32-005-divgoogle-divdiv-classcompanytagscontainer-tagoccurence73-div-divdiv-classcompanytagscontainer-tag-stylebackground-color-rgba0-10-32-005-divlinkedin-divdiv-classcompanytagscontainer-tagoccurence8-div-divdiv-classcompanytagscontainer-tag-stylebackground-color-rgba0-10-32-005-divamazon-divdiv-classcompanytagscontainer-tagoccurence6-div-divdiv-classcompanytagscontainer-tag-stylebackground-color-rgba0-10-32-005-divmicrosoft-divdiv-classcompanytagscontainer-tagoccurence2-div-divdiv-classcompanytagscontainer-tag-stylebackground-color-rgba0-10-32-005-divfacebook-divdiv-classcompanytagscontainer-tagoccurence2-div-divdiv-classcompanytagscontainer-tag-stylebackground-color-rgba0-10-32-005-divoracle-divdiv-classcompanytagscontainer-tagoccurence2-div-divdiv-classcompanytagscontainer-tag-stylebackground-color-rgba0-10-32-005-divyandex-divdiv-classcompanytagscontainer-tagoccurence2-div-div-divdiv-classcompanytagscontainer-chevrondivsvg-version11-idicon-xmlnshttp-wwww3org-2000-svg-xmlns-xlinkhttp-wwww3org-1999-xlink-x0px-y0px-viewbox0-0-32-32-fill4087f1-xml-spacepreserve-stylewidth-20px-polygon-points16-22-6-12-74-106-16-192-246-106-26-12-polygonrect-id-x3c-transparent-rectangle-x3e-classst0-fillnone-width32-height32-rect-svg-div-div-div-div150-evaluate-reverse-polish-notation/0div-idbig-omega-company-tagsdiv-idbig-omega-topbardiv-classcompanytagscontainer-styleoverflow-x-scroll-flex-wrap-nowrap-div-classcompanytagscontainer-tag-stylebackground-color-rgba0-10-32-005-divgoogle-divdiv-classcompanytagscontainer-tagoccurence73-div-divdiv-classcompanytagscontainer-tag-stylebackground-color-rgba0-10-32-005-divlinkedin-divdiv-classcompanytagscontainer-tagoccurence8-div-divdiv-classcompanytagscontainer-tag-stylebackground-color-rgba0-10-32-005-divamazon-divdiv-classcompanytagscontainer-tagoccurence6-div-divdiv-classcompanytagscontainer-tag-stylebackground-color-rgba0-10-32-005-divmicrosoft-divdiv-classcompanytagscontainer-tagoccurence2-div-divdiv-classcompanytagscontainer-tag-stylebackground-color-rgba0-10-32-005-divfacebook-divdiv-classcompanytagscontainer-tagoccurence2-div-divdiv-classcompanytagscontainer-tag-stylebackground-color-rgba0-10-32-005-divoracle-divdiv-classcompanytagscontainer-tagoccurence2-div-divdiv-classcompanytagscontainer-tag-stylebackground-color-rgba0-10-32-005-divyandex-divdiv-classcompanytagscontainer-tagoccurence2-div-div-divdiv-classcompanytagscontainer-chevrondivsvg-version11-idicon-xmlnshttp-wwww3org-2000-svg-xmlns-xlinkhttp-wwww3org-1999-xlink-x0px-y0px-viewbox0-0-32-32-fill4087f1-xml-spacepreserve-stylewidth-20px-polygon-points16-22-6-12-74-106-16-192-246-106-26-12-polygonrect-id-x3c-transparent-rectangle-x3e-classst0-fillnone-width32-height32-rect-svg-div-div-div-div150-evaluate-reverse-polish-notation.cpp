class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int ans=0;
        
        for(int i=0;i<tokens.size();i++){
            if(isdigit(tokens[i][0]) || (tokens[i].size()>1 && isdigit(tokens[i][1])))
                st.push(stoi(tokens[i]));
            else{
                if(tokens[i]=="+"){
                    int num1=st.top();
                    st.pop();
                    int num2=st.top();
                    st.pop();
                    st.push(num2+num1);
                }
                if(tokens[i]=="-"){
                    int num1=st.top();
                    st.pop();
                    int num2=st.top();
                    st.pop();
                    st.push(num2-num1);
                }
                if(tokens[i]=="/"){
                    int num1=st.top();
                    st.pop();
                    int num2=st.top();
                    st.pop();
                    st.push(num2/num1);
                }
                if(tokens[i]=="*"){
                    int num1=st.top();
                    st.pop();
                    int num2=st.top();
                    st.pop();
                    st.push(num2*num1);
                }
            }
            
        }return st.top();
    }
};