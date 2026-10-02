#include <cassert>
#include <string>

using std::string;


template<class T>
void sswap(T& var, T& var1){
    T tmp = var;
    var = var1;
    var1 = tmp;  
}

int main(){
    int a = 3;
    int b = 5;
    
    sswap<int>(a, b);
    assert(a == 5 && b == 3);

    
    double da = 3.5;
    double db = 5.5;
    
    sswap<double>(da, db);
    assert(da == 5.5 && db == 3.5);

    
    std::string sa = "Hehe";
    std::string sb = "Not Hehe";
    
    sswap<string>(sa, sb);
    assert(sa == "Not Hehe" && sb == "Hehe");
    
    
}