
#include <cassert>
#include <cstring>
#include <stack>
#include <string>
void rev(std::string& str){
    std::stack<char> st;
    for(char c : str){
        st.push(c);
    }
    for(char c : str){
        c = st.top();
        st.pop();
    }
}
int main(){
    std::string s = "Hello";
    std::string s1 = "olleH";
    rev(s);
    assert(std::strcmp(s.c_str(),s1.c_str()));
}