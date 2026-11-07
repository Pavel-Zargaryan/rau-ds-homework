// ===================================================N1
#include <cassert>
#include <forward_list>

auto middle( std::forward_list<int>& list){
    auto it  = list.begin();
    auto fit = list.begin();
    while(fit != list.end()){
        fit++;
        if( fit == list.end() ) return it;
        fit ++;
        it++;

       
    }
    return it;
}

int main(){
    std::forward_list<int> list = {1 , 2 , 3 , 4 , 5 , 6};
    std::forward_list<int> list1 = {1 , 2 , 3 , 4 , 5};
    assert(*middle(list) == 4);
    assert(*middle(list1) == 3);
    
}