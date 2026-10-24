
#include <cassert>
#include <stack>
#include <string>
bool bal(const std::string& str){
    std::stack<char> st;
    for(char ch : str){
        if(ch == '(' || ch == '[' || ch == '{')st.push(ch);
        else{
            switch (ch) {
                case ')':
                    if(!st.empty() && st.top() == '(')st.pop();
                    else return false;
                    break;
                case']':
                    if(!st.empty() && st.top() == '[')st.pop();
                    else return false;
                    break;
                case '}':
                    if(!st.empty() && st.top() == '{')st.pop();
                    else return false;
                    break;
            }
        }
         
    }
    return st.empty();
}

int main(){
    assert( bal("({[]})"));
   assert( !bal("([)]"));
   assert( !bal("{[}]"));
   assert( bal(""));
}
