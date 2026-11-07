// =============================================================N2
#include <cassert>
#include <forward_list>
void insert(std::forward_list<int>& ls, int in, int val){
    auto it = ls.begin();
    for(int i = 0; i < in; i++){
        it++;
    }
    ls.insert_after(it, val);
}

int main(){
    std::forward_list<int> fl = {1, 2, 3, 4};
    insert(fl, 1, 99);
    auto it = fl.begin();
    it++;
    it++;
    assert(*it == 99);
}