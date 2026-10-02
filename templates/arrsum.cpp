#include <cassert>
#include <string>


using std::string;


template<class T>
T arrsum(T* arr, int size){
    T sum = T();
    for( int i = 0; i < size ; i ++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    int arr1[5] = {1, 2, 3, 4, 5};
    double arr[5] = {1.1, 2.1, 3.1, 4.1, 5.1};
    string arr2[6] = {":", ")", " ", ">", ":", "("};
    
    assert(arrsum<int>(arr1, 5) == 15);
    assert(arrsum<double>(arr, 5) == 15.5);
    assert(arrsum<string>(arr2, 6) == ":) >:(");
}