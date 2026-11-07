// =========================================================N2
#include <cassert>
#include <forward_list>
bool cycle(std::forward_list<int>& list){
    auto it = list.begin();
    auto fit = list.begin();
    while(fit != list.end()){
        fit++;
        if (fit == list.end()) return false;
        fit++;
        it++;
        if(it == fit) return true;
    }
    return false;
}

int main(){
    std::forward_list<int> list = {1,2,3,4,5};
    assert(!cycle(list));
}