// ========================================================N1
#include <forward_list>
#include <iostream>
#include <ostream>
void  cf(int n){
     std::forward_list<int> list; 
     for(int i = 1 ; i <= n; i++){
         list.push_front(i);
     }
     for( int i : list){
         std::cout << i << ' ';
     }
     std::cout << std::endl;
 }

int main(){
    cf(6);

}