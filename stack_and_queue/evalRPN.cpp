
#include <cassert>
#include <stack>
#include <string>
#include <vector>
int eval(const std::vector<std::string> exp){
    std::stack<int> st;
    for( std::string s : exp){
        if(s != "+" && s != "-" && s!= "/" && s != "*"){
            st.push(std::stoi(s));
        }
        else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (s[0]) {
                case '-':
                    st.push(op1 - op2);
                    break;
                case '+':
                    st.push(op1 + op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
            }
        }
    }
    return st.top();
}

int main(){
    std::vector<std::string> expr = {"2", "1", "+", "3", "*"};
    assert(eval(expr) == 9);
}