#include "iostream"
#include "string"

using std::cout;
using std::endl;


template<class T>
void printElement(const T& val){
  cout << val << endl ;
}

int main(){
    printElement<int>(6);
    printElement<double>(6.5);
    printElement<std::string>("Hello");
    
}