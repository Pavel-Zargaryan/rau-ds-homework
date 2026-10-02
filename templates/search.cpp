#include <cassert>
#include <string>
#include <vector>


using std::string;


template<class T>
int  search(std::vector<T> arr, const T& Target){
    for(int i = 0; i < arr.size(); i++){
        if( Target == arr[i]) return i;
    }
    return -1;
}

int main(){

    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<double> arr = {1.1, 2.1, 3.1, 4.1, 5.1};
    std::vector<string> arr2 = {":", ")", " ", ">", ":", "("};



    assert(search<int>(arr1, 5) == 4);
    assert(search<double>(arr, 5.1) == 4);
    assert(search<string>(arr2, ":") == 0);
    assert(search<int>(arr1, 6) == -1);
    assert(search<double>(arr, 5) == -1);
    assert(search<string>(arr2, "67") == -1);
}
