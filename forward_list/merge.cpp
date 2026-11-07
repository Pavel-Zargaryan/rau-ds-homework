// ===============================================N4


#include <cassert>
#include <forward_list>
void merge(std::forward_list<int>& ls1, std::forward_list<int>& ls2){
    auto it1 = ls1.before_begin();
    auto it11 = ls1.begin();
    auto it2 = ls2.begin();
    while(it2 != ls2.end()){
        if(it11 == ls1.end()){
            ls1.insert_after(it1,*it2);
            it2++;
        }
        else if(*it2 < *it11){
            ls1.insert_after(it1, *it2);
            it2++;
            it1++;
            it11 = it1;
            it11++;
           
        }
        else{
            it11++;
            it1++;
        }
    }
    ls2.clear();
}

int main(){
    std::forward_list<int> fl1 = {1, 3, 5};
    std::forward_list<int> fl2 = {2, 4, 6};
    merge(fl1, fl2);
    assert(fl2.empty());
    auto it = fl1.begin();
    assert(*it++ == 1 );
    assert(*it++ == 2 );
    assert(*it++ == 3 );
    assert(*it++ == 4);
    assert(*it++ == 5 );
    assert(*it == 6);
    // fl1 содержит: {1, 2, 3, 4, 5, 6}
}