// ========================================================N3
#include <forward_list>
#include <cassert>
int rep(std::forward_list<int>& list, int val){
    int am = 0;
    auto it = list.begin();
    auto it1 = ++list.begin();
    while(it1 != list.end()){
        if(val ==  *it1){
          list.erase_after(it);
          am++;
          it1 = it;
          ++it1;
        }
        else{
            it++;
            it1++;
        }
    }
    return am;
}

int main(){
    std::forward_list<int> list = {1, 2, 3, 2, 4, 2};
    assert(rep(list,2) == 3);
    auto it = list.begin();
    assert(*it++ == 1 );
    assert(*it++ == 3 );
    assert(*it == 4 );
    
}