// ===============================================N3
#include <forward_list>
#include <cassert>
void rep(std::forward_list<int>& list){
    auto it = list.begin();
    auto it1 = ++list.begin();
    while(it1 != list.end()){
        if(*it == *it1){
          list.erase_after(it);
          it1 = it;
          ++it1;
        }
        else{
            it++;
            it1++;
        }
    }
}

int main(){
    std::forward_list<int> list = {1,1,1,3,3,5,5,6,6};
    rep(list);
    auto it = list.begin();
    assert(*it++ == 1 );
    assert(*it++ == 3 );
    assert(*it++ == 5 );
    assert(*it++ == 6 );
    
}