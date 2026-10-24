
#include <cassert>
#include <queue>
#include <string>
#include <vector>
std::vector<std::string>* genb(int num){
    std::vector<std::string>* res = new std::vector<std::string>;
    std::queue<std::string> nums;
    nums.push("1");
    while(res->size() < num){
        res->push_back(nums.front());
        nums.push(nums.front() + "0");
        nums.push(nums.front() + "1");
        nums.pop();
    }
    return res;
}

int main(){
    std::vector<std::string>* res = genb(5);
    std::vector<std::string>* res1 = genb(0);
    std::vector<std::string> restest =  {"1", "10", "11", "100", "101"};
    assert(*res == restest);
    assert( *res1 == std::vector<std::string>());
    delete res;
    delete res1;
}
